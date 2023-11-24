cmake_minimum_required(VERSION 3.26)
project(SDAT)

set(CMAKE_CXX_STANDARD 23)

add_executable(SDAT main.cpp
        Sensor.cpp
        Missile_Controls.cpp
        Missile_Controls.h
        Sensor.h
)
