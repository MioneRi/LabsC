cmake_minimum_required(VERSION 3.17.0 ) #Some really needed comment

set(PROJECT_NAME "Lab4project")

project(${PROJECT_NAME})

#add_executable(main "main.c")

file (GLOB 
            HFILES "*.h"
            CFILES "*.c")

add_executable(${PROJECT_NAME} ${CFILES} ${HFILES})