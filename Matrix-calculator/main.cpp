#include "menu.h"
#include "macierz1.h"
/**
 *@mainpage
 *@par Kalkulator macierzowy
 *@author Gabriel Dobromilski
 *@date 28.05.2020
 *@version 1.0
 */

/**
  @brief Funkcja main
 *
 *Funkcja main zawierająca deklaracje potrzebnych zmiennych,
 *tablic,list dwukierunkowych oraz główną funkcję "menu"
 *
 *@param m, n - rozmiary tablicy
 *@param tab, tab2 - tablice, których będą przechowywane macierze
 *@param glowa1, koniec1 - "głowa" oraz "ogon" macierzy1
 */

int main()
{
    int m = 0, n = 0;
    double **tab = nullptr;
    double **tab2 = nullptr;
    macierz1 *glowa1 = nullptr;
    macierz1 *koniec1 = nullptr;    
   while(true)
   {
       menu(glowa1, koniec1, tab, tab2, n, m);
   }
    return 0;
}
