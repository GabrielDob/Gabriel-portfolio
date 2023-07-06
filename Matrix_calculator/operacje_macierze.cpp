#include <iostream>
#include "operacje_macierze.h"
#include "macierz1.h"
#include <fstream>
#include <iomanip>
#include <stdlib.h>

using namespace std;
/**
 * @brief wypisz Funckja drukowania macierzy wierszami
 *
 * @param glowa1 Pierwszy element listy zawierającej macierz
 * @param m Rozmiar macierzy
 */
void wypisz(macierz1 *glowa1,int &m)
{
    ///licznik l, który umożliwia rozdzielenie elementów listy na wiersze i kolumny
    int l = 0;
    macierz1 *tmp = nullptr;
    tmp = glowa1;
    ///wypisanie elementów pierwszej macierzy
    while(tmp)
    {
        cout<<setw(5)<<tmp->x;
        tmp = tmp->next;
        l++;
        if(l == m)
        {
            cout<<endl;
            l = 0;
        }
    }
    cout<<endl;
    cout<<endl;
    l = 0;
    tmp = glowa1;
    ///wypisanie elementów drugiej macierzy
    while(tmp)
    {
        cout<<setw(5)<<tmp->y;
        tmp = tmp->next;
        l++;
        if(l == m)
        {
            cout<<endl;
            l = 0;
        }
    }
    cout<<endl;
    cout<<endl;
    l = 0;
    tmp = glowa1;
    ///wypisanie elementów macierzy wynikowej
    while(tmp)
    {
        cout<<setw(5)<<tmp->z;
        tmp = tmp->next;
        l++;
        if(l == m)
        {
            cout<<endl;
            l = 0;
        }
    }
    cout<<endl;
    cout<<endl;
}
/**
 * @brief macierz1_wpisz Funckja, przez którą użytkownik wpisuje dane do macierzy
 * @param glowa1 Pierwszy element listy zawierającej macierz
 * @param koniec1 Ostatni element listy zawierającej macierz
 * @param n Liczba wierszy
 * @param m Liczba kolumn
 */
void macierz1_wpisz(macierz1 *&glowa1, macierz1 *&koniec1, int &n, int &m)
{
    ///pętla, w której wpisywane są kolejne wartości dla poszczególnych elementów listy (macierz 1), zależna od rozmiarów tablicy
    for(int i = 0; i<m*n; i++)
    {
        macierz1 *pomoc = new macierz1;
        cout<<"wpisz "<<i+1<<" wyraz pierwszej macierzy"<<endl;
        ///wpisanie wartości do danego elementu macierzy 1
        cin >> pomoc->x;
        ///pętla zabezpieczająca przed wpisaniem niewłaściwej zmiennej
        while(!cin.good())
        {
          cout<<"wpisano nieprawidlowa zmienna"<<endl;
          cin.clear();
          cin.sync();
          cin >> pomoc->x;
        }
        pomoc->next = nullptr;
        ///sprawdzenie, czy istnieje już "głowa", jeżeli nie to stwarza ją
        if (glowa1 == nullptr)
        {
            glowa1 = pomoc;
            koniec1 = pomoc;
        }
        else
        {
            koniec1->next = pomoc;
            koniec1 = koniec1->next;
        }
    }
    macierz1 *tmp = nullptr;
    tmp = glowa1;
    ///pętla, w której wpisywane są kolejne wartości dla poszczególnych elementów listy (macierz 2), zależna od rozmiarów tablicy
    for(int i = 0; i<m*n; i++)
    {

        cout<<"wpisz "<<i+1<<" wyraz drugiej macierzy"<<endl;
        ///wpisanie wartości do danego elementu macierzy 2
        cin>>tmp->y;
        ///pętla zabezpieczająca przed wpisaniem niewłaściwej zmiennej
        while(!cin.good())
        {
          cout<<"wpisano nieprawidlowa zmienna"<<endl;
          cin.clear();
          cin.sync();
          cin>>tmp->y;
        }
        tmp = tmp->next;

    }
}
/**
 * @brief macierz1_plik Funckja, przez którą użytkownik wczytuje dane z wybranego przez siebie pliku
 * @param glowa1 Pierwszy element listy zawierającej macierz
 * @param koniec1 Ostatni element listy zawierającej macierz
 */
void macierz1_plik(macierz1 *&glowa1, macierz1 *&koniec1)
{
    ///zmienne typu string zawierające nazwy plików, oraz zmienną pomocniczą pomoc_s
    string plik1, plik2, pomoc_s;
    ///zmienna bool
    bool w1;
    cout<<"wpisz nazwe pierwszego pliku"<<endl;
    ///wpisanie nazwy pliku 1
    cin>>plik1;
    ifstream plikx(plik1);
    ///sprawdzenie czy wpisano poprawną nazwę pliku
    while(!plikx.is_open())
    {
        plikx.clear();
        plikx.close();
        cout<<"wystapil blad, wpisz poprawna nazwe pliku"<<endl;
        cin>>plik1;
        plikx.open(plik1.c_str());
    }
    ///pętla wczytująca wartości z pliku do macierzy 1
    while(plikx.eof()==false)
    {

        macierz1 *pomoc = new macierz1;
        ///wczytująca wartości z pliku do zmiennej pomocniczej pomoc_s
        plikx >> pomoc_s;
        ///sprawdzenie czy wartość w pomoc_s jest pusta
        w1 = pomoc_s.empty();
        ///jeżeli pomoc_s nie jest puste, funkcja atof zwraca string jako double
        if(!w1)
        {
            pomoc->x = atof(pomoc_s.c_str());
        }
        pomoc->next = nullptr;
        ///sprawdzenie, czy istnieje już "głowa", jeżeli nie to stwarza ją
        if (glowa1 == nullptr)
        {
            glowa1 = pomoc;
            koniec1 = pomoc;
        }
        else
        {
            koniec1->next = pomoc;
            koniec1 = koniec1->next;
        }
    }
    ///zamknięcie pliku
    plikx.close();
    cout<<"wpisz nazwe drugiego pliku"<<endl;
    cin>>plik2;
    ///wpisanie nazwy pliku 2
    ifstream pliky(plik2.c_str());
    ///sprawdzenie czy wpisano poprawną nazwę pliku
    while(!pliky.is_open())
    {
        pliky.clear();
        pliky.close();
        cout<<"wystapil blad, wpisz poprawna nazwe pliku"<<endl;
        cin>>plik2;
        pliky.open(plik2.c_str());
    }
    macierz1 *tmp = nullptr;
    tmp = glowa1;
    ///pętla, która tak samo jak podczas wczytywania pliku 1, sprawdza czy nie występują białe znaki
    while(pliky.eof()==false)
    {
        pliky >> pomoc_s;
        w1 = pomoc_s.empty();
        if(!w1)
        {
            tmp->y = atof(pomoc_s.c_str());
        }
    }
    ///zamknięcie pliku
     pliky.close();
}

void macierz1_oba(macierz1 *&glowa1, macierz1 *&koniec1, int &n, int &m)
{
    ///zmienne typu string zawierające nazwę pliku, oraz zmienną pomocniczą pomoc_s
    string plik, pomoc_s;
    bool w1;
    ///pętla, w której wpisywane są kolejne wartości dla poszczególnych elementów listy (macierz 1), zależna od rozmiarów tablicy
    for(int i = 0; i<m*n; i++)
    {
        macierz1 *pomoc = new macierz1;
        cout<<"wpisz "<<i+1<<" wyraz pierwszej macierzy"<<endl;
        cin >> pomoc->x;
        ///pętla zabezpieczająca przed wpisaniem niewłaściwej zmiennej
        while(!cin.good())
        {
          cout<<"wpisano nieprawidlowa zmienna"<<endl;
          cin.clear();
          cin.sync();
          cin >> pomoc->x;
        }
        pomoc->next = nullptr;
        ///sprawdzenie, czy istnieje już "głowa", jeżeli nie to stwarza ją
        if (glowa1 == nullptr)
        {
            glowa1 = pomoc;
            koniec1 = pomoc;
        }
        else
        {
            koniec1->next = pomoc;
            koniec1 = koniec1->next;
        }
    }
    cout<<"wpisz nazwe pliku"<<endl;
    ///wpisanie nazwy pliku
    cin>>plik;
    ifstream pliky(plik.c_str());
    ///sprawdzenie czy wpisano poprawną nazwę pliku
    while(!pliky.is_open())
    {
        pliky.clear();
        pliky.close();
        cout<<"wystapil blad, wpisz poprawna nazwe pliku"<<endl;
        cin>>plik;
        pliky.open(plik.c_str());
    }
    macierz1 *tmp = nullptr;
    tmp = glowa1;
    ///pętla, która sprawdza czy nie występują białe znaki
    for(int i = 0; i<m*n; i++)
    {
        pliky >> pomoc_s;
        w1 = pomoc_s.empty();
        if(!w1)
        {
            tmp->y = atof(pomoc_s.c_str());
        }
    }
     pliky.close();
}

/**
 * @brief usun Zwalnia pamięć po kolejnych elementach listy
 * @param glowa Pierwszy element listy zawierającej macierz
 */
void usun(macierz1 *&glowa)
{
    while(glowa)
    {
        macierz1 *tmp = glowa;
        glowa = glowa->next;
        delete tmp;
    }
}
