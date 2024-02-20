cmake_minimum_required(VERSION 3.27)
project(Robot_simulator)

set(CMAKE_CXX_STANDARD 20)

set(SOURCE_FILES main.cpp)
add_executable(Robot_simulator_run ${SOURCE_FILES})

include_directories(src)
add_subdirectory(Google_tests)
add_subdirectory(src)

target_link_libraries(Robot_simulator_run robot_library)


