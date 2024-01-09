cmake_minimum_required(VERSION 3.12)
project(HANGMAN)

set(CMAKE_CXX_STANDARD 11)

# Add the source files
set(SOURCES
        main.cpp
        HANGMAN.cpp)

# Add the header files
set(HEADERS
        HANGMAN.h)

# Create the executable
add_executable(${PROJECT_NAME} ${SOURCES} ${HEADERS})
