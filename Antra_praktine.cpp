#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

const int MAX_MOKINIU = 100;
const int MAX_PAZYMIU = 10;
int skaitytiSkaiciu(int nuo, int iki);
int skaitytiMokinioNumeri(int mokiniuSkaicius);
void rodytiMokini(string vardai[], int pazymiai[][MAX_PAZYMIU], int pazymiuKiekiai[], int numeris);

int main() {

    string vardai[MAX_MOKINIU];
    int pazymiai[MAX_MOKINIU][MAX_PAZYMIU] = {};
    int pazymiuKiekiai[MAX_MOKINIU] = {};
    int mokiniuSkaicius = 0;
    int pasirinkimas;

    do {
        cout << "MOKINIU PAZYMIU SISTEMA" << endl;
        cout << "1. Ivesti mokini ir jo pazymius" << endl;
        cout << "2. Perziureti visu mokiniu pazymius" << endl;
        cout << "3. Perziureti konkretaus mokinio pazymius" << endl;
        cout << "4. Atnaujinti pazymi" << endl;
        cout << "5. Apskaiciuoti mokinio vidurki" << endl;
        cout << "6. Pasalinti mokini" << endl;
        cout << "7. Iseiti" << endl;
        cout << "Pasirinkite veiksma: " << endl;

        pasirinkimas = skaitytiSkaiciu(1, 7);

        if (pasirinkimas == 1) {
            if (mokiniuSkaicius == MAX_MOKINIU) {
                cout << "Mokiniu limitas pasiektas.\n";
            }
            else {
                cin.ignore(numeric_limits<streamsize>::max(), '\n');

                cout << "Iveskite mokinio varda: ";
                getline(cin, vardai[mokiniuSkaicius]);

                while (vardai[mokiniuSkaicius].empty()) {
                    cout << "Vardas negali buti tuscias. Iveskite varda: ";
                    getline(cin, vardai[mokiniuSkaicius]);
                }

                cout << "Kiek pazymiu norite ivesti (0-10)? ";
                pazymiuKiekiai[mokiniuSkaicius] = skaitytiSkaiciu(0, 10);

                for (int i = 0; i < pazymiuKiekiai[mokiniuSkaicius]; i++) {
                    cout << "Iveskite " << i + 1 << "-aji pazymi (1-10): ";
                    pazymiai[mokiniuSkaicius][i] = skaitytiSkaiciu(1, 10);
                }

                mokiniuSkaicius++;
                cout << "Mokinys pridetas.\n";
            }
        } else if (pasirinkimas == 2) {
            if (mokiniuSkaicius == 0) {
                cout << "Mokiniu sarasas tuscias.\n";
            }
            else {
                for (int i = 0; i < mokiniuSkaicius; i++) {
                    cout << "\nMokinio numeris: " << i + 1 << "\n";
                    rodytiMokini(vardai, pazymiai, pazymiuKiekiai, i);
                }
            }
        }
        else if (pasirinkimas == 3) {
            if (mokiniuSkaicius == 0) {
                cout << "Mokiniu sarasas tuscias.\n";
            }
            else {
                for (int i = 0; i < mokiniuSkaicius; i++) {
                    cout << i + 1 << ". " << vardai[i] << "\n";
                }

                int mokinioIndeksas = skaitytiMokinioNumeri(mokiniuSkaicius);

                if (mokinioIndeksas != -1) {
                    rodytiMokini(vardai, pazymiai, pazymiuKiekiai,
                                 mokinioIndeksas);
                }
            }
        }
        else if (pasirinkimas == 4) {
            if (mokiniuSkaicius == 0) {
                cout << "Mokiniu sarasas tuscias.\n";
            }
            else {
                for (int i = 0; i < mokiniuSkaicius; i++) {
                    cout << i + 1 << ". " << vardai[i] << "\n";
                }

                int mokinioIndeksas = skaitytiMokinioNumeri(mokiniuSkaicius);

                if (mokinioIndeksas != -1) {
                    if (pazymiuKiekiai[mokinioIndeksas] == 0) {
                        cout << "Sis mokinys pazymiu neturi.\n";
                    }
                    else {
                        cout << "Mokinio pazymiai: ";
                        for (int i = 0; i < pazymiuKiekiai[mokinioIndeksas]; i++) {
                            cout << i + 1 << ". "
                                 << pazymiai[mokinioIndeksas][i] << "  ";
                        }
                        cout << "\n";

                        cout << "Kuri pazymi norite atnaujinti? ";
                        int pazymioNumeris =
                            skaitytiSkaiciu(1, pazymiuKiekiai[mokinioIndeksas]);

                        cout << "Iveskite nauja pazymi (1-10): ";
                        pazymiai[mokinioIndeksas][pazymioNumeris - 1] =
                            skaitytiSkaiciu(1, 10);

                        cout << "Pazymys atnaujintas.\n";
                    }
                }
            }
        }
        else if (pasirinkimas == 5) {
            if (mokiniuSkaicius == 0) {
                cout << "Mokiniu sarasas tuscias.\n";
            }
            else {
                for (int i = 0; i < mokiniuSkaicius; i++) {
                    cout << i + 1 << ". " << vardai[i] << "\n";
                }

                int mokinioIndeksas = skaitytiMokinioNumeri(mokiniuSkaicius);

                if (mokinioIndeksas != -1) {
                    int kiekis = pazymiuKiekiai[mokinioIndeksas];

                    if (kiekis == 0) {
                        cout << "Sis mokinys pazymiu neturi, vidurkio apskaiciuoti negalima.\n";
                    }
                    else {
                        int suma = 0;

                        for (int i = 0; i < kiekis; i++) {
                            suma += pazymiai[mokinioIndeksas][i];
                        }

                        double vidurkis = static_cast<double>(suma) / kiekis;

                        cout << fixed << setprecision(2);
                        cout << vardai[mokinioIndeksas]
                             << " pazymiu vidurkis: " << vidurkis << "\n";
                    }
                }
            }
        }
        else if (pasirinkimas == 6) {
            if (mokiniuSkaicius == 0) {
                cout << "Mokiniu sarasas tuscias.\n";
            }
            else {
                for (int i = 0; i < mokiniuSkaicius; i++) {
                    cout << i + 1 << ". " << vardai[i] << "\n";
                }

                int mokinioIndeksas = skaitytiMokinioNumeri(mokiniuSkaicius);

                if (mokinioIndeksas != -1) {
                    for (int i = mokinioIndeksas; i < mokiniuSkaicius - 1; i++) {
                        vardai[i] = vardai[i + 1];
                        pazymiuKiekiai[i] = pazymiuKiekiai[i + 1];

                        for (int j = 0; j < MAX_PAZYMIU; j++) {
                            pazymiai[i][j] = pazymiai[i + 1][j];
                        }
                    }

                    mokiniuSkaicius--;
                    pazymiuKiekiai[mokiniuSkaicius] = 0;
                    vardai[mokiniuSkaicius] = "";

                    cout << "Mokinys pasalintas.\n";
                }
            }
        }

    } while (pasirinkimas != 7);

    cout << "Programa baigta.\n";
    return 0;
}

int skaitytiSkaiciu(int nuo, int iki) {
    int skaicius;

    while (true) {
        if (cin >> skaicius) {
            if (skaicius >= nuo && skaicius <= iki) {
                return skaicius;
            }

            cout << "Neteisingas skaicius. Iveskite skaiciu nuo "
                 << nuo << " iki " << iki << ": ";
        }
        else {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Iveskite sveikaji skaiciu nuo "
                 << nuo << " iki " << iki << ": ";
        }
    }
}

int skaitytiMokinioNumeri(int mokiniuSkaicius) {
    int numeris;

    while (true) {
        cout << "Iveskite mokinio numeri nuo 1 iki "
             << mokiniuSkaicius << " (0 - grizti i meniu): ";

        if (cin >> numeris) {
            if (numeris == 0) {
                return -1;
            }

            if (numeris >= 1 && numeris <= mokiniuSkaicius) {
                return numeris - 1;
            }

            cout << "Neteisingas mokinio numeris. Iveskite skaiciu nuo 1 iki "
                 << mokiniuSkaicius << ".\n";
        }
        else {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Iveskite sveikaji skaiciu.\n";
        }
    }
}

void rodytiMokini(string vardai[], int pazymiai[][MAX_PAZYMIU],
                  int pazymiuKiekiai[], int numeris) {
    cout << "\nMokinys: " << vardai[numeris] << "\n";
    cout << "Pazymiai: ";

    if (pazymiuKiekiai[numeris] == 0) {
        cout << "mokinis pazymiu neturi";
    }
    else {
        for (int i = 0; i < pazymiuKiekiai[numeris]; i++) {
            cout << pazymiai[numeris][i] << " ";
        }
    }

    cout << "\n";
}
