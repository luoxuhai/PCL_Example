cmake_minimum_required(VERSION 3.22)
project(PCL_Example)

set(CMAKE_CXX_STANDARD 14)

find_package(PCL 1.3 REQUIRED COMPONENTS common io)
include_directories(${PCL_INCLUDE_DIRS})
link_directories(${PCL_LIBRARY_DIRS})
add_definitions(${PCL_DEFINITIONS})
add_executable(PCL_Example src/main.cpp)
target_link_libraries(PCL_Example ${PCL_LIBRARIES})

