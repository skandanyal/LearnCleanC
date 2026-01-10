add_executable(saxpy
        main.c
        plain_kernel.c
        restrict_kernel.c
        parallel_kernel.c
        gpu_kernel.cu
)
target_link_libraries(saxpy PRIVATE project_config)
target_include_directories(saxpy PRIVATE .)

set_target_properties(saxpy PROPERTIES
        CUDA_SEPARABLE_COMPILATION ON
)