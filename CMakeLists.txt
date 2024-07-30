cmake_minimum_required(VERSION 3.11)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

project(
    associative-law-checker
    VERSION 0.1
    LANGUAGES C CXX
)

# if (NOT CMAKE_BUILD_TYPE)
#     set(CMAKE_BUILD_TYPE Release)
# endif()

if (WIN32)
    add_definitions(-DNOMINMAX)
endif()

add_library(
    multitable
    nhfstr.cpp
    multitable.cpp
)

add_executable(
    associative-law-checker
    main.cpp
)

target_link_libraries(
    associative-law-checker PRIVATE
    multitable
)