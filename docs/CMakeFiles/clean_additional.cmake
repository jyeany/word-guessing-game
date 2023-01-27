# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Release")
  file(REMOVE_RECURSE
  "CMakeFiles/appword-guess-game_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/appword-guess-game_autogen.dir/ParseCache.txt"
  "appword-guess-game_autogen"
  "test/cpp-unit-tests/CMakeFiles/WordGuessUnitTests_autogen.dir/AutogenUsed.txt"
  "test/cpp-unit-tests/CMakeFiles/WordGuessUnitTests_autogen.dir/ParseCache.txt"
  "test/cpp-unit-tests/WordGuessUnitTests_autogen"
  "test/qml-unit-tests/CMakeFiles/WordGuessQmlCase_autogen.dir/AutogenUsed.txt"
  "test/qml-unit-tests/CMakeFiles/WordGuessQmlCase_autogen.dir/ParseCache.txt"
  "test/qml-unit-tests/WordGuessQmlCase_autogen"
  )
endif()
