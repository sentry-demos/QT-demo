cmake_minimum_required(VERSION 3.5)

project(Sentry-qt5-demo VERSION 0.1 LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 COMPONENTS Widgets REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Widgets REQUIRED)

find_package(sentry REQUIRED)

set(PROJECT_SOURCES
        main.cpp
        mainwindow.cpp
        mainwindow.h
        eventCrashes.h
        eventCrashes.cpp
        mainwindow.ui
        resources.qrc
)
add_executable(Sentry-qt5-demo ${PROJECT_SOURCES})

target_link_libraries(Sentry-qt5-demo PUBLIC sentry::sentry)
target_link_libraries(Sentry-qt5-demo PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)
