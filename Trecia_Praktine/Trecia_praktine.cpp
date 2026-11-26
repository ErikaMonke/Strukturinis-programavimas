#include <iostream>
#include <fstream>
#include <iomanip>
#include <sstream>
#include <string>

using namespace std;

const int MAX_PREKES = 100;
// Tas pats kategoriju sarasas naudojamas tikrinant faila, renkantis kategorija ir isvedant sumas.
const string KATEGORIJOS[] = {"Dviraciai", "Dalys", "Aksesuarai"};
const int KATEGORIJU_KIEKIS = 3;

bool Nuskaitymas(const string& failoPavadinimas, string kategorijos[], string pavadinimai[], double kainos[], int kiekiai[], int& prekiuSkaicius);
bool KategorijaTeisinga(const string& kategorija);
double EilutesSuma(double kaina, int kiekis);
double Nuolaida(double eilutesSuma, int kiekis);
double KategorijosSuma(const string kategorijos[], const double kainos[], const int kiekiai[], int prekiuSkaicius, const string& ieskomaKategorija);
double SumaPriesNuolaidas(const double kainos[], const int kiekiai[], int prekiuSkaicius);
double BendraNuolaida(const double kainos[], const int kiekiai[], int prekiuSkaicius);
void IsvestiPrekes(ostream& isvestis, const string kategorijos[], const string pavadinimai[], const double kainos[], const int kiekiai[], int prekiuSkaicius, const string& filtruojamaKategorija);
void IsvestiSumas(ostream& isvestis, const double kainos[], const int kiekiai[], int prekiuSkaicius);
void IsvestiAtaskaita(ostream& isvestis, const string kategorijos[], const string pavadinimai[], const double kainos[], const int kiekiai[], int prekiuSkaicius);
bool NuskaitytiPasirinkima(int& pasirinkimas);
bool PasirinktiKategorija(string& kategorija);
void IsvestiMeniu();

int main()
{
    // Kiekvieno masyvo elementai tuo paciu indeksu priklauso tai paciai prekei.
    string kategorijos[MAX_PREKES];
    string pavadinimai[MAX_PREKES];
    double kainos[MAX_PREKES];
    int kiekiai[MAX_PREKES];
    int prekiuSkaicius = 0;

    // Nuskaitymas uzpildo masyvus is failo; jei nepavyksta, meniu neturi ka rodyti.
    if (!Nuskaitymas("uzsakymas.txt", kategorijos, pavadinimai, kainos, kiekiai, prekiuSkaicius)) {
        return 1;
    }

    int pasirinkimas;
    while (true) {
        IsvestiMeniu();
        // Visa eilute tikrinama kaip skaicius; EOF atveju programa uzdaroma, o neteisinga eilute atmetama.
        if (!NuskaitytiPasirinkima(pasirinkimas)) {
            if (cin.eof()) {
                cout << "\nIvestis baigta. Programa baigiama." << endl;
                return 0;
            }
            cout << "Neteisingas pasirinkimas. Iveskite skaiciu nuo 1 iki 7." << endl;
            continue;
        }

        if (pasirinkimas < 1 || pasirinkimas > 7) {
            cout << "Neteisingas pasirinkimas. Iveskite skaiciu nuo 1 iki 7." << endl;
        }

        else if (pasirinkimas == 1) {
            IsvestiPrekes(cout, kategorijos, pavadinimai, kainos, kiekiai, prekiuSkaicius, "");
        }

        else if (pasirinkimas == 2) {
            string kategorija;
            if (!PasirinktiKategorija(kategorija)) {
                if (cin.eof()) {
                    cout << "\nIvestis baigta. Programa baigiama." << endl;
                    return 0;
                }
                continue;
            }

            IsvestiPrekes(cout, kategorijos, pavadinimai, kainos, kiekiai, prekiuSkaicius, kategorija);
            cout << "Kategorijos \"" << kategorija << "\" moketina suma: "
                 << fixed << setprecision(2)
                 << KategorijosSuma(kategorijos, kainos, kiekiai, prekiuSkaicius, kategorija)
                 << " Eur" << endl;
        }
        else if (pasirinkimas == 3) {
            IsvestiSumas(cout, kainos, kiekiai, prekiuSkaicius);
        }
        else if (pasirinkimas == 4) {
            cout << fixed << setprecision(2);
            cout << "\nSumos pagal kategorijas:\n";
            for (int i = 0; i < KATEGORIJU_KIEKIS; ++i) {
                cout << KATEGORIJOS[i] << ": "
                     << KategorijosSuma(kategorijos, kainos, kiekiai, prekiuSkaicius, KATEGORIJOS[i])
                     << " Eur" << endl;
            }
        }
        else if (pasirinkimas == 5) {
            IsvestiAtaskaita(cout, kategorijos, pavadinimai, kainos, kiekiai, prekiuSkaicius);
        }

        else if (pasirinkimas == 6) {
            // Ataskaitos funkcija rasys i failo srauta taip pat, kaip kituose punktuose raso i cout.
            ofstream ataskaita("ataskaita.txt");
            if (!ataskaita) {
                cout << "Nepavyko atidaryti failo ataskaita.txt." << endl;
                continue;
            }

            IsvestiAtaskaita(ataskaita, kategorijos, pavadinimai, kainos, kiekiai, prekiuSkaicius);
            ataskaita.close();
            if (!ataskaita) {
                cout << "Nepavyko irasyti ataskaitos i ataskaita.txt." << endl;
            }
            else {
                cout << "Ataskaita sekmingai issaugota faile ataskaita.txt." << endl;
            }
        }
        else {
            cout << "Programa baigiama." << endl;
            return 0;
        }
    }
}

bool Nuskaitymas(const string& failoPavadinimas, string kategorijos[], string pavadinimai[], double kainos[], int kiekiai[], int& prekiuSkaicius) {
    ifstream failas(failoPavadinimas);

    if (!failas) {
        cout << "Nepavyko atidaryti duomenu failo " << failoPavadinimas << "." << endl;
        return false;
    }

    string eilute;

    // Pirma eilute nurodo irasu skaiciu; riba saugo nuo tuscio uzsakymo ir masyvu perpildymo.
    if (!(failas >> prekiuSkaicius) || prekiuSkaicius < 1 || prekiuSkaicius > MAX_PREKES) {
        cout << "Irasu skaicius turi buti nuo 1 iki " << MAX_PREKES << "." << endl;
        return false;
    }

    // Skaiciavimo operatorius palieka eilutes pabaiga, todel ja perskaitome ir patikriname, ar po skaiciaus nera papildomo teksto.
    getline(failas, eilute);
    istringstream skaiciausEilute(eilute);
    string papildomiDuomenys;
    if (skaiciausEilute >> papildomiDuomenys) {
        cout << "Netinkamas prekiu irasu skaicius faile." << endl;
        return false;
    }

    for (int i = 0; i < prekiuSkaicius; ++i) {

        if (!getline(failas, eilute)) {
            cout << "Nepavyko nuskaityti " << i + 1 << "-ojo prekes iraso." << endl;
            return false;
        }

        // Viena eilute turi tureti tris kabliataskius, kurie atskiria keturis prekes laukus.
        int skirtukuKiekis = 0;
        for (int j = 0; j < eilute.length(); ++j) {
            if (eilute[j] == ';') {
                ++skirtukuKiekis;
            }
        }
        if (skirtukuKiekis != 3) {
            cout << "Netinkamas " << i + 1 << "-ojo prekes iraso formatas." << endl;
            return false;
        }

        // Is eilutes laukai atskiriami pagal ';', todel prekes pavadinime gali buti tarpu.
        istringstream prekesSrautas(eilute);
        string kainosTekstas, kiekioTekstas;
        if (!getline(prekesSrautas, kategorijos[i], ';') || !getline(prekesSrautas, pavadinimai[i], ';') || !getline(prekesSrautas, kainosTekstas, ';') || !getline(prekesSrautas, kiekioTekstas)) {
            cout << "Nepavyko nuskaityti " << i + 1 << "-ojo prekes iraso." << endl;
            return false;
        }

        if (!KategorijaTeisinga(kategorijos[i])) {
            cout << "Neatpazinta kategorija " << i + 1 << "-ajame prekes irase." << endl;
            return false;
        }
        if (pavadinimai[i].empty()) {
            cout << "Tuscias prekes pavadinimas " << i + 1 << "-ajame irase." << endl;
            return false;
        }

        // Atskiras srautas patikrina, ar kainos lauke yra tik teigiama skaiciaus reiksme.
        istringstream kainosSrautas(kainosTekstas);
        if (!(kainosSrautas >> kainos[i]) || !(kainos[i] > 0)) {
            cout << "Netinkama vieneto kaina " << i + 1 << "-ajame prekes irase." << endl;
            return false;
        }
        // ws praleidzia gale esancius tarpus, o eof patikrina, ar neliko kitu simboliu.
        kainosSrautas >> ws;
        if (!kainosSrautas.eof()) {
            cout << "Netinkama vieneto kaina " << i + 1 << "-ajame prekes irase." << endl;
            return false;
        }

        // Kiekis tikrinamas atskirai, nes jis turi buti teigiamas sveikasis skaicius.
        istringstream kiekioSrautas(kiekioTekstas);
        if (!(kiekioSrautas >> kiekiai[i]) || kiekiai[i] <= 0) {
            cout << "Netinkamas kiekis " << i + 1 << "-ajame prekes irase." << endl;
            return false;
        }
        // Kaip ir kainos atveju, po skaiciaus leidziami tik tarpai, ne papildomas tekstas.
        kiekioSrautas >> ws;
        if (!kiekioSrautas.eof()) {
            cout << "Netinkamas kiekis " << i + 1 << "-ajame prekes irase." << endl;
            return false;
        }
    }

    // Patikrina, ar faile nera daugiau duomenu eiluciu nei nurode pirmasis skaicius.
    while (getline(failas, eilute)) {
        istringstream papildomuDuomenuSrautas(eilute);
        if (papildomuDuomenuSrautas >> papildomiDuomenys) {
            cout << "Duomenu faile yra daugiau irasu, nei nurodyta." << endl;
            return false;
        }
    }

    // bad() pazymi rimta skaitymo klaida; iprasta failo pabaiga nera klaida.
    if (failas.bad()) {
        cout << "Klaida skaitant duomenu faila." << endl;
        return false;
    }

    return true;
}

bool KategorijaTeisinga(const string& kategorija) {
    // Pereina per bendra kategoriju sarasa ir grazina true radusi sutapima.
    for (int i = 0; i < KATEGORIJU_KIEKIS; ++i) {
        if (kategorija == KATEGORIJOS[i]) {
            return true;
        }
    }
    return false;
}

double EilutesSuma(double kaina, int kiekis) {
    return kaina * kiekis;
}

double Nuolaida(double eilutesSuma, int kiekis) {
    // Nuolaida taikoma vienai prekes eilutei, kai jos kiekis yra bent 10 vienetu.
    if (kiekis >= 10) {
        return eilutesSuma * 0.10;
    }
    return 0.0;
}

double KategorijosSuma(const string kategorijos[], const double kainos[], const int kiekiai[], int prekiuSkaicius, const string& ieskomaKategorija) {
    double suma = 0.0;
    // Skaiciuojamos tik pasirinktos kategorijos eilutes; is kiekvienos atimama jos nuolaida.
    for (int i = 0; i < prekiuSkaicius; ++i) {
        if (kategorijos[i] == ieskomaKategorija) {
            double eilutesSuma = EilutesSuma(kainos[i], kiekiai[i]);
            suma += eilutesSuma - Nuolaida(eilutesSuma, kiekiai[i]);
        }
    }
    return suma;
}

double SumaPriesNuolaidas(const double kainos[], const int kiekiai[], int prekiuSkaicius) {
    double suma = 0.0;
    // Kiekvienos prekes kaina dauginama is kiekio ir pridedama prie pradines sumos.
    for (int i = 0; i < prekiuSkaicius; ++i) {
        suma += EilutesSuma(kainos[i], kiekiai[i]);
    }
    return suma;
}

double BendraNuolaida(const double kainos[], const int kiekiai[], int prekiuSkaicius) {
    double suma = 0.0;
    // Apskaiciuoja kiekvienos prekes nuolaida ir sudeda jas i bendra nuolaidu suma.
    for (int i = 0; i < prekiuSkaicius; ++i) {
        suma += Nuolaida(EilutesSuma(kainos[i], kiekiai[i]), kiekiai[i]);
    }
    return suma;
}

void IsvestiPrekes(ostream& isvestis, const string kategorijos[], const string pavadinimai[], const double kainos[], const int kiekiai[], int prekiuSkaicius, const string& filtruojamaKategorija) {
    // ostream leidzia ta pacia funkcija naudoti ir ekranui (cout), ir ataskaitos failui.
    int rastuPrekiu = 0;
    isvestis << fixed << setprecision(2);
    // setw sulygiuoja lentele, o fixed ir setprecision(2) rodo kainas dviem skaitmenimis po kablelio.
    isvestis << " " << string(151, '-');
    isvestis << "\n" << " | "
             << left << setw(15) << "Kategorija" << " | "
             << setw(48) << "Prekes pavadinimas" << " | "
             << right << setw(12) << "Kaina (Eur)" << " | "
             << setw(8) << "Kiekis" << " | "
             << setw(16) << "Suma (Eur)" << " | "
             << setw(14) << "Nuolaida (Eur)" << " | "
             << setw(16) << "Moketina (Eur)"  << " | " << endl;
    isvestis << " " << string(151, '-') << endl;

    // Tuscias filtras reiskia visas prekes; kitu atveju praleidziamos kitoms kategorijoms priklausancios prekes.
    for (int i = 0; i < prekiuSkaicius; ++i) {
        if (filtruojamaKategorija.empty() ||
            kategorijos[i] == filtruojamaKategorija) {
            // Moketina eilutes suma lygi kainai * kiekiui minus tai eilutei pritaikyta nuolaida.
            double eilutesSuma = EilutesSuma(kainos[i], kiekiai[i]);
            double nuolaida = Nuolaida(eilutesSuma, kiekiai[i]);
            isvestis  << " | " << left << setw(15) << kategorijos[i]  << " | "
                     << setw(48) << pavadinimai[i]  << " | "
                     << right << setw(12) << kainos[i]  << " | "
                     << setw(8) << kiekiai[i]  << " | "
                     << setw(16) << eilutesSuma  << " | "
                     << setw(14) << nuolaida  << " | "
                     << setw(16) << eilutesSuma - nuolaida  << " | " << endl;
            ++rastuPrekiu;
        }
    }
    isvestis << " " << string(151, '-') << endl;

    if (rastuPrekiu == 0) {
        isvestis << "Kategorijoje \"" << filtruojamaKategorija << "\" prekiu nera." << endl;
    }
}

void IsvestiSumas(ostream& isvestis, const double kainos[], const int kiekiai[], int prekiuSkaicius) {
    double sumaPriesNuolaidas = SumaPriesNuolaidas(kainos, kiekiai, prekiuSkaicius);
    double nuolaida = BendraNuolaida(kainos, kiekiai, prekiuSkaicius);
    isvestis << fixed << setprecision(2);
    isvestis << "\nSuma pries nuolaidas: " << sumaPriesNuolaidas << " Eur" << endl;
    isvestis << "Bendra nuolaidu suma: " << nuolaida << " Eur" << endl;
    isvestis << "Galutine moketina suma: " << sumaPriesNuolaidas - nuolaida << " Eur" << endl;
}

void IsvestiAtaskaita(ostream& isvestis, const string kategorijos[], const string pavadinimai[], const double kainos[], const int kiekiai[], int prekiuSkaicius) {
    // Ataskaita sudaroma pakartotinai naudojant prekiu lentele, bendra suma ir kategoriju sumas.
    isvestis << "DVIRACIU PARDUOTUVES UZSAKYMO ATASKAITA\n";
    IsvestiPrekes(isvestis, kategorijos, pavadinimai, kainos, kiekiai, prekiuSkaicius, "");
    IsvestiSumas(isvestis, kainos, kiekiai, prekiuSkaicius);

    isvestis << "\nMoketinos sumos pagal kategorijas:\n";
    isvestis << fixed << setprecision(2);
    for (int i = 0; i < KATEGORIJU_KIEKIS; ++i) {
        isvestis << KATEGORIJOS[i] << ": "
                 << KategorijosSuma(kategorijos, kainos, kiekiai, prekiuSkaicius, KATEGORIJOS[i])
                 << " Eur" << endl;
    }
}

bool NuskaitytiPasirinkima(int& pasirinkimas) {
    string eilute;
    // getline perskaito visa eilute, kad butu galima atmesti ivesti su papildomais simboliais.
    if (!getline(cin, eilute)) {
        return false;
    }

    // Pirmiausia nuskaitomas skaicius, tada tikrinama, ar sraute liko dar koks nors ne tarpo simbolis.
    istringstream srautas(eilute);
    char papildomasZenklas; // Sulaiko galima simboli po skaiciaus, kad ji butu galima atmesti.
    if (!(srautas >> pasirinkimas) || (srautas >> papildomasZenklas)) {
        return false;
    }
    return true;
}

bool PasirinktiKategorija(string& kategorija) {
    int pasirinkimas;

    while (true) {
        cout << "\nPasirinkite kategorija:\n";
        for (int i = 0; i < KATEGORIJU_KIEKIS; ++i) {
            cout << i + 1 << ". " << KATEGORIJOS[i] << endl;
        }
        cout << "Jusu pasirinkimas: ";
        if (!NuskaitytiPasirinkima(pasirinkimas)) {
            if (cin.eof()) {
                return false;
            }
            cout << "Neteisingas pasirinkimas. Iveskite skaiciu nuo 1 iki "
                 << KATEGORIJU_KIEKIS << "." << endl;
            continue;
        }

        // Meniu numeriai prasideda nuo 1, o masyvo indeksai nuo 0, todel atimamas vienetas.
        if (pasirinkimas >= 1 && pasirinkimas <= KATEGORIJU_KIEKIS) {
            kategorija = KATEGORIJOS[pasirinkimas - 1];
            return true;
        }
        cout << "Neteisingas pasirinkimas. Iveskite skaiciu nuo 1 iki "
             << KATEGORIJU_KIEKIS << "." << endl;
    }
}

void IsvestiMeniu() {
    cout << "\n--- Dviraciu parduotuves uzsakymo skaiciuokle ---\n"
         << "1. Perziureti visas uzsakymo prekes\n"
         << "2. Perziureti pasirinktos kategorijos prekes\n"
         << "3. Perziureti viso uzsakymo sumas\n"
         << "4. Perziureti sumas pagal kategorijas\n"
         << "5. Parodyti visa uzsakymo ataskaita\n"
         << "6. Issaugoti ataskaita i faila\n"
         << "7. Iseiti\n"
         << "Jusu pasirinkimas: ";
}
