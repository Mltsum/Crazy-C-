cmake_minimum_required(VERSION 3.18)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(spdlog)

include_directories(
        ./3rd-party/spdlog/include
)

link_directories(
        ./3rd-party/spdlog/lib
)

add_executable(spdlog-test main.cpp)

target_link_libraries(spdlog-test
        spdlog
)
