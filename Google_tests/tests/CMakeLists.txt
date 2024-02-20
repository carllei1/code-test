include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

# 'Google_Tests_run' is the target name
# 'test1.cpp test2.cpp' are source files with tests
add_executable(Google_Tests_run basic_map_test.cpp basic_robot_test.cpp robot_manager_test.cpp)

target_link_libraries(Google_Tests_run gtest gtest_main)
target_link_libraries(Google_Tests_run robot_library)
