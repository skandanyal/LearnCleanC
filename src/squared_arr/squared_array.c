#include "squared_array.h"

void square(const int *in, int *out, int arr_size_) {
    for (int i = 0; i < arr_size_; i++)
        *(out + i) = *(in + i) * *(in + i);
}
