#include "plain_kernel.h"

void saxpy_plain(const int *restrict x, int *restrict y, const int a, const int arr_size) {
    for (int i = 0; i < arr_size; i++) {
        y[i] = a*x[i] + y[i];
    }
}
