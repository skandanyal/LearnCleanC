# LearnCleanC

A C17 sandbox to write, compile and benchmark isolated numerical kernels derived from common supervised machine learning 
algorithms. Explicit control over compiler-level optimization is emphasized. 

Each subdirectory contains a standalone main file and the kernels. 

## Goals

* Write clean, safe C17 with CMake as build system
* Study kernel behaviour under different release configurations and compiler optimization flags
* Profile numerical kernels to identify behaviour and system roofline

## Requirements

* C17
* GCC v13.3.0  
* CMake >= 3.20

## Build instructions 🔨

To build with `release` flags (`-O3`, `-march=native`, `-ffast-math`)
```
cmake -S . -B cmake-build-release -DCMAKE_BUILD_TYPE=Release       
cmake --build cmake-build-release
```

To build with `debug` flags (`-g`, `-O0`)
```
cmake -S . -B cmake-build-debug -DCMAKE_BUILD_TYPE=Debug       
cmake --build cmake-build-debug
```

## Collaboration

`This is still a work in progress`

Those interested in performance engineering, numerical kernel profiling and benchmarking, high performance computing on 
consumer grade chipsets are welcome to collaborate. 
