cmake_minimum_required(VERSION 3.0.0)
project(win32api-concept VERSION 0.1.0 LANGUAGES C CXX)

include(CTest)
enable_testing()

add_executable(win32api-concept main.cpp)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
