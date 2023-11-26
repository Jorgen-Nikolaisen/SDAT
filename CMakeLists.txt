cmake_minimum_required(VERSION 3.26)
project(SDAT)

set(CMAKE_CXX_STANDARD 23)

include(FetchContent)
FetchContent_Declare(
        googletest
        GIT_REPOSITORY https://github.com/google/googletest.git
        GIT_TAG        main
)
FetchContent_MakeAvailable(googletest)

find_package(CURL REQUIRED)

add_executable(SDAT main.cpp
        Sensor.cpp
        Missile_Controls.cpp
        Missile_Controls.h
        Sensor.h
        Data/TemperatureSensor.cpp
        Data/TemperatureSensor.h
        Data/Humidity.cpp
        Data/Humidity.h
)

target_link_libraries(SDAT ${CURL_LIBRARIES})
target_include_directories(SDAT PRIVATE ${CURL_INCLUDE_DIRS})

# Define the test executable target, including all necessary test files
add_executable(tests Test/MissileTester.cpp)

# Link the test executable with Google Test
target_link_libraries(tests gtest_main)
target_link_libraries(tests gtest_main ${CURL_LIBRARIES})
target_include_directories(tests PRIVATE ${CURL_INCLUDE_DIRS})