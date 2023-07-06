#include "wyznacznik_odwracanie.h"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cmath>


/**
 * @brief tworz_odw Funkcja alokująca pamięć dla macierzy
 * @param tab Tablica dynamiczna kwadratowa zawierająca wartości macierzy
 * @param n rozmiar macierzy kwadratowej
 */
void tworz_odw(double**& tab, int n)
{
    tab = new double* [n];
    for (int i = 0;i < n;i++)
    {
            tab[i] = new double[n];
    }
}
/**
 * @brief wypelnij_odw Funckja, przez którą użytkownik wpisuje dane do macierzy
 * @param tab Tablica dynamiczna kwadratowa zawierająca wartości macierzy
 * @param n rozmiar macierzy kwadratowej
 */
void wypelnij_odw(double** tab, int n)
{
    int l = 1;
    ///pętla, w której wpisywane są kolejne wartości macierzy, zależna od rozmiarów tablicy
    for (int i = 0;i < n;i++)
    {
        for (int j = 0;j < n;j++)
        {
            std::cout<<"wpisz "<<l<<" wyraz macierzy"<<std::endl;
            std::cin >> tab[i][j];
            ///pętla zabezpieczająca przed wpisaniem niewłaściwej zmiennej
            while(!std::cin.good())
            {
                std::cout<<"wpisano nieprawidlowa zmienna"<<std::endl;
                std::cin.clear();
                std::cin.sync();
                std::cin >> tab[i][j];
            }
            l++;
        }
    }
}

void wypelnij_plik_odw(double** tab, int n)
{
    std::string plik;
    std::cout<<"wpisz nazwe pliku"<<std::endl;
    std::cin>>plik;
    std::ifstream plik1(plik.c_str());
    ///sprawdzenie czy wpisano poprawną nazwę pliku
    while(!plik1.is_open())
    {
        plik1.clear();
        plik1.close();
        std:: cout<<"wystapil blad, wpisz poprawna nazwe pliku"<<std::endl;
        std::cin>>plik;
        plik1.open(plik.c_str());
    }
    for (int i = 0;i < n;i++)
    {
        for (int j = 0;j < n;j++)
        {
            if(plik1.eof() == false)
            plik1>> tab[i][j];
        }
    }
    plik1.close();
}
/**
 * @brief wypisz_odw Funkcja drukująca macierz
 * @param tab Tablica dynamiczna kwadratowa zawierająca wartości macierzy
 * @param n rozmiar macierzy kwadratowej
 */
void wypisz_odw(double **tab, int n)
{

    for (int i = 0;i < n;i++)
    {
        for (int j = 0;j < n;j++)
        {
            std::cout<<std::setw(8)<<std::fixed<<std::setprecision(2)<<tab[i][j];
        }
        std::cout<<std::endl;
    }
}
/**
 * @brief usun_odw Zwalnia pamięć po tablicy dynamicznej
 * @param tab2 Tablica dynamiczna kwadratowa zawierająca wartości macierzy
 * @param n rozmiar macierzy kwadratowej
 */
void usun_odw(double **tab2, int n)
{
    for( int i = 0; i < n; ++i )
            delete [] tab2[i];

        delete [] tab2;
}
/**
 * @brief det Rekurencyjna funkcja obliczająca rozwinięcie Laplace'a
 * @param tab Tablica dynamiczna zawierająca macierz
 * @param n rozmiar macierzy kwadratowej
 * @param w wektor wierszy
 * @param vk pomocniczy wektor kolumn
 * @return
 */
double det(double** tab,int n,int w,int *vk)
{
  int k,m,*vk2;
  double d;
  ///jeżeli macierz jest 1x1 to jej wyznacznik jest równy elementowi
  if(n==1)
      return tab[w][vk[0]];
  else
   {
      ///tworzenie dynamicznego wektora kolumn
      vk2 =new int[n-1];
      m=1;
      d=0;
      for(int i = 0; i < n; i++ )
        {
          k = 0;
          /// pętla obliczająca rozwinięcie Laplace'a
          for(int j = 0; j < n - 1; j++ )
          {
            if( k == i ) k++;
            vk2 [j] = vk [k++];
          }
          ///rekurencyjne liczenie wyznacznika
          d += m * tab [w ][vk[i]] * det (tab, n - 1,w + 1, vk2 );
          m = -m;
        }
        delete [ ] vk2;
        return d;
   }
}
/**
 * @brief ludist Funkcja dokonuje rozkładu LU macierzy A
 * @param tab tablica dynamiczna zawierająca macierz
 * @param n rozmiar tablicy
 * @return wartość logiczna, czy macierz może zostać odwrócona
 */

bool ludist (double **tab, int n)
{


  for(int k = 0; k < n - 1; k++ )
  {
    if(fabs (tab  [k][k]) == 0)
        return false;

    for( int i = k + 1; i < n; i++ )
      tab [i][k] /= tab [k][k];

    for(int i = k + 1; i < n; i++ )
    {
      for(int j = k + 1; j < n; j++ )
      {
        tab [i][j] -= tab [i][k] * tab [k][j];
      }
    }
  }

  return true;
}
/**
 * @brief lusolve Funkcja dokonująca odwrócenia
 * @param k wektor wierszy
 * @param n rozmiar tablicy
 * @param tab tablica dynamiczna zawierająca macierz
 * @param tab2 tablica dynamiczna zawierająca macierz jednostkową
 * @return wartość logiczną
 */
bool lusolve(int k, int n, double **tab, double **tab2)
{
  double s;

  for(int i = 1; i < n; i++)
  {
    s = 0;

    for(int j = 0; j < i; j++)
        s += tab [i][j] * tab2 [j][k];

    tab2 [i][k] -= s;
  }

  if(fabs (tab [n-1][n-1]) == 0)
      return false;

  tab2[n-1][k] /= tab [n-1][n-1];

  for(int i = n-2;i >= 0; i--)
  {
    s = 0;

    for(int j = i+1; j < n; j++ )
        s += tab [i][j] * tab2 [j][k];

    if(fabs( tab [ i ][ i ] ) == 0)
        return false;

    tab2[i][k] = (tab2[i][k] - s )/tab[i][i];
  }

  return true;
}
/**
 * @brief macierz_jednostkowa Funckja tworząca macierz jednostkową
 * @param tab2 Tablica dynamiczna zawierająca macierz odwrotną
 * @param n rozmiar macierzy kwadratowej
 */
void macierz_jednostkowa(double **tab2, int n)
{

    for(int i = 0; i < n; i++ )
       {
         for(int j = 0; j < n; j++ )
         {
             ///nadanie wartości 0 dla elementów poza główną przekątną
             tab2 [ i ][ j ] = 0;
         }
         ///nadanie wartości 1 dla elementów na głównej przekątnej
         tab2 [ i ][ i ] = 1;
       }
}


