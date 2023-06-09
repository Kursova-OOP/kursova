cmake_minimum_required(VERSION 3.12)
project(PONG)

set(CMAKE_CXX_STANDARD 11)

# Add the source files
set(SOURCES
        main.cpp
        PONG.cpp)

# Add the header files
set(HEADERS
        PONG.h)

# Create the executable
add_executable(PONG ${SOURCES} ${HEADERS})