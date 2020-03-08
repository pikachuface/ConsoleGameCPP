cmake_minimum_required(VERSION 3.15.0)

project (ConsoleGameCPP)

file(GLOB_RECURSE _HDRFILES ${CMAKE_CURRENT_SOURCE_DIR}/*.h)
file(GLOB_RECURSE _SRCFILES ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp)

source_group("Header Files" FILES ${_HDRFILES})
source_group("Source Files" FILES ${_SRCFILES})

add_executable(${PROJECT_NAME} ${_HDRFILES} ${_SRCFILES})

if(UNIX)
    target_link_libraries(${PROJECT_NAME} pthread)
    target_link_libraries(${PROJECT_NAME} ncurses)    
endif(UNIX)
