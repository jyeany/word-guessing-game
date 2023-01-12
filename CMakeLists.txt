cmake_minimum_required(VERSION 3.16)

project(word-guess-game VERSION 0.1 LANGUAGES CXX)

# Use this setting to get build working with CLion
# set(CMAKE_PREFIX_PATH "/home/jyeany/Qt/6.4.2/gcc_64")

set(CMAKE_AUTOMOC ON)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 6.2 COMPONENTS Quick REQUIRED)

add_subdirectory(test/cpp-unit-tests)
add_subdirectory(test/qml-unit-tests)

qt_add_executable(appword-guess-game
    src/gamestate.h
    src/gamestate.cpp
    src/main.cpp
)

qt_add_qml_module(appword-guess-game
    URI word-guess-game
    VERSION 1.0
    QML_FILES
        src/main.qml
        src/components/WordDisplay.qml
        src/components/WordGuess.qml
        src/components/LetterGuess.qml
        src/components/GameEnd.qml
)

set_target_properties(appword-guess-game PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

target_link_libraries(appword-guess-game
    PRIVATE Qt6::Quick)

install(TARGETS appword-guess-game
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
