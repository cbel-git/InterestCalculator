cmake_minimum_required(VERSION 3.24)
project(InterestCalculator)

set(CMAKE_CXX_STANDARD 17)

set(PROJECT_HEADERS
        testclass.h
        )
set(PROJECT_SOURCES
        main.cpp
        testclass.cpp
        )

add_executable(InterestCalculator main.cpp CompoundInterestCalc.cpp CompoundInterestCalc.h)
