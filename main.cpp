#include <iostream>
#include <windows.h>
#include "ksiazkaTel.h"
#include <fstream>
#include <cstdlib>

using namespace std;

void wczytajKontaktyZpliku(KsiazkaTelefoniczna kontakty[]);
int ileZapisanychKontaktow(KsiazkaTelefoniczna kontakty[]);

int main()
{
    char wybranaOpcja;
    int iloscOsob = 0;
    KsiazkaTelefoniczna kontakty[1000];
    wczytajKontaktyZpliku(kontakty);
    iloscOsob = ileZapisanychKontaktow(kontakty);
    while(1)
    {
        cout << "==========================================" << endl;
        cout << "========= Ksiazka Telefoniczna ===========" << endl;
        cout << "==========================================" << endl;
        cout << endl << "Menu Glowne" << endl << endl;
        cout << "1. Dodaj nowy kontakt" << endl;
        cout << "2. Edytuj kontakt" << endl;
        cout << "3. Wyszukaj kontaktu" << endl;
        cout << "4. Wszystkie kontakty" << endl;
        cout << "5. Zakoncz program" << endl;
        cout << endl << "Wybierz opcje: ";
        cin >> wybranaOpcja;

        switch(wybranaOpcja)
        {
        case '1':
            iloscOsob = kontakty[iloscOsob].dodajNowyKontakt(kontakty, iloscOsob);
            break;
        case '2':
            kontakty[iloscOsob].edytujKontakt(kontakty, iloscOsob);
            break;
        case '3':
            kontakty[iloscOsob].wyszukajKontaktu(kontakty, iloscOsob);
            break;
        case '4':
            kontakty[iloscOsob].wypiszWszystkieKontakty(kontakty, iloscOsob);
            break;
        case '5':
            exit(0);
            break;
        default:
            cout << "Wybrana opcja nieistnieje. Wybierz jenda z opcji w menu." << endl;
            Sleep(2000);
        }
        system("cls");
    }
    return 0;
}

void wczytajKontaktyZpliku(KsiazkaTelefoniczna kontakty[])
{
    fstream plikZKontaktami;
    plikZKontaktami.open("kontakty.txt", ios::in);

    if (plikZKontaktami.good() == false)
    {
        cout << "Nie udalo sie otworzyc pliku!" << endl;
        exit(0);
    }

    string linia;
    int aktualnyNrLini = 1;
    int i = 0;
    while (getline(plikZKontaktami, linia))
     {
          switch (aktualnyNrLini)
          {
              case 1: kontakty[i].idOsoby = atoi(linia.c_str()); break;
              case 2: kontakty[i].imie = linia; break;
              case 3: kontakty[i].nazwisko = linia; break;
              case 4: kontakty[i].nrTelefonu = linia; break;
              case 5: kontakty[i].adres = linia; break;
              case 6: kontakty[i].email = linia; break;
          }
          if (aktualnyNrLini >= 6)
          {
              aktualnyNrLini = 1;
              i++;
          }
          else
          {
              aktualnyNrLini++;
          }
     }
    plikZKontaktami.close();
}

int ileZapisanychKontaktow(KsiazkaTelefoniczna kontakty[])
{
    int id = 0;
    int liczbaOsob = 0;
    if (kontakty[id].pobierzIdOsoby() == 0)
    {
        return 0;
    }
    else
    {
        while (kontakty[id].pobierzIdOsoby() != 0)
        {
            liczbaOsob++;
            id++;
        }
    }

    return liczbaOsob;
}
