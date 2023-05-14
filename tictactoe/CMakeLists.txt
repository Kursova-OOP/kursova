cmake_minimum_required(VERSION 3.16)

project(tictactoe LANGUAGES CXX)

find_package(Qt6 REQUIRED COMPONENTS Core Gui Widgets)

qt_standard_project_setup()

qt_add_executable(tictactoe main.cpp tictactoe.cpp)
//трябва да си допиша другите файлове като имена тук

set_target_properties(tictactoe PROPERTIES
WIN32_EXECUTABLE TRUE
)

target_link_libraries(tictactoe PRIVATE
Qt6::Core
Qt6::Gui
Qt6::Widgets
)