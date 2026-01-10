#include "gpu_kernel.h"
#include <cuda_runtime.h>

__global__ void saxpy_kernel(const float* x,
                             float* y,
                             float a,
                             int n)
{
    int i = blockIdx.x * blockDim.x + threadIdx.x;
    if (i < n)
        y[i] = a * x[i] + y[i];
}

extern "C"
void saxpy_gpu(float* h_x,
               float* h_y,
               float a,
               int n)
{
    float *d_x, *d_y;
    size_t bytes = n * sizeof(float);

    cudaMalloc(&d_x, bytes);
    cudaMalloc(&d_y, bytes);

    cudaMemcpy(d_x, h_x, bytes, cudaMemcpyHostToDevice);
    cudaMemcpy(d_y, h_y, bytes, cudaMemcpyHostToDevice);

    int threads = 256;
    int blocks  = (n + threads - 1) / threads;

    saxpy_kernel<<<blocks, threads>>>(d_x, d_y, a, n);

    cudaMemcpy(h_y, d_y, bytes, cudaMemcpyDeviceToHost);

    cudaFree(d_x);
    cudaFree(d_y);
}
