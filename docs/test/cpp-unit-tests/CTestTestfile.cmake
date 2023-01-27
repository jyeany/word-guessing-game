# CMake generated Testfile for 
# Source directory: /home/jyeany/QtProjects/word-guess-game/test/cpp-unit-tests
# Build directory: /home/jyeany/QtProjects/build-word-guess-game-WebAssembly_Qt_6_4_2-Release/test/cpp-unit-tests
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(WordGuessUnitTests "/home/jyeany/Development/Emscripten/emsdk/node/14.18.2_64bit/bin/node" "/home/jyeany/QtProjects/build-word-guess-game-WebAssembly_Qt_6_4_2-Release/test/cpp-unit-tests/WordGuessUnitTests.js")
set_tests_properties(WordGuessUnitTests PROPERTIES  _BACKTRACE_TRIPLES "/home/jyeany/QtProjects/word-guess-game/test/cpp-unit-tests/CMakeLists.txt;63;add_test;/home/jyeany/QtProjects/word-guess-game/test/cpp-unit-tests/CMakeLists.txt;0;")
add_test(DictUtilsUnitTests "DictUtilsUnitTests")
set_tests_properties(DictUtilsUnitTests PROPERTIES  _BACKTRACE_TRIPLES "/home/jyeany/QtProjects/word-guess-game/test/cpp-unit-tests/CMakeLists.txt;64;add_test;/home/jyeany/QtProjects/word-guess-game/test/cpp-unit-tests/CMakeLists.txt;0;")
