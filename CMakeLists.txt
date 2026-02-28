cmake_minimum_required(VERSION 3.11)

project(algo_visualizer)
find_package(raylib REQUIRED)

# vcpkg
if(DEFINED ENV{VCPKG_ROOT})
    message(STATUS "VCPKG found")
    set(CMAKE_TOOLCHAIN_FILE "$ENV{VCPKG_ROOT}/scripts/buildsystems/vcpkg.cmake")
    if(DEFINED ENV{VCPKG_DEFAULT_TRIPLET})
        set(VCPKG_TARGET_TRIPLET "$ENV{VCPKG_DEFAULT_TRIPLET}")
    else()
        set(VCPKG_TARGET_TRIPLET "x64-linux")
    endif()
endif()

file(GLOB PROJECT_SOURCES "src/*.cpp")
file(GLOB PROJECT_INCLUDE "src/*.hpp")

add_executable(${PROJECT_NAME})
target_sources(${PROJECT_NAME} PRIVATE ${PROJECT_SOURCES})
target_include_directories(${PROJECT_NAME} PRIVATE ${PROJECT_INCLUDE})
target_link_libraries(${PROJECT_NAME} PRIVATE raylib)
