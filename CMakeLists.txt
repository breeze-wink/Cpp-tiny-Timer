cmake_minimum_required(VERSION 3.0)
project(Timer)

set(CMAKE_CXX_STANDARD 17)
set(target_output_path ${PROJECT_SOURCE_DIR}/bin)
set(lib_output_path ${PROJECT_SOURCE_DIR}/lib)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${lib_output_path})
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${lib_output_path})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${target_output_path})

set(utility_dir ${PROJECT_SOURCE_DIR}/utility)
set(srclist main.cpp)
add_subdirectory(time_based_timer)
add_subdirectory(multi_thread_timer)
add_executable(test ${srclist})

target_include_directories(test PUBLIC multi_thread_timer)
target_link_libraries(test PUBLIC multi_thread_timer time_based_timer)