cmake_minimum_required(VERSION 3.10)

project(NeuralNetLib VERSION 0.1)

set(CMAKE_C_STANDARD 99)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

enable_testing()

add_subdirectory(googletest)

set(Headers
    ./include/stack.h
)

set(Sources
    ./lib/stack.cpp
)

configure_file(./libconf.h.in ./libconf.h)

add_library(${PROJECT_NAME} STATIC ${Sources} ${Headers})

add_subdirectory(test)
