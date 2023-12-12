cmake_minimum_required(VERSION 3.5)

project(po8_210641_task_08)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

add_executable(po8_210641_task_08 
        main.cpp
        AbstractFactory.h
        Builder.h
)
