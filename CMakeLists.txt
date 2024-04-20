cmake_minimum_required(VERSION 3.29)
project(OOPproj2)

set(CMAKE_CXX_STANDARD 17)

add_executable(OOPproj2 main.cpp
        Card.cpp
        Card.h
        CardStandard.cpp
        CardStandard.h
        CardPremium.cpp
        CardPremium.h)
