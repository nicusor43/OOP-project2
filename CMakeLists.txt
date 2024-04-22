cmake_minimum_required(VERSION 3.29)
project(OOPproj2)

set(CMAKE_CXX_STANDARD 17)

add_executable(OOPproj2 main.cpp
        Card.cpp
        Card.h
        CardStandard.cpp
        CardStandard.h
        CardPremium.cpp
        CardPremium.h
        Menu.cpp
        Menu.h)


set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -std=c++17 -pedantic-errors -Werror -Wno-unused-variable -Wno-unused-parameter -Wno-unused-but-set-variable -Wno-unused-function -Wno-unused-but-set-parameter -Wno-unused-local-typedefs -Wno-unused-private-field -Wno-unused-const-variable -Wno-unused-value -fsanitize=address -g")