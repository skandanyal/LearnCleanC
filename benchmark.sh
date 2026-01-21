#!/bin/bash
set -e  # Exit on any error

# =============================
# Configuration
# =============================
SRC_DIR="src/saxpy"        # Directory containing main.c and plain_kernel.c
ITERATIONS=5               # Number of optimized runs
BIN="./bench_bin"          # Output executable
SOURCE="$SRC_DIR/main.c $SRC_DIR/plain_kernel.c"

# Check source directory
if [ ! -d "$SRC_DIR" ]; then
    echo "Error: $SRC_DIR not found."
    exit 1
fi

# =============================
# Step 1: Compile Baseline (-O0)
# =============================
echo "Compiling baseline (-O0 -g)..."
gcc $SOURCE -O0 -g -o $BIN
echo "Running baseline..."
./$BIN | awk -F': ' '/Mean time per iteration/ {print $2}' | sed 's/ s//'

rm -f $BIN

# =============================
# Step 2: Compile Optimized (-O3)
# =============================
echo "Compiling optimized (-O3 -ffast-math -march=native)..."
gcc $SOURCE -O3 -ffast-math -march=native -o $BIN

# =============================
# Step 3: Run optimized ITERATIONS times and capture times
# =============================
times=()
sum=0

for i in $(seq 1 $ITERATIONS); do
    # Extract numeric time, remove trailing ' s'
    t=$(./$BIN | awk -F': ' '/Mean time per iteration/ {gsub(/ s/,"",$2); print $2}')
    if [ -z "$t" ]; then
        echo "Error: Could not parse time from iteration $i"
        exit 1
    fi
    times+=("$t")
    sum=$(echo "$sum + $t" | bc -l)
    echo "Iteration $i: $t s"
done

# =============================
# Step 4: Compute min, max, average
# =============================
max=${times[0]}
min=${times[0]}
for t in "${times[@]}"; do
    if (( $(echo "$t > $max" | bc -l) )); then max=$t; fi
    if (( $(echo "$t < $min" | bc -l) )); then min=$t; fi
done

avg=$(echo "$sum / $ITERATIONS" | bc -l)

echo "-----------------------------------"
echo "OPTIMIZED RESULTS (n=$ITERATIONS)"
printf "Highest Time: %.6f s\n" "$max"
printf "Lowest Time:  %.6f s\n" "$min"
printf "Average Time: %.6f s\n" "$avg"

# Clean up
rm -f $BIN