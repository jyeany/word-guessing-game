# Word Guessing Game 

## Overview
Simple word guessing game built using Qt6.  
Created to experiment with Qt6 development and deployment.  
Try the web assembly deployment out here: <demo>  
  
## Structure
_src_: Source code for the project  
_test_: Subdirectories with test projects  
_test/cpp-unit-tests_: Unit tests for C++ code using gtest  
_test/qml-unit-tests_: Unit tests for Qt Quick QML code 

## Build
Set the following environment variables prior to running cmake:  
_CMAKE_PREFIX_PATH_
_GOOGLETEST_DIR_
  
_CMAKE_PREFIX_PATH_ should point to the Qt base directory for the system being compiled on  
_GOOGLETEST_DIR_ should reference the base googletest source directory (has children googletest and googlemock)
