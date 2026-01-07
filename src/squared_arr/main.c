#include "squared_array.h"
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int arr_size_;
    printf("Enter size of array: \n");
    if (scanf("%d", &arr_size_) != 1)
        return 1;

    int *in = malloc(arr_size_ * sizeof(int));
    int *out = malloc(arr_size_ * sizeof(int));

    printf("\nEnter array elements: \n");
    for (int i = 0; i < arr_size_; i++)
        if (scanf("%d", &in[i]) != 1)
            return 1;

    square(in, out, arr_size_);

    printf("\nSquared elements are:\n");
    for (int i = 0; i < arr_size_; i++)
        printf("Element %d: %d\n", i, *(out + i));

    free(in);
    free(out);

    return 0;
}
