add_executable(saxpy
        main.c plain_kernel.c
)
target_link_libraries(saxpy PRIVATE project_config)
target_include_directories(saxpy PRIVATE .)