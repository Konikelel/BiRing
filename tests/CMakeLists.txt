include(FetchContent)
FetchContent_Declare(
        googletest
        GIT_REPOSITORY      https://github.com/google/googletest.git
        GIT_TAG main
)
FetchContent_MakeAvailable(googletest)

file(GLOB_RECURSE TEST_SOURCES "*test*.cpp")
set(TEST_PROJECT_SOURCES
        fixtures/biRingFixture.hpp fixtures/biRingFixture.cpp
)


add_executable(testGoogle ${TEST_SOURCES} ${TEST_PROJECT_SOURCES})
target_link_libraries(testGoogle PRIVATE gtest gtest_main ProjectSourcesLib)

target_include_directories(testGoogle PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/fixtures)
target_include_directories(testGoogle PRIVATE ${CMAKE_SOURCE_DIR})