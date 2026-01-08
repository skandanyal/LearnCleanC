//
// Created by skandan-c-y on 1/8/26.
//

#ifndef LEARNCLEANC_PARALLEL_KERNEL_H
#define LEARNCLEANC_PARALLEL_KERNEL_H

void saxpy_parallel(float * restrict x, float * restrict y, const float a, const int arr_size);

#endif //LEARNCLEANC_PARALLEL_KERNEL_H