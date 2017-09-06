#include <iostream>
#include "osoba.h"

using namespace std;

class KsiazkaTelefoniczna
{
    int idOsoby;
        string imie;
        string nazwisko;
        string nrTelefonu;
        string adres;
        string email;

    public:
        KsiazkaTelefoniczna(int id = 0, string imie = "brak", string nazwisko = "brak", string nrTelefonu = "0", string adres = "brak", string email ="brak")
        {
            idOsoby = id;
            this->imie = imie;
            this->nazwisko = nazwisko;
            this->nrTelefonu = nrTelefonu;
            this->adres = adres;
            this->email = email;
        }
        ~KsiazkaTelefoniczna(){
            //cout << "Destruktor";
        }
        void ustawIdOsoby(int id);
        void ustawImie();
        void ustawNazwisko();
        void ustawNrTelefonu();
        void ustawAdres();
        void ustawAdresEmail();

        int pobierzIdOsoby();
        string pobierzImie();
        string pobierzNazwisko();
        string pobierzNrTelefonu();
        string pobierzAdres();
        string pobierzAdresEmail();

        void wypiszWprowadzoneDaneOOsobie(KsiazkaTelefoniczna kontakty[], int iloscOsob);
        int dodajNowyKontakt(KsiazkaTelefoniczna kontakty[], int iloscOsob);
        void edytujKontakt(KsiazkaTelefoniczna kontakty[], int iloscOsob);
        void wyszukajKontaktu(KsiazkaTelefoniczna kontakty[], int iloscOsob);
        void wypiszWszystkieKontakty(KsiazkaTelefoniczna kontakty[], int iloscOsob);
        void zapisDoPliku(KsiazkaTelefoniczna kontakty[], int iloscOsob);

        friend void wczytajKontaktyZpliku(KsiazkaTelefoniczna kontakty[]);
};
