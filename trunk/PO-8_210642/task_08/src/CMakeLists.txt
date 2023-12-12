cmake_minimum_required(VERSION 3.5)

project(po8_210642_task_08)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

add_executable(po8_210642_task_08_abstract_factory
        AbstractFactory.cpp        
 )

add_executable(po8_210642_task_08_builder
        Builder.cpp        
)
