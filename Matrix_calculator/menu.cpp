#include "menu.h"
#include "dodawanie_odejmowanie.h"
#include "operacje_macierze.h"
#include "macierz1.h"
#include "wyznacznik_odwracanie.h"
#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;
/**
 * @brief cont Funkcja umożliwiająca użytkownikowi kontynuować pracę programu po zakończeniu operacji
 *
 * @param x znak, od którego zależy czy użytkownik chce kontynuować pracę programu
 * @return funkcja zwraca wartość logiczną war
 */
bool cont(char x)
{
    ///zmienna war
    bool war = true;
    cout<<"Chcesz kontynuowac? (Y/N)"<<endl;
    cin>>x;
    ///wymuszenie na użytkowniku wpisania odpowiedniej zmiennej
    while(x != 'y' && x !='n' && x != 'Y' && x != 'N')
    {
        cout<<"Y/N?"<<endl;
        cin>>x;
    }
    ///ustawienie wartości logicznej 1, jeżeli użytkownik chce kontynuować pracę
    if(x == 'y' || x == 'Y')
        war = true;
    ///ustawienie wartości logicznej 0, jeżeli użytkownik nie chce kontynuować pracy
    if(x == 'n' || x == 'N')
        war = false;
    ///zwrócenie zmiennej war, która odpowiada za kontynuowanie, lub wyłączenie programu
    return war;
}
/**
 * @brief menu Główna funkcja programu, zawierająca wszystkie operacje
 *
 * @param glowa1 Pierwszy element listy zawierającej macierz
 * @param koniec1 Ostatni element listy zawierającej macierz
 * @param tab Tablica dynamiczna zawierająca macierz
 * @param tab2 Tablica dynamiczna zawierająca macierz odwrotną
 * @param n rozmiar macierzy
 * @param m rozmiar macierzy
 */
void menu(macierz1 *&glowa1, macierz1 *&koniec1, double**tab, double**tab2, int &n, int &m)
{
    /**
     * Procedura "menu" polega na wywołaniu funkcji wykonujących operacje na macierzach w zagnieżdżonych switch'ach
     */
    system("CLS");
    cout<<"1.DODAJ MACIERZE"<<endl;
    cout<<"2.ODEJMIJ MACIERZE"<<endl;
    cout<<"3.WYZNACZNIK MACIERZY"<<endl;
    cout<<"4.ODWRACANIE MACIERZY"<<endl;
    int a = 0,b = 0,x = 0;
    cin>>a;
    ///pętla zabezpieczająca przed wpisaniem niewłaściwej zmiennej
    while(!cin.good())
    {
      cout<<"wpisano nieprawidlowa zmienna"<<endl;
      cin.clear();
      cin.sync();
    }
    ///wymuszenie na użytkowniku wpisania odpowiedniej zmiennej
    while(!(a>=1 && a<=4))
    {
        cout<<"nie istnieje taka opcja, wpisz liczbe od 1 do 4"<<endl;
        cin>>a;
        ///pętla zabezpieczająca przed wpisaniem niewłaściwej zmiennej
        while(!cin.good())
        {
          cout<<"wpisano nieprawidlowa zmienna"<<endl;
          cin.clear();
          cin.sync();
        }
    }
    ///pierwszy switch dotyczący wyboru operacji, jakiej użytkownik chce dokonać
    switch(a)
    {
        ///użytkownik wybrał dodawanie
        case 1:
        system("CLS");
        cout<<"1.WPISZ MACIERZE"<<endl;
        cout<<"2.WCZYTAJ MACIERZE Z PLIKU"<<endl;
        cout<<"3.WPISZ JEDNA MACIERZ, WCZYTAJ DRUGA"<<endl;

        cin>>b;
        ///pętla zabezpieczająca przed wpisaniem niewłaściwej zmiennej
        while(!cin.good())
        {
          cout<<"wpisano nieprawidlowa zmienna"<<endl;
          cin.clear();
          cin.sync();
        }
        ///wymuszenie na użytkowniku wpisania odpowiedniej zmiennej
        while(!(b>=1 && b<=3))
        {
            cout<<"nie istnieje taka opcja, wpisz liczbe od 1 do 3"<<endl;
            cin>>b;
            ///pętla zabezpieczająca przed wpisaniem niewłaściwej zmiennej
            while(!cin.good())
            {
              cout<<"wpisano nieprawidlowa zmienna"<<endl;
              cin.clear();
              cin.sync();
            }
        }
        ///switch dotyczący wyboru w jaki sposób użytkownik chce wprowadzić dane
        switch(b)
        {
        ///użytkownik wybrał opcję wpisania macierzy
        case 1:
        {
          system("CLS");
          cout<<"Wpisz rozmiary tablicy"<<endl;
          cin>>m;
          ///pętla zabezpieczająca przed wpisaniem niewłaściwej zmiennej
          while(!cin.good())
          {
            cout<<"wpisano nieprawidlowa zmienna"<<endl;
            cin.clear();
            cin.sync();
            cin>>m;
          }
          cin>>n;
          ///pętla zabezpieczająca przed wpisaniem niewłaściwej zmiennej
          while(!cin.good())
          {
            cout<<"wpisano nieprawidlowa zmienna"<<endl;
            cin.clear();
            cin.sync();
            cin>>n;
          }
          ///wywołanie funkcji dodających macierze
          macierz1_wpisz(glowa1,koniec1,m,n);
          dodaj(glowa1);
          wypisz(glowa1,m);
          usun(glowa1);
            break;
        }
            ///użytkownik wybrał opcję wczytania obydwu macierzy z pliku
            case 2:
        {
          system("CLS");
          cout<<"Wpisz rozmiary tablicy"<<endl;
          cin>>m;
          ///pętla zabezpieczająca przed wpisaniem niewłaściwej zmiennej
          while(!cin.good())
          {
            cout<<"wpisano nieprawidlowa zmienna"<<endl;
            cin.clear();
            cin.sync();
            cin>>m;
          }
          cin>>n;
          ///pętla zabezpieczająca przed wpisaniem niewłaściwej zmiennej
          while(!cin.good())
          {
            cout<<"wpisano nieprawidlowa zmienna"<<endl;
            cin.clear();
            cin.sync();
            cin>>n;
          }
          ///wywołanie funkcji dodających macierze
          macierz1_plik(glowa1,koniec1);
          dodaj(glowa1);
          wypisz(glowa1,m);
          usun(glowa1);
            break;
        }
            ///użytkownik wybrał opcję wpisania jednej macierzy i wczytania drugiej z pliku
            case 3:
        {
          system("CLS");
          cout<<"Wpisz rozmiary tablicy"<<endl;
          cin>>m;
          ///pętla zabezpieczająca przed wpisaniem niewłaściwej zmiennej
          while(!cin.good())
          {
            cout<<"wpisano nieprawidlowa zmienna"<<endl;
            cin.clear();
            cin.sync();
            cin>>m;
          }
          cin>>n;
          ///pętla zabezpieczająca przed wpisaniem niewłaściwej zmiennej
          while(!cin.good())
          {
            cout<<"wpisano nieprawidlowa zmienna"<<endl;
            cin.clear();
            cin.sync();
            cin>>n;
          }
          ///wywołanie funkcji dodających macierze
          macierz1_oba(glowa1,koniec1,m,n);
          dodaj(glowa1);
          wypisz(glowa1,m);
          usun(glowa1);
              break;
        }
        }
        break;
    ///użytkownik wybrał odejmowanie
    case 2:
        system("CLS");
        cout<<"1.WPISZ MACIERZE"<<endl;
        cout<<"2.WCZYTAJ MACIERZE Z PLIKU"<<endl;
        cout<<"3.WPISZ JEDNA MACIERZ, WCZYTAJ DRUGA"<<endl;
        cin>>b;
        ///pętla zabezpieczająca przed wpisaniem niewłaściwej zmiennej
        while(!cin.good())
        {
          cout<<"wpisano nieprawidlowa zmienna"<<endl;
          cin.clear();
          cin.sync();
        }
        ///wymuszenie na użytkowniku wpisania odpowiedniej zmiennej
        while(!(b>=1 && b<=3))
        {
            cout<<"nie istnieje taka opcja, wpisz liczbe od 1 do 3"<<endl;
            cin>>b;
            ///pętla zabezpieczająca przed wpisaniem niewłaściwej zmiennej
            while(!cin.good())
            {
              cout<<"wpisano nieprawidlowa zmienna"<<endl;
              cin.clear();
              cin.sync();
            }
        }
        ///switch dotyczący wyboru w jaki sposób użytkownik chce wprowadzić dane
        switch(b)
        {
            ///użytkownik wybrał opcję wpisania macierzy
            case 1:
        {
          system("CLS");
          cout<<"Wpisz rozmiary tablicy"<<endl;
          cin>>m;
          ///pętla zabezpieczająca przed wpisaniem niewłaściwej zmiennej
          while(!cin.good())
          {
            cout<<"wpisano nieprawidlowa zmienna"<<endl;
            cin.clear();
            cin.sync();
            cin>>m;
          }
          cin>>n;
          ///pętla zabezpieczająca przed wpisaniem niewłaściwej zmiennej
          while(!cin.good())
          {
            cout<<"wpisano nieprawidlowa zmienna"<<endl;
            cin.clear();
            cin.sync();
            cin>>n;
          }
          ///wywołanie funkcji odejmujących macierze
          macierz1_wpisz(glowa1,koniec1,m,n);
          odejmij(glowa1);
          wypisz(glowa1,m);
          usun(glowa1);
            break;
        }
            ///użytkownik wybrał opcję wczytania obydwu macierzy z pliku
            case 2:
        {
          system("CLS");
          cout<<"Wpisz rozmiary tablicy"<<endl;
          cin>>m;
          ///pętla zabezpieczająca przed wpisaniem niewłaściwej zmiennej
          while(!cin.good())
          {
            cout<<"wpisano nieprawidlowa zmienna"<<endl;
            cin.clear();
            cin.sync();
            cin>>m;
          }
          cin>>n;
          ///pętla zabezpieczająca przed wpisaniem niewłaściwej zmiennej
          while(!cin.good())
          {
            cout<<"wpisano nieprawidlowa zmienna"<<endl;
            cin.clear();
            cin.sync();
            cin>>n;
          }
          ///wywołanie funkcji odejmujących macierze
          macierz1_plik(glowa1,koniec1);
          odejmij(glowa1);
          wypisz(glowa1,m);
          usun(glowa1);
            break;
        }
            ///użytkownik wybrał opcję wpisania jednej macierzy i wczytania drugiej z pliku
            case 3:
        {
          system("CLS");
          cout<<"Wpisz rozmiary tablicy"<<endl;
          cin>>m;
          ///pętla zabezpieczająca przed wpisaniem niewłaściwej zmiennej
          while(!cin.good())
          {
            cout<<"wpisano nieprawidlowa zmienna"<<endl;
            cin.clear();
            cin.sync();
            cin>>m;
          }
          cin>>n;
          ///pętla zabezpieczająca przed wpisaniem niewłaściwej zmiennej
          while(!cin.good())
          {
            cout<<"wpisano nieprawidlowa zmienna"<<endl;
            cin.clear();
            cin.sync();
            cin>>n;
          }
          ///wywołanie funkcji odejmujących macierze
          macierz1_oba(glowa1,koniec1,m,n);
          odejmij(glowa1);
          wypisz(glowa1,m);
          usun(glowa1);
            break;
        }
        }
        break;
    ///użytkownik wybrał liczenie wyznacznika
    case 3:
        system("CLS");
        cout<<"1.WPISZ MACIERZ"<<endl;
        cout<<"2.WCZYTAJ MACIERZ Z PLIKU"<<endl;
        cin>>b;
        ///pętla zabezpieczająca przed wpisaniem niewłaściwej zmiennej
        while(!cin.good())
        {
          cout<<"wpisano nieprawidlowa zmienna"<<endl;
          cin.clear();
          cin.sync();
        }
        ///wymuszenie na użytkowniku wpisania odpowiedniej zmiennej
        while(!(b>=1 && b<=2))
        {
            cout<<"nie istnieje taka opcja, wpisz liczbe 1 lub 2"<<endl;
            cin>>b;
            ///pętla zabezpieczająca przed wpisaniem niewłaściwej zmiennej
            while(!cin.good())
            {
              cout<<"wpisano nieprawidlowa zmienna"<<endl;
              cin.clear();
              cin.sync();
            }
        }
        ///switch dotyczący wyboru w jaki sposób użytkownik chce wprowadzić dane
        switch(b)
        {
        ///użytkownik wybrał opcję wpisania macierzy
            case 1:
        {
         cout<<"podaj wymiar macierzy kwadratowej"<<endl;
         cin>>n;
         ///pętla zabezpieczająca przed wpisaniem niewłaściwej zmiennej
         while(!cin.good())
         {
           cout<<"wpisano nieprawidlowa zmienna"<<endl;
           cin.clear();
           cin.sync();
           cin>>n;
         }
         ///wywołanie funkcji liczących wyznacznik macierzy
         tworz_odw(tab,n);
         wypelnij_odw(tab,n);
         wypisz_odw(tab,n);
         ///alokacja pamięci dla dynamicznego wektora kolumnowego
         int *vk;
                 vk = new int[n];
                 for(int i = 0; i < n; i++ )
                   vk [ i ] = i;
                 cout <<"wyznacznik funkcji to = "<< det(tab,n,0,vk)<< endl;
         usun_odw(tab,n);
            break;
         }

            case 2:
         ///użytkownik wybrał opcję wczytania macierzy z pliku
         {
         cout<<"podaj wymiar macierzy kwadratowej"<<endl;
         cin>>n;
         ///pętla zabezpieczająca przed wpisaniem niewłaściwej zmiennej
         while(!cin.good())
         {
           cout<<"wpisano nieprawidlowa zmienna"<<endl;
           cin.clear();
           cin.sync();
           cin>>n;
         }
         ///wywołanie funkcji liczących wyznacznik macierzy
         tworz_odw(tab,n);
         wypelnij_plik_odw(tab,n);
         wypisz_odw(tab,n);
         ///alokacja pamięci dla dynamicznego wektora kolumnowego
         int *vkx;
                 vkx = new int[n];
                 for(int i = 0; i < n; i++ )
                   vkx [ i ] = i;
                 cout <<"wyznacznik funkcji to = "<< det(tab,n,0,vkx)<< endl;
         usun_odw(tab,n);
            break;
        }
        }
        break;
    ///użytkownik wybrał liczenie macierzy odwrotnej
    case 4:
        system("CLS");
        cout<<"1.WPISZ MACIERZ"<<endl;
        cout<<"2.WCZYTAJ MACIERZ Z PLIKU"<<endl;
        cin>>b;
        ///pętla zabezpieczająca przed wpisaniem niewłaściwej zmiennej
        while(!cin.good())
        {
          cout<<"wpisano nieprawidlowa zmienna"<<endl;
          cin.clear();
          cin.sync();
        }
        ///wymuszenie na użytkowniku wpisania odpowiedniej zmiennej
        while(!(b>=1 && b<=2))
        {
            cout<<"nie istnieje taka opcja, wpisz liczbe 1 lub 2"<<endl;
            cin>>b;
            ///pętla zabezpieczająca przed wpisaniem niewłaściwej zmiennej
            while(!cin.good())
            {
              cout<<"wpisano nieprawidlowa zmienna"<<endl;
              cin.clear();
              cin.sync();
            }
        }
        ///switch dotyczący wyboru w jaki sposób użytkownik chce wprowadzić dane
        switch(b)
        {
            ///użytkownik wybrał opcję wpisania macierzy
            case 1:
        {
         cout<<"podaj wymiar macierzy kwadratowej"<<endl;
         cin>>n;
         ///pętla zabezpieczająca przed wpisaniem niewłaściwej zmiennej
         while(!cin.good())
         {
           cout<<"wpisano nieprawidlowa zmienna"<<endl;
           cin.clear();
           cin.sync();
           cin>>n;
         }
         ///wywołanie funkcji odwracania macierzy
         tworz_odw(tab,n);
         tworz_odw(tab2,n);
         wypelnij_odw(tab,n);
         wypisz_odw(tab,n);
         bool ok = true;
         macierz_jednostkowa(tab2,n);
         if(ludist(tab,n))
            {
         for(int i = 0; i < n; i++)
              {
                  if(!lusolve (i, n, tab, tab2 ))
                  {
                    ok = false;
                    break;
                  }
              }
            }
            else ok = false;
               if(ok)
               {
                   cout<<endl;
                   cout<<"macierz odwrotna to: "<<endl;
                   cout<<endl;
                   wypisz_odw(tab2,n);
               }
               else
               {
                   cout<<endl;
                   cout<<"nie mozna stworzyc macierzy odwrotnej"<<endl;
               }
          usun_odw(tab,n);
          usun_odw(tab2,n);
            break;
        }
            ///użytkownik wybrał opcję wczytania macierzy z pliku
            case 2:
        {
         cout<<"podaj wymiar macierzy kwadratowej"<<endl;
         cin>>n;
         ///pętla zabezpieczająca przed wpisaniem niewłaściwej zmiennej
         while(!cin.good())
         {
           cout<<"wpisano nieprawidlowa zmienna"<<endl;
           cin.clear();
           cin.sync();
           cin>>n;
         }
         ///wywołanie funkcji odwracania macierzy
         tworz_odw(tab,n);
         tworz_odw(tab2,n);
         wypelnij_plik_odw(tab,n);
         wypisz_odw(tab,n);
         bool ok = true;
         macierz_jednostkowa(tab2,n);
         if(ludist(tab,n))
            {
         for(int i = 0; i < n; i++)
              {
                  if(!lusolve (i, n, tab, tab2))
                  {
                    ok = false;
                    break;
                  }
              }
            }
            else ok = false;
               if(ok)
               {
                   cout<<endl;
                   cout<<"macierz odwrotna to: "<<endl;
                   cout<<endl;
                   wypisz_odw(tab2,n);
               }
               else
               {
                   cout<<endl;
                   cout<<"nie mozna stworzyc macierzy odwrotnej"<<endl;
               }
               usun_odw(tab,n);
               usun_odw(tab2,n);
            break;
        }
            break;
       }
    }
    /**
     * wywołanie funkcji cont oraz wyłączenie programu gdy cont(x) == false
     * @see cont(char x)
     */
    if(cont(x) == false)
        exit (0);
}
