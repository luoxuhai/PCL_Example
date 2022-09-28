cmake_minimum_required(VERSION 3.18)

set(PROJECT_NAME PCL_Example)
project(${PROJECT_NAME})

set(CMAKE_CXX_STANDARD 14)

find_package(PCL 1.11 REQUIRED COMPONENTS filters io)
include_directories(${PCL_INCLUDE_DIRS})
link_directories(${PCL_LIBRARY_DIRS})
add_definitions(${PCL_DEFINITIONS})
add_executable(${PROJECT_NAME} main.cpp)
target_link_libraries(${PROJECT_NAME} ${PCL_LIBRARIES})
