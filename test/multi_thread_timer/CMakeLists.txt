project(multi_thread_timer_test)

add_executable(${PROJECT_NAME} timer_test.cpp)

target_include_directories(${PROJECT_NAME} PUBLIC ${multi_thread_dir} ${utility_dir})

target_link_libraries(${PROJECT_NAME} PUBLIC multi_thread_timer)

add_test(
    NAME ${PROJECT_NAME}
    COMMAND ${PROJECT_NAME}
)