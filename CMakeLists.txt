cmake_minimum_required(VERSION 3.11.0)
project(program VERSION 0.1.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(PROJECT_SOURCES biRing.hpp biRing.tpp iterators/biRingBaseIterator.hpp iterators/biRingIterator.hpp iterators/biRingConstIterator.hpp brUsage.hpp)
add_library(ProjectSourcesLib STATIC ${PROJECT_SOURCES})
set_target_properties(ProjectSourcesLib PROPERTIES LINKER_LANGUAGE CXX)

add_executable(program main.cpp)
target_link_libraries(program PRIVATE ProjectSourcesLib)

add_subdirectory(tests)