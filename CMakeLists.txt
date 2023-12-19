cmake_minimum_required(VERSION 3.8.0)
project(win32api-concept VERSION 0.1.0 LANGUAGES C CXX)

include(CTest)
enable_testing()

add_executable(win32api-concept BaseWindow.hpp MainWindow.hpp main_oop.cpp)
# add_executable(win32api-concept main.cpp)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
set(CMAKE_CXX_STANDARD 17)
# Perform preprocessing without compilation when building.
# May cause interrupt debugger to behave erratically.
# set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /P")
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} /SUBSYSTEM:WINDOWS")
include(CPack)
