cmake_minimum_required(VERSION 4.2.3)

project(dynsim CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(dynsim src/dynsim.cpp)

include(FetchContent)

FetchContent_Declare(
    doctest
    GIT_REPOSITORY https://github.com/doctest/doctest
    GIT_TAG        v2.5.3
)

FetchContent_MakeAvailable(doctest)

add_executable(dynsim_tests test/test_dynsim.cpp)

# 4. Link doctest to your executable
target_link_libraries(dynsim_tests PRIVATE doctest::doctest)