cmake_minimum_required(VERSION 3.25)
project(Gabriel_Dobromilski_temat_7_v_1)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Gabriel_Dobromilski_temat_7_v_1
        dodawanie_odejmowanie.cpp
        dodawanie_odejmowanie.h
        macierz1.cpp
        macierz1.h
        main.cpp
        menu.cpp
        menu.h
        operacje_macierze.cpp
        operacje_macierze.h
        wyznacznik_odwracanie.cpp
        wyznacznik_odwracanie.h
        zap2_projekt_beta.pro)
