cmake_minimum_required(VERSION 4.2.3)

project(dynsim CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_library(project_warnings INTERFACE)

if(CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
    target_compile_options(project_warnings INTERFACE
        -Wall
        -Wextra
        -Wpedantic
        -Wconversion
        -Wsign-conversion
        -Wshadow
        -Wformat=2
        -Wnull-dereference
        -Wdouble-promotion
        -Wimplicit-fallthrough
        -Wcast-align
        -Wundef
    )
endif()

add_executable(dynsim src/dynsim.cpp)
target_link_libraries(dynsim PRIVATE project_warnings)

include(FetchContent)

FetchContent_Declare(
    doctest
    GIT_REPOSITORY https://github.com/doctest/doctest
    GIT_TAG        v2.5.3
)

FetchContent_MakeAvailable(doctest)

add_executable(dynsim_tests test/test_dynsim.cpp test/signal_container_test.cpp)

include_directories(src)

target_link_libraries(dynsim_tests PRIVATE doctest::doctest)
target_link_libraries(dynsim_tests PRIVATE project_warnings)