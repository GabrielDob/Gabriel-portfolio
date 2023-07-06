#include "dodawanie_odejmowanie.h"
#include "macierz1.h"
/**
 * @brief dodaj Funkcja dodająca macierze
 * @param glowa1 Pierwszy element listy zawierającej macierz
 */
void dodaj(macierz1 *&glowa1)
{
    macierz1 *pomoc1 = nullptr;
    ///zmienna pomocnicza przechowująca adres "głowy"
    pomoc1 = glowa1;
    ///pętla, w której dodawane są poszczególne elementy macierzy 1 oraz macierzy 2, dopóki zmienna pomocnicza nie jest nullpointerem
    while(pomoc1 != nullptr)
    {
        ///dodanie macierzy do zmiennej przechowującej macierz wynikową
        pomoc1->z = pomoc1->x + pomoc1->y;
        ///nadanie zmiennej pomocniczej adresu następnego elementu listy
        pomoc1 = pomoc1->next;
    }
}
/**
 * @brief odejmij Funkcja odejmująca macierze
 * @param glowa1
 */
void odejmij(macierz1 *&glowa1)
{
    macierz1 *pomoc1 = nullptr;
    ///zmienna pomocnicza przechowująca adres "głowy"
    pomoc1 = glowa1;
    ///pętla, w której dodawane są poszczególne elementy macierzy 1 oraz macierzy 2, dopóki zmienna pomocnicza nie jest nullpointerem
    while(pomoc1 != nullptr)
    {
        ///dodanie macierzy do zmiennej przechowującej macierz wynikową
        pomoc1->z = pomoc1->x - pomoc1->y;
        ///nadanie zmiennej pomocniczej adresu następnego elementu listy
        pomoc1 = pomoc1->next;
    }
}
