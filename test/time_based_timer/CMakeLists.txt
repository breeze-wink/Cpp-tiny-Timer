project(time_based_timer_test)

add_executable(${PROJECT_NAME} timer_test.cpp)

target_include_directories(${PROJECT_NAME} PUBLIC ${time_based_dir} ${utility_dir})

target_link_libraries(${PROJECT_NAME} PUBLIC time_based_timer)

add_test(
    NAME ${PROJECT_NAME}
    COMMAND ${PROJECT_NAME}
)