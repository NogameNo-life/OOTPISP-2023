cmake_minimum_required(VERSION 3.5)

project(task_01)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_PREFIX_PATH $ENV{QTDIR})

find_package(QT NAMES Qt7 Qt6 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)

add_executable(po8_210646_task_01
        main.cpp
        mainwindow.cpp
        mainwindow.ui
)

target_link_libraries(po8_210646_task_01 Qt${QT_VERSION_MAJOR}::Widgets)