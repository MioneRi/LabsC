cmake_minimum_required(VERSION 3.17.0 ) #Some really needed comment

set(PROJECT_NAME "Lab2")

project(${PROJECT_NAME})

#add_executable(main "задача2.1(29).c")

file (GLOB 
            HFILES "*.h"
            CFILES "*.c")

add_executable(${PROJECT_NAME} ${CFILES} ${HFILES})

