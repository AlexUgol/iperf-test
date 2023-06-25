cmake_minimum_required(VERSION 3.0.0)
project(iperf-test VERSION 0.1.0 LANGUAGES C CXX)

add_executable(iperf-test main.cpp)
target_link_libraries(iperf-test PRIVATE iperf)
