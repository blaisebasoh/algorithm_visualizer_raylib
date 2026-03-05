cmake_minimum_required(VERSION 3.6)
project(algo_visualizer LANGUAGES CXX)

find_package(raylib CONFIG REQUIRED)

add_executable(${PROJECT_NAME} src/main.cpp)

target_include_directories(${PROJECT_NAME} PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/src")
target_link_libraries(${PROJECT_NAME} PRIVATE raylib)