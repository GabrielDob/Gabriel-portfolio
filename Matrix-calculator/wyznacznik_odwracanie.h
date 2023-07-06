#ifndef WYZNACZNIK_ODWRACANIE_H
#define WYZNACZNIK_ODWRACANIE_H
/**
 * @file wyznacznik_odwracanie.h
 * @brief plik nagłówkowy modułu wyznacznik_odwracanie
 *
 */
void tworz_odw(double**& tab, int n);
void wypelnij_odw(double **tab, int n);
void wypelnij_plik_odw(double **tab, int n);
void wypisz_odw(double **tab, int n);
void usun_odw(double **tab2, int n);
double det(double **tab, int n, int w, int *vk);
bool ludist (double **tab, int n);
bool lusolve(int k, int n, double **tab, double **tab2);
void macierz_jednostkowa(double **tab2, int n);
#endif // WYZNACZNIK_ODWRACANIE_H
