add_executable(saxpy
        main.c
        kernels/plain_kernel.c
        kernels/restrict_kernel.c
        kernels/parallel_kernel.c
        kernels/gpu_kernel.cu
)
target_link_libraries(saxpy PRIVATE project_config)
target_include_directories(saxpy PRIVATE .)

set_target_properties(saxpy PROPERTIES
        CUDA_SEPARABLE_COMPILATION ON
)