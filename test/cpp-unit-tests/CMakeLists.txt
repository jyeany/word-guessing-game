cmake_minimum_required(VERSION 3.5)

project(WordGuessUnitTests LANGUAGES CXX)

enable_testing()

if (UNIX)
    set(CMAKE_PREFIX_PATH "/home/jyeany/Qt/6.4.2/gcc_64")
    set(GOOGLETEST_DIR "/home/jyeany/Development/googletest")
elseif (MSVC)
    set(CMAKE_PREFIX_PATH "C:/Qt/6.4.1/msvc2019_64")
    set(GOOGLETEST_DIR "C:/Users/jyean/DevTools/GoogleTest/googletest")
endif ()

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
add_definitions(-DGTEST_LANGUAGE_CXX14)

find_package(Threads REQUIRED)
find_package(Qt6 6.2 COMPONENTS Quick Core REQUIRED)

if (EXISTS ${GOOGLETEST_DIR})
    set(GTestSrc ${GOOGLETEST_DIR}/googletest)
    set(GMockSrc ${GOOGLETEST_DIR}/googlemock)
elseif (UNIX AND EXISTS /usr/src/gtest)
    set(GTestSrc /usr/src/gtest)
    message(WARNING "Using gtest from system")
    if (EXISTS /usr/src/gmock)
        set(GMockSrc /usr/src/gmock)
    endif ()
else ()
    message( FATAL_ERROR "No googletest src dir found - set GOOGLETEST_DIR to enable!")
endif ()

set(GTestFiles ${GTestSrc}/src/gtest-all.cc)
set(GTestIncludes ${GTestSrc} ${GTestSrc}/include)
if (NOT ${GMockSrc} STREQUAL "")
    list(APPEND GTestFiles ${GMockSrc}/src/gmock-all.cc)
    list(APPEND GTestIncludes ${GMockSrc} ${GMockSrc}/include)
endif ()

include_directories(${GTestIncludes})

add_executable(WordGuessUnitTests
    ../../src/gamemanager.h
    ../../src/gamemanager.cpp
    ../../src/gamestatecreator.h
    ../../src/gamestatecreator.cpp
    ../../src/gamestate.h
    ../../src/gamestate.cpp
    ../../src/dicts/dictutils.h
    ../../src/dicts/dictutils.cpp
    ../../src/dicts/wordproviderfactory.h
    ../../src/dicts/wordproviderfactory.cpp
    ../../src/dicts/iwordprovider.h
    ../../src/dicts/shortwords.h
    ../../src/dicts/shortwords.cpp
    ../../src/dicts/mediumwords.h
    ../../src/dicts/mediumwords.cpp
    ../../src/dicts/longwords.h
    ../../src/dicts/longwords.cpp
    main.cpp
    tst_game_manager_case.cpp
    dicts/tst_dict_utils.cpp
    ${GTestFiles})

add_test(NAME WordGuessUnitTests COMMAND WordGuessUnitTests)
add_test(NAME DictUtilsUnitTests COMMAND DictUtilsUnitTests)

target_link_libraries(WordGuessUnitTests
    PRIVATE Threads::Threads Qt6::Quick Qt6::Core)
