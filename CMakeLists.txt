cmake_minimum_required(VERSION 3.20)
project(LearnCleanC C)

set (CMAKE_C_STANDARD 11)
set (CMAKE_C_STANDARD_REQUIRED ON)

# Common flags for the whole project
add_library(project_config INTERFACE)
target_compile_options(project_config INTERFACE
        -Wall -Wextra
        $<$<CONFIG:Debug>:-g -O0>
        $<$<CONFIG:Release>:-O3 -march=native -ffast-math>
)

# Add kernel subdirectories here
add_subdirectory(src/saxpy)
add_subdirectory(src/squared_arr)




