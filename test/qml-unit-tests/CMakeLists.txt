cmake_minimum_required(VERSION 3.5)

project(WordGuessQmlCase LANGUAGES CXX)

enable_testing()

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS QuickTest Qml)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS QuickTest Qml)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# no need to copy around qml test files for shadow builds - just set the respective define
add_definitions(-DQUICK_TEST_SOURCE_DIR="${CMAKE_CURRENT_SOURCE_DIR}")

add_executable(WordGuessQmlCase main.cpp
               setup.cpp setup.h
               tst_wordguessqmlcase.qml)
add_test(NAME WordGuessQmlCase COMMAND WordGuessQmlCase)

target_link_libraries(WordGuessQmlCase
                      PRIVATE Qt${QT_VERSION_MAJOR}::QuickTest
                      PRIVATE Qt${QT_VERSION_MAJOR}::Qml)

