cmake_minimum_required(VERSION 3.24)
project(lab_2_sd)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(lab_2_sd
        ATM.cpp
        ATM.h
        Colection.cpp
        Colection.h
        Interfata.cpp
        Interfata.h
        Teste.cpp
        teste.h
        Tranzaction.cpp
        Tranzaction.h main.cpp)
