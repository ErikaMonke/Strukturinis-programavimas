#include <iostream>
#include <fstream>
#include <string>

using namespace std;

const int MAX_PREKES = 100;

bool Nuskaitymas(const string& failoVardas, string kategorijos[], string pavadinimai[], double kainos[], int kiekiai[], int& kiekis);
void IsvedimasEkranas(const string kategorijos[], const string pavadinimai[], const double kainos[], const int kiekiai[], int kiekis);
void Ataskaita(const string& failoVardas, const string kategorijos[], const string pavadinimai[], const double kainos[], const int kiekiai[], int kiekis);

int main()
{
    string kategorijos[MAX_PREKES], pavadinimai[MAX_PREKES];
    double kainos[MAX_PREKES];
    int kiekiai[MAX_PREKES];
    int kiekis = 0;

    if (!Nuskaitymas("uzsakymas.txt", kategorijos, pavadinimai, kainos, kiekiai, kiekis)) {
        return 1;
    }
    IsvedimasEkranas(kategorijos, pavadinimai, kainos, kiekiai, kiekis);
    IsvedimasFailas("rezultatai.txt", kategorijos, pavadinimai, kainos, kiekiai, kiekis);

    return 0;
}

bool Nuskaitymas(const string& failoVardas, string kategorijos[], string pavadinimai[], double kainos[], int kiekiai[], int& kiekis)
{
    ifstream failas(failoVardas);
    if (!failas) {
        cerr << "Nepavyko atidaryti failo: " << failoVardas << endl;
        return false;
    }

    failas >> kiekis;
    failas.ignore();

    for (int i = 0; i < kiekis; ++i) {
        getline(failas, kategorijos[i], ';');
        getline(failas, pavadinimai[i], ';');
        failas >> kainos[i];
        failas.ignore();
        failas >> kiekiai[i];
        failas.ignore();
    }

    return true;
}

void IsvedimasEkranas(const string kategorijos[], const string pavadinimai[], const double kainos[], const int kiekiai[], int kiekis)
{
    cout << "Kategorija\nPavadinimas\nKaina\nKiekis" << endl;
    for (int i = 0; i < kiekis; ++i) {
        cout << kategorijos[i] << "\n" << pavadinimai[i] << "\n" << kainos[i] << "\n" << kiekiai[i] << endl;
    }
}

void IsvedimasFailas(const string& failoVardas, const string kategorijos[], const string pavadinimai[], const double kainos[], const int kiekiai[], int kiekis)
{
    ofstream failas(failoVardas);
    if (!failas) {
        cerr << "Nepavyko sukurti failo: " << failoVardas << endl;
        return;
    }

    failas << "Kategorija\nPavadinimas\nKaina\nKiekis" << endl;
    for (int i = 0; i < kiekis; ++i) {
        failas << kategorijos[i] << "\n" << pavadinimai[i] << "\n" << kainos[i] << "\n" << kiekiai[i] << endl;
    }
}