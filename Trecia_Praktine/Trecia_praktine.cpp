#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

const int MAX_PREKES = 100;

bool Nuskaitymas(const string& failas, string kategorijos[], string pavadinimai[], double kainos[], int kiekiai[], int& n);
double EilutesSuma(double kaina, int kiekis);
double KategorijosSuma(const string kategorijos[], const double kainos[], const int kiekiai[], int n, const string& kategorija);
void RodytiPrekes(const string kategorijos[], const string pavadinimai[], const double kainos[], const int kiekiai[], int n);
void RodytiSumas(const double kainos[], const int kiekiai[], int n);
void Meniu();

int main()
{
    string kategorijos[MAX_PREKES];
    string pavadinimai[MAX_PREKES];
    double kainos[MAX_PREKES];
    int kiekiai[MAX_PREKES];
    int n = 0;

    if (!Nuskaitymas("uzsakymas.txt", kategorijos, pavadinimai, kainos, kiekiai, n))
    {
        cout << "Nepavyko nuskaityti duomenu." << endl;
        return 1;
    }

    int pasirinkimas;
    do {
        Meniu();
        if (!(cin >> pasirinkimas)) {
            if (cin.eof()) {
                break;
            }
            cin.clear();
            cin.ignore(10000, '\n');
            pasirinkimas = 0;
            cout << "Neteisingas pasirinkimas. Bandykite dar kartą." << endl;
            continue;
        }

        if (pasirinkimas == 1)
        {
            RodytiPrekes(kategorijos, pavadinimai, kainos, kiekiai, n);
        }
        else if (pasirinkimas == 2)
        {
            RodytiSumas(kainos, kiekiai, n);
        }
        else if (pasirinkimas == 3)
        {
            const string kategorijuPavadinimai[] = {"Dviraciai", "Dalys", "Aksesuarai"};
            cout << "Kategoriju sumos:" << endl;
            for (int i = 0; i < 3; i++)
            {
                cout << kategorijuPavadinimai[i] << ": "
                     << KategorijosSuma(kategorijos, kainos, kiekiai, n, kategorijuPavadinimai[i]) << endl;
            }
        }
        else if (pasirinkimas == 4)
        {
            cout << "" << endl;
        }
        else if (pasirinkimas == 5)
        {
            cout << "" << endl;
        }
        else if (pasirinkimas < 1 || pasirinkimas > 6)
        {
            cout << "" << endl;
        }
    } while (pasirinkimas != 6);
    cout << "Programa baigiama." << endl;
    return 0;
}

bool Nuskaitymas(const string& failas, string kategorijos[], string pavadinimai[], double kainos[], int kiekiai[], int& n)
{
    ifstream in(failas);
    if (!in || !(in >> n) || n < 1 || n > MAX_PREKES)
        return false;

    string eilute;
    getline(in, eilute);
    for (int i = 0; i < n; i++)
    {
        char skirtukas;
        if (!getline(in, kategorijos[i], ';') ||
            !getline(in, pavadinimai[i], ';') ||
            !(in >> kainos[i]) ||
            !in.get(skirtukas) || skirtukas != ';' ||
            !(in >> kiekiai[i]))
            return false;

        getline(in, eilute);
    }
    return true;
}
void RodytiPrekes(const string kategorijos[], const string pavadinimai[], const double kainos[], const int kiekiai[], int n) {
    cout << left << setw(15) << "Kategorija" << setw(20) << "Pavadinimas" << setw(10) << "Kaina" << setw(10) << "Kiekis" << endl;
    cout << string(55, '-') << endl;

    for (int i = 0; i < n; i++)
    {
        cout << left << setw(15) << kategorijos[i]
             << setw(30) << pavadinimai[i]
             << setw(10) << fixed << setprecision(2) << kainos[i]
             << setw(10) << kiekiai[i] << endl;
    }
}
void RodytiSumas(const double kainos[], const int kiekiai[], int n)
{
    double suma = 0.0;

    for (int i = 0; i < n; i++)
    {
        suma += EilutesSuma(kainos[i], kiekiai[i]);
    }

    cout << "Bendra suma: " << fixed << setprecision(2) << suma << endl;
}

void Meniu()
{
    cout << "\nPasirinkite veiksmą:\n"
         << "1. Rodyti prekes\n"
         << "2. Rodyti sumas\n"
         << "3. Rodyti kategorijų sumas\n"
         << "4. Ataskaita\n"
         << "5. Ataskaitos saugojimas\n"
         << "6. Baigti programą\n"
         << "Jūsų pasirinkimas: ";
}
double KategorijosSuma(const string kategorijos[], const double kainos[], const int kiekiai[], int n, const string& kategorija)
{
    double suma = 0.0;

    for (int i = 0; i < n; i++)
    {
        if (kategorijos[i] == kategorija)
        {
            suma += EilutesSuma(kainos[i], kiekiai[i]);
        }
    }

    return suma;
}
double EilutesSuma(double kaina, int kiekis)
{
    return kaina * kiekis;
}