cmake_minimum_required(VERSION 3.16)

project(word-guess-game VERSION 0.1 LANGUAGES CXX)

set(CMAKE_PREFIX_PATH $ENV{CMAKE_PREFIX_PATH})
set(CMAKE_AUTOMOC ON)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 6.2 COMPONENTS Quick REQUIRED)

add_subdirectory(test/cpp-unit-tests)
add_subdirectory(test/qml-unit-tests)

qt_add_executable(appword-guess-game
    src/gamemanager.h
    src/gamemanager.cpp
    src/gamestate.h
    src/gamestate.cpp
    src/gamestatecreator.h
    src/gamestatecreator.cpp
    src/dicts/shortwords.h
    src/dicts/shortwords.cpp
    src/dicts/mediumwords.h
    src/dicts/mediumwords.cpp
    src/dicts/longwords.h
    src/dicts/longwords.cpp
    src/dicts/iwordprovider.h
    src/dicts/wordproviderfactory.h
    src/dicts/wordproviderfactory.cpp
    src/dicts/dictutils.h
    src/dicts/dictutils.cpp
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
        src/components/GreetingView.qml
        src/components/MissedLetters.qml
        src/components/MissedWords.qml
        src/components/buttons/ColorButton.qml
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
