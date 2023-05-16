cmake_minimum_required(VERSION 3.16)

project(lab1 LANGUAGES CXX)

find_package(Qt6 REQUIRED COMPONENTS Core Gui Widgets)

qt_standard_project_setup()

qt_add_executable(lab1 lifeSimulator.cpp)

set_target_properties(lab1 PROPERTIES
    WIN32_EXECUTABLE TRUE
    MACOSX_BUNDLE TRUE
)

target_link_libraries(lab1 PRIVATE
    Qt6::Core
    Qt6::Gui
    Qt6::Widgets
)
