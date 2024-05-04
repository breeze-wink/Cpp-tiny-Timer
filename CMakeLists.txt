cmake_minimum_required(VERSION 3.0)
project(C++-tiny-Timer
    VERSION 0.1.0
    DESCRIPTION "try to implement a Cpp Timer, and with the development of use, improve it gragually."
    HOMEPAGE_URL "https://github.com/breeze-wink/Cpp-tiny-Timer"
    LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 17)

enable_testing()

set(target_output_path ${PROJECT_SOURCE_DIR}/bin)
set(lib_output_path ${PROJECT_SOURCE_DIR}/lib)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${lib_output_path})
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${lib_output_path})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${target_output_path})

set(utility_dir ${PROJECT_SOURCE_DIR}/utility)
set(multi_thread_dir ${PROJECT_SOURCE_DIR}/multi_thread_timer)
set(time_based_dir ${PROJECT_SOURCE_DIR}/time_based_timer)

add_subdirectory(time_based_timer)
add_subdirectory(multi_thread_timer)
add_subdirectory(test/multi_thread_timer)
add_subdirectory(test/time_based_timer)
