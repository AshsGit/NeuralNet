cmake_minimum_required(VERSION 3.10)

set(This LibTests)

set(Sources
    StackTests.cpp
    MyMathTests.cpp
    layers/Testfc_layer.cpp
)

add_executable(${This} ${Sources})
target_link_libraries(${This} PUBLIC
    gtest_main
)

add_test(
    NAME ${This}
    COMMAND ${This}
)


