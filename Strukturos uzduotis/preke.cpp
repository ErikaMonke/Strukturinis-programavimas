#include <iostream>

using namespace std;
struct Preke {
    string pavadinimas;
    double kaina;
    int kiekis;
};
int main() {
    Preke p[5];
    int indeksas = 1;
    int maxI = 0;
    double max = 0.0;
    cout << "Si programa leidzia irasyti prekes ir rasti brangiausia preke" << endl;

    for (int i = 0; i < 5; i++) {
        cout << "Iveskite " << indeksas << "-os prekes pavadinima: " << endl;
        cin >> p[i].pavadinimas;
        cout << "Iveskite " << indeksas << "-os prekes kaina: " << endl;
        cin >> p[i].kaina;
        cout << "Iveskite " << indeksas << "-os prekes kieki: " << endl;
        cin >> p[i].kiekis;
        indeksas++;
        if (p[i].kaina > max) {
            maxI = i;
            max = p[i].kaina;
        }
    }
    cout << "Brangiausia preke - " << p[maxI].pavadinimas << endl;
    cout << "Jos kaina - " << p[maxI].kaina << endl;
    return 0;
}