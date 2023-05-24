cmake_minimum_required(VERSION 3.25)

add_subdirectory(./lib/googletest_main)
set(gtest_SOURCE_DIR, ./lib/googletest_main)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

set(TEST_SOURCE_FILES runAllTests.cpp NoteListTest.cpp NoteTest.cpp DateTest.cpp)

add_executable(runNoteListTests ${TEST_SOURCE_FILES})
target_link_libraries(runNoteListTests gtest gtest_main core)
