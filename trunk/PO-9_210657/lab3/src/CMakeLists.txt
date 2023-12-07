cmake_minimum_required(VERSION 3.5)
set(PROJECT_NAME PO-9_210657_task_3 )
project(${PROJECT_NAME} VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)

set(PROJECT_SOURCES
    main.cpp
    mainwindow.cpp
    mainwindow.h
    mainwindow.ui
    task1window.cpp
    task1window.h
    task1window.ui
    task2window.cpp
    task2window.h
    task2window.ui
    task3window.cpp
    task3window.h
    task3window.ui
    task4window.cpp
    task4window.h
    task4window.ui
    task5window.cpp
    task5window.h
    task5window.ui
    task6window.cpp
    task6window.h
    task6window.ui    
)

add_executable(${PROJECT_NAME}
    ${PROJECT_SOURCES}
)

target_link_libraries(${PROJECT_NAME} PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)
