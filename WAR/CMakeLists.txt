cmake_minimum_required(VERSION 3.12)
project(WAR)

set(CMAKE_CXX_STANDARD 11)

# Add the source files
set(SOURCES
        main.cpp
        card.cpp
        deck.cpp)

# Add the header files
set(HEADERS
        card.h
        deck.h)

# Create the executable
add_executable(WAR ${SOURCES} ${HEADERS})
