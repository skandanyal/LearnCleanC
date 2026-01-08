# Profiling results

|          Kernel `saxpy`          | Iterations | Instructions Per Cycle | frontend cycles idle | Kernel shared object |
|:--------------------------------:|:----------:|:----------------------:|:--------------------:|:--------------------:|
|          `plain_kernel`          |     10     |          1.77          |        16.98         |        saxpy         |
|        `restrict_kernel`         |     -      |           -            |          -           |          -           |
| `parallel_kernel` <br> threads=6 |     10     |          0.20          |         4.45         |          -           |
