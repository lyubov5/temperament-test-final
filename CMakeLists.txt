cmake_minimum_required(VERSION 3.16)
project(TemperamentTest LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

find_package(Qt6 REQUIRED COMPONENTS Widgets)

add_executable(TemperamentTest
    main.cpp
    mainwindow.cpp
    mainwindow.h
    testwindow.cpp
    testwindow.h
    resultwindow.cpp
    resultwindow.h
    photo.qrc
    images.qrc
)

target_link_libraries(TemperamentTest PRIVATE Qt6::Widgets)
