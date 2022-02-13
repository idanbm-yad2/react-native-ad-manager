cmake_minimum_required(VERSION 3.9.0)

set (CMAKE_VERBOSE_MAKEFILE ON)
set (CMAKE_CXX_STANDARD 11)

add_library(AdManager
    SHARED
    "${NODE_MODULES_DIR}/react-native/ReactCommon/jsi/jsi/jsi.cpp"
    ../cpp/react-native-ad-manager.cpp
    cpp-adapter.cpp
)

# Specifies a path to native header files.
include_directories(
    ../cpp
    "${NODE_MODULES_DIR}/react-native/React"
    "${NODE_MODULES_DIR}/react-native/React/Base"
    "${NODE_MODULES_DIR}/react-native/ReactCommon/jsi"
)

target_link_libraries(AdManager android)

