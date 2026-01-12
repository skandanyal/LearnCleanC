#include "gpu_kernel.h"
#include "parallel_kernel.h"
#include "plain_kernel.h"
#include "restrict_kernel.h"

#include "omp.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
 * Wall-clock time
 * FLOPs/sec
 * Arithmetic intensity
 * Memory bandwidth
 * Vectorization reports
 * Scaling vs threads
 */

int main() {
  int n = 10000000;
  float *x = aligned_alloc(64, n * sizeof(float));
  float *y = aligned_alloc(64, n * sizeof(float));

  float a = 5.0f;

  for (int i = 0; i < n; i++) {
    x[i] = (float)i;
    y[i] = (float)i;
  }

  // heating the cache lines
  saxpy_parallel(x, y, a, n);

  // recording WALL-TIME
  struct timespec start_time, end_time;
  clock_gettime(CLOCK_MONOTONIC, &start_time);

  volatile float sink;

  // set number of threads
  omp_set_num_threads(4);

  // 1000 iterations for the parallel_kernel
  for (int i = 0; i < 1000; i++)
    saxpy_parallel(x, y, a, n);

  clock_gettime(CLOCK_MONOTONIC, &end_time);

  double time_elapsed = ((end_time.tv_sec - start_time.tv_sec) +
                         (end_time.tv_nsec - start_time.tv_nsec) * 1e-9) /
                        1000;

  sink = y[n - 1];
  printf("-----RESULTS-----\n");
  printf("Last element: %f\n", sink);
  printf("Mean time per iteration: %.6f s\n", time_elapsed);

  free(x);
  free(y);
  return 0;
}
