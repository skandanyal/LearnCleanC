#include <stdio.h>
#include <stdlib.h>

#include "parallel_kernel.h"
#include "plain_kernel.h"
#include "restrict_kernel.h"
#include "gpu_kernel.h"


int main() {
    int n = 10000000;
    float *x = aligned_alloc(64, n * sizeof(float));
    float *y = aligned_alloc(64, n * sizeof(float));

    float a = 5.0f;

    for (int i = 0; i < n; i++) {
        x[i] = (float)i;
        y[i] = (float)i;
    }

    volatile float sink;
    for (int i = 0; i <5000; i++)
        saxpy_gpu(x, y, a, n);

    sink = y[n-1];
    printf("%f\n", sink);

    free(x);
    free(y);
    return 0;
}