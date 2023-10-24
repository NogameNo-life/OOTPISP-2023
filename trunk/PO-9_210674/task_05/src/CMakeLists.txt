cmake_minimum_required(VERSION 3.5)

project(CD_Collection)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

find_package(Qt6 COMPONENTS Widgets Sql REQUIRED)

add_executable(CD_Collection
        main.cpp
        MainWindow.cpp
        MainWindow.h
        MainWindow.ui)

target_link_libraries(CD_Collection PRIVATE Qt6::Widgets Qt5::Sql)
