#include <iostream>

void tworz_wyz(int**& tab, int n, int m)
{
    tab = new int* [n];
    for (int i = 0;i < n;i++)
    {
            tab[i] = new int[m];
    }
}

void wypelnij_wyz(int** tab, int n)
{
    std::cout << "Uzupelnij macierz wierszami:"<<std::endl;
    for (int i = 0;i < n;i++)
    {
        for (int j = 0;j < n;j++)
        {
            std::cin >> tab[i][j];
        }
    }
}

void wypisz_wyz(int**tab, int n)
{
    for (int i = 0;i < n;i++)
    {
        for (int j = 0;j < n;j++)
        {
            std::cin >> tab[i][j];
        }
    }
}


