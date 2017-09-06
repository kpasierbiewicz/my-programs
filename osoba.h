#include <string>
#include <iostream>

using namespace std;

class Osoba
{
    private:
        int idOsoby;
        string imie;
        string nazwisko;
        string nrTelefonu;
        string adres;

    public:
        Osoba(int id = 0, string imie = "brak", string nazwisko = "brak", string nrTelefonu = "0", string adres = "brak")
        {
            idOsoby = id;
            this->imie = imie;
            this->nazwisko = nazwisko;
            this->nrTelefonu = nrTelefonu;
            this->adres = adres;
        }
        ~Osoba(){
            //cout << "Destruktor";
        }
        void ustawIdOsoby(int id);
        void ustawImie();
        void ustawNazwisko();
        void ustawNrTelefonu();
        void ustawAdres();

        int pobierzIdOsoby();
        string pobierzImie();
        string pobierzNazwisko();
        string pobierzNrTelefonu();
        string pobierzAdres();

        void wypiszWprowadzoneDaneOOsobie();
};
