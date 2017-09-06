#include "ksiazkaTel.h"
#include <iostream>
#include <string>
#include <windows.h>
#include <cstdio>
#include <fstream>
#include <cstdlib>

using namespace std;


void KsiazkaTelefoniczna::ustawIdOsoby(int id)
{
    idOsoby = id;
}

void KsiazkaTelefoniczna::ustawImie()
{
    do
    {
        cout << "Podaj imie: ";
        cin >> imie;
    }
    while(cin.good() != true);

}

void KsiazkaTelefoniczna::ustawNazwisko()
{
    do
    {
        cout << "Podaj nazwisko: ";
        cin >> nazwisko;
    }
    while(cin.good() != true);
}

void KsiazkaTelefoniczna::ustawNrTelefonu()
{
    do
    {
        cout << "Podaj numer telefonu: ";
        cin.sync();
        getline(cin, nrTelefonu);
    }
    while(cin.good() != true);
}

void KsiazkaTelefoniczna::ustawAdres()
{

    cout << "Podaj adres zamieszkania: ";
    cin.sync();
    getline(cin, adres);
}

void KsiazkaTelefoniczna::ustawAdresEmail()
{
    do
    {
        cout << "Podaj adres e-mail: ";
        cin >> email;
    }
    while(cin.good() != true);
}

int KsiazkaTelefoniczna::pobierzIdOsoby()
{
    return idOsoby;
}

string KsiazkaTelefoniczna::pobierzImie()
{
    return imie;
}

string KsiazkaTelefoniczna::pobierzNazwisko()
{
    return nazwisko;
}

string KsiazkaTelefoniczna::pobierzNrTelefonu()
{
    return nrTelefonu;
}

string KsiazkaTelefoniczna::pobierzAdres()
{
    return adres;
}

string KsiazkaTelefoniczna::pobierzAdresEmail()
{
    return email;
}

void KsiazkaTelefoniczna::wypiszWprowadzoneDaneOOsobie(KsiazkaTelefoniczna kontakty[], int iloscOsob)
{
    if (kontakty[iloscOsob].idOsoby != 0)
    {
        cout << "ID: " << kontakty[iloscOsob].idOsoby << endl << kontakty[iloscOsob].imie << endl << kontakty[iloscOsob].nazwisko << endl << "tel." << kontakty[iloscOsob].nrTelefonu << endl << "adres zamieszkania: "
             << kontakty[iloscOsob].adres << endl << "e-mail: "<< kontakty[iloscOsob].email<< endl
             << "------------------------------------------" << endl;
    }
}

int KsiazkaTelefoniczna::dodajNowyKontakt(KsiazkaTelefoniczna kontakty[], int iloscOsob)
{
    fstream plikZKontaktami;
    plikZKontaktami.open("kontakty.txt", ios::out | ios::app);
    if (plikZKontaktami.good() == false)
    {
        cout << "Nie udalo sie otworzyc pliku!" << endl;
        exit(0);
    }

    kontakty[iloscOsob].ustawIdOsoby(iloscOsob + 1);
    kontakty[iloscOsob].ustawImie();
    kontakty[iloscOsob].ustawNazwisko();
    kontakty[iloscOsob].ustawNrTelefonu();
    kontakty[iloscOsob].ustawAdres();
    kontakty[iloscOsob].ustawAdresEmail();

    int i = 0;
    while (i < iloscOsob)
    {
        if ( kontakty[i].pobierzNrTelefonu() == kontakty[iloscOsob].pobierzNrTelefonu() && kontakty[i].pobierzAdres() == kontakty[iloscOsob].pobierzAdres() && kontakty[i].pobierzAdresEmail() == kontakty[iloscOsob].pobierzAdresEmail())
        {
            cout << "\nPodana osoba juz istnieje w bazie." << endl;
            KsiazkaTelefoniczna::wypiszWprowadzoneDaneOOsobie(kontakty, iloscOsob);
            cout << "Aby kotynuowac wcisnij dowony klawisz" << endl;
            system("pause");
            return iloscOsob;
        }
        i++;
    }

    plikZKontaktami << kontakty[iloscOsob].idOsoby << endl;
    plikZKontaktami << kontakty[iloscOsob].imie << endl;
    plikZKontaktami << kontakty[iloscOsob].nazwisko << endl;
    plikZKontaktami << kontakty[iloscOsob].nrTelefonu << endl;
    plikZKontaktami << kontakty[iloscOsob].adres << endl;
    plikZKontaktami << kontakty[iloscOsob].email << endl;

    cout << "Kontakt zostal dodany." << endl;
    Sleep(2000);
    plikZKontaktami.close();
    return kontakty[iloscOsob].pobierzIdOsoby();
}

void KsiazkaTelefoniczna::edytujKontakt(KsiazkaTelefoniczna kontakty[], int iloscOsob)
{
    string imie;
    string nazwisko;

    cout << "Podaj imie: ";
    cin >> imie;

    cout << "Podaj nazwisko: ";
    cin >> nazwisko;

    int tabelaZnalezionychKontaktow[10] = {0};
    int iloscZnalezionychKontakow = 0;
    for (int i = 0; i < iloscOsob; i++)
    {
        if (kontakty[i].imie == imie && kontakty[i].nazwisko == nazwisko)
        {
            tabelaZnalezionychKontaktow[iloscZnalezionychKontakow] = i;
            iloscZnalezionychKontakow++;
        }
    }

    if (iloscZnalezionychKontakow > 0)
    {
        cout << "Kontakty znalezione:" << endl;
        for (int i = 0; i < iloscZnalezionychKontakow; i++)
        {
            KsiazkaTelefoniczna::wypiszWprowadzoneDaneOOsobie(kontakty, tabelaZnalezionychKontaktow[i]);
        }

        int pozycjaZListy;
        cout << endl << endl;
        cout << "Ktory kontakt edytowac. Podaj ID osoby: ";
        cin >> pozycjaZListy;

        pozycjaZListy = pozycjaZListy - 1;
        cout << endl << endl;
        cout << "============================" << endl;
        cout << "=======OPCJE EDYCJI=========" << endl;
        cout << "============================" << endl;
        cout << endl;

        cout << "a) " << "Edytuj imie" << endl;
        cout << "b) " << "Edytuj nazwisko" << endl;
        cout << "c) " << "Edytuj numer telefonu" << endl;
        cout << "d) " << "Edytuj adres zamieszkoania" << endl;
        cout << "e) " << "Edytuj adres e-mail" << endl;
        cout << "f) " << "Usun kontak" << endl;
        cout << "g) " << "Zakoncz program" << endl;

        char wyborEdycji;
        cout << "Wybor opcji: ";
        cin >> wyborEdycji;
        switch (wyborEdycji)
        {
        case 'a':
        {
            kontakty[pozycjaZListy].KsiazkaTelefoniczna::ustawImie();
            cout << "Zmianny zostaly zapisane" << endl;
            Sleep(1500);
        }

        break;
        case 'b':
        {
            kontakty[pozycjaZListy].KsiazkaTelefoniczna::ustawNazwisko();
            cout << "Zmianny zostaly zapisane" << endl;
            Sleep(1500);
        }

        break;
        case 'c':
        {
            kontakty[pozycjaZListy].KsiazkaTelefoniczna::ustawNrTelefonu();
            cout << "Zmianny zostaly zapisane" << endl;
            Sleep(1500);
        }

        break;
        case 'd':
        {
            kontakty[pozycjaZListy].KsiazkaTelefoniczna::ustawAdres();
            cout << "Zmianny zostaly zapisane" << endl;
            Sleep(1500);
        }

        break;
        case 'e':
        {
            kontakty[pozycjaZListy].KsiazkaTelefoniczna::ustawAdresEmail();
            cout << "Zmianny zostaly zapisane" << endl;
            Sleep(1500);
        }

        break;
        case 'f':
        {
            for(int i = pozycjaZListy; i < iloscOsob; i++)
            {
                kontakty[i].KsiazkaTelefoniczna::imie = kontakty[i+1].KsiazkaTelefoniczna::imie;
                kontakty[i].KsiazkaTelefoniczna::nazwisko = kontakty[i+1].KsiazkaTelefoniczna::nazwisko;
                kontakty[i].KsiazkaTelefoniczna::nrTelefonu = kontakty[i+1].KsiazkaTelefoniczna::nrTelefonu;
                kontakty[i].KsiazkaTelefoniczna::adres = kontakty[i+1].KsiazkaTelefoniczna::adres;
                kontakty[i].KsiazkaTelefoniczna::email = kontakty[i+1].KsiazkaTelefoniczna::email;

            }
            KsiazkaTelefoniczna::zapisDoPliku(kontakty, iloscOsob);
            cout << "Zmianny zostaly zapisane" << endl;
            Sleep(1500);
        }
        break;
        case 'g':
        {
            KsiazkaTelefoniczna::zapisDoPliku(kontakty, iloscOsob);
            cout << "Zmianny zostaly zapisane" << endl;
            Sleep(1500);
            exit(0);
        }

        break;
        default:
        {
            cout << "Nie ma takiej opcji na liscie." << endl;
            Sleep(1500);
        }

        }
        KsiazkaTelefoniczna::zapisDoPliku(kontakty, iloscOsob);
    }
    else
    {

        cout << "Brak danych o osobie.";
        Sleep(2000);
    }

}

void  KsiazkaTelefoniczna::wyszukajKontaktu(KsiazkaTelefoniczna kontakty[], int iloscOsob)
{
    string imie;
    string nazwisko;
    char wybranaOpcjaSzukania;
    char z;

    cout << endl << endl;
    cout << "============================" << endl;
    cout << "=======OPCJE WYSZUKIWANIA=========" << endl;
    cout << "============================" << endl;
    cout << endl;

    cout << "1. Szukaj po imieniu" << endl;
    cout << "2. Szukaj po nazwisku" << endl;

    cout << endl << "Wybor opcji: ";
    cin >> wybranaOpcjaSzukania;

    switch (wybranaOpcjaSzukania)
    {
    case '1':
    {
        cout << "Podaj imie: ";
        cin >> imie;
        int trafienia = 0;
        for (int i = 0; i < iloscOsob; i++)
        {
            if (kontakty[i].imie == imie)
            {
                KsiazkaTelefoniczna::wypiszWprowadzoneDaneOOsobie(kontakty, i);
                trafienia++;
            }
        }
        if (trafienia == 0)
        {
            cout << "Brak danych o osobie." << endl;
        }
        cout << "Jesli chcesz kontynuowac wcisnij dowolny klawisz i enter." << endl;
        cin >> z;
    }
    break;
    case '2':
    {
        cout << "Podaj nazwisko: ";
        cin >> nazwisko;
        int trafienia = 0;
        for (int i = 0; i < iloscOsob; i++)
        {
            if (kontakty[i].nazwisko == nazwisko)
            {
                KsiazkaTelefoniczna::wypiszWprowadzoneDaneOOsobie(kontakty, i);
                trafienia++;
            }
        }

        if (trafienia == 0)
        {
            cout << "Brak danych o osobie." << endl;
        }
        cout << "Jesli chcesz kontynuowac wcisnij dowolny klawisz i enter." << endl;
        cin >> z;
    }
    break;
    default:
        cout << "Nie ma takiej opcji" << endl;
    }
}

void KsiazkaTelefoniczna::wypiszWszystkieKontakty(KsiazkaTelefoniczna kontakty[], int iloscOsob)
{
    cout << endl << endl;
    cout << "============================" << endl;
    cout << "========= Kontakty =========" << endl;
    cout << "============================" << endl;
    cout << endl << endl;

    for (int i = 0; i < iloscOsob; i++)
    {

        KsiazkaTelefoniczna::wypiszWprowadzoneDaneOOsobie(kontakty, i);

    }
    system("pause");
}

void KsiazkaTelefoniczna::zapisDoPliku(KsiazkaTelefoniczna kontakty[], int iloscOsob)
{
    fstream plikZKontaktami;
    plikZKontaktami.clear();
    plikZKontaktami.open("kontakty.txt", ios::out | ios::trunc);

    if (plikZKontaktami.good() == false)
    {
        cout << "Nie udalo sie otworzyc pliku!" << endl;
        exit(0);
    }

    for (int i = 0; i < iloscOsob; i++)
    {
        plikZKontaktami << kontakty[i].idOsoby << endl;
        plikZKontaktami << kontakty[i].imie << endl;
        plikZKontaktami << kontakty[i].nazwisko << endl;
        plikZKontaktami << kontakty[i].nrTelefonu << endl;
        plikZKontaktami << kontakty[i].adres << endl;
        plikZKontaktami << kontakty[i].email << endl;
    }
    plikZKontaktami.close();
}
