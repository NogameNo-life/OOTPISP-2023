cmake_minimum_required(VERSION 3.5)
project(po9_210651_task_06 LANGUAGES CXX)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_PREFIX_PATH $ENV{QTDIR})
find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Core)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Core)
add_executable(po9_210651_task_06
  main.cpp
)
target_link_libraries(po9_210651_task_06 Qt${QT_VERSION_MAJOR}::Core)

