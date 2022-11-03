cmake_minimum_required(VERSION 3.0.0)
project(tp_agenda VERSION 0.1.0)

add_executable(
    tp_agenda
    src/main.cpp
    
    src/entree.cpp
    include/entree.h
    
    src/tableau.cpp
    include/tableau.h
    
    src/agenda.cpp
    include/agenda.h
)
    
target_include_directories(tp_agenda PRIVATE include)



# include(CTest)
# enable_testing()

# set(CPACK_PROJECT_NAME ${PROJECT_NAME})
# set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
# include(CPack)
