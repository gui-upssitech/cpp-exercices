cmake_minimum_required(VERSION 3.0.0)
project(tp_agenda VERSION 0.1.0)

set(libs 
    src/entree.cpp
    include/entree.h

    src/tableau.cpp
    include/tableau.h

    src/agenda.cpp
    include/agenda.h
)

add_executable(test_tp1 test/test_tp1.cpp ${libs})
target_include_directories(test_tp1 PRIVATE include)

add_executable(test_tp2 test/test_tp2.cpp ${libs})
target_include_directories(test_tp2 PRIVATE include)