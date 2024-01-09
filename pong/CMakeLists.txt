cmake_minimum_required(VERSION 3.16)

project(pong LANGUAGES CXX)

find_package(Qt6 REQUIRED COMPONENTS Core Gui Widgets)

qt_standard_project_setup()

qt_add_executable(pong main.cpp pong.cpp)
//трябва да си допиша другите файлове като имена тук

set_target_properties(pong PROPERTIES
WIN32_EXECUTABLE TRUE
)

target_link_libraries(pong PRIVATE
Qt6::Core
Qt6::Gui
Qt6::Widgets
)