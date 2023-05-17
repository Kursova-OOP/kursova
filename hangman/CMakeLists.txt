ake_minimum_required(VERSION 3.16)

project(hangman LANGUAGES CXX)

find_package(Qt6 REQUIRED COMPONENTS Core Gui Widgets)

qt_standard_project_setup()

qt_add_executable(hangman main.cpp hangman.cpp)
//трябва да си допиша другите файлове като имена тук

set_target_properties(hangman PROPERTIES
WIN32_EXECUTABLE TRUE
)

target_link_libraries(hangman PRIVATE
Qt6::Core
Qt6::Gui
Qt6::Widgets
)