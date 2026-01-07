#include "plain_kernel.h"
#include <error.h>
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int m, n, a;

    // check if all inputs are recorded properly
    printf("Enter m, n, a: ");
    if (scanf("%d %d %d", &m, &n, &a) != 3) {
        fprintf(stderr, "Input error\n");
        return 1;
    }

    // check if sizes of both the arrays match
    if (m != n) {
        fprintf(stderr, "Sizes of vectors are different.\n");
        return 1;
    }

    int *x = malloc(m * sizeof(int));
    int *y = malloc(n * sizeof(int));
    if (!x || !y) {
          fprintf(stderr, "Memory allocation failed.\n");
          return 1;
    }

    printf("\nEnter elements of arr x:\n");
    for (int i = 0; i < m; i++)
        if (scanf("%d", &x[i]) != 1)
            fprintf(stderr, "Empty element recorded.\n");

    printf("\nEnter elements of arr y:\n");
    for (int i = 0; i < n; i++)
        if (scanf("%d", &y[i]) != 1)
            fprintf(stderr, "Empty element recorded.\n");

    saxpy_plain(x, y, a, m);

    printf("\nResult: \n");
    for (int i = 0; i < m; i++)
        printf("%d\n", *(y + i));

    free(x);
    free(y);

  return 0;
}
