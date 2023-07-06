#ifndef OPERACJE_MACIERZE_H
#define OPERACJE_MACIERZE_H
#include "macierz1.h"
/**
 * @file operacje_macierze.h
 * @brief plik nagłówkowy modułu macierze
 *
 */
void wypisz(macierz1 *glowa1, int &m);
void macierz1_wpisz(macierz1 *&glowa1, macierz1 *&koniec1, int &n, int &m);
void macierz1_plik(macierz1 *&glowa1, macierz1 *&koniec1);
void macierz1_oba(macierz1 *&glowa1, macierz1 *&koniec1, int &n, int &m);
void usun(macierz1 *&glowa);
#endif // OPERACJE_MACIERZE_H
