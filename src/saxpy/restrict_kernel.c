//
// Created by skandan-c-y on 1/8/26.
//

#include "restrict_kernel.h"

void saxpy_restrict(const float *restrict x, float *restrict y, const float a,
                    const int arr_size) {
  for (int i = 0; i < arr_size; i++) {
    y[i] = a * x[i] + y[i];
  }
}
