//
// Created by skandan-c-y on 1/8/26.
//

#include "parallel_kernel.h"
#include "omp.h"

void saxpy_parallel(float * restrict x, float * restrict y, const float a, const int arr_size) {
    float sum = 0;
#pragma omp parallel for num_threads(3)
    for (int j = 0; j < arr_size; j++) {
        y[j] = a*x[j] + y[j];
        sum += 1;
    }
    volatile float sink = sum;
}