cmake_minimum_required(VERSION 3.25)
project(AndreaGepponiLab)

set(CMAKE_CXX_STANDARD 11)

add_subdirectory(test)

set(SOURCE_FILES Date.h Date.cpp Note.h Note.cpp NoteList.h NoteList.cpp Testo.txt)

add_executable(AndreaGepponiLab main.cpp)
add_library(core ${SOURCE_FILES})
target_link_libraries(AndreaGepponiLab core)
