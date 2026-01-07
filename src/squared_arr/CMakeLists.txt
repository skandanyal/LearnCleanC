add_executable(squared_arr
        main.c squared_array.c
)
target_link_libraries(squared_arr PRIVATE project_config)
target_include_directories(squared_arr PRIVATE .)