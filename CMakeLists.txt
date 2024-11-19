cmake_minimum_required(VERSION 3.29)
project(LabAssignment)

set(CMAKE_CXX_STANDARD 20)

add_executable(LabAssignment main.cpp
        sources/time.cpp
        headers/time.h
        headers/utilities.h
        sources/patient.cpp
        headers/patient.h
        sources/utilities.cpp
        sources/scheduler.cpp
        headers/scheduler.h
)
