#ifndef MACIERZ1_H
#define MACIERZ1_H
/**
 * @brief The macierz1 class
 *
 * Definicja elementu zawierającego dwie macierze oraz macierz wynikową
 */

class macierz1
{
public:
    ///zmienna zawierająca wartości macierzy 1
    double x = 0;
    ///zmienna zawierająca wartości macierzy 2
    double y = 0;
    ///zmienna zawierająca wartości macierzy wynikowej
    double z = 0;
    ///wskaźnik do poprzedniego elementu listy
    macierz1 *prev = nullptr;
    ///wskaźnik do następnego elementu listy
    macierz1 *next = nullptr;

};

#endif // MACIERZ1_H
