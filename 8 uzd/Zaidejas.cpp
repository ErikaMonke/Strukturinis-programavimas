#include <iostream>
#include <fstream>
#include <string>

using namespace std;
struct Zaidejas {
    string vardasPavarde;
    string komanda;
    int rungtynes;
    int taskai;
};
int main() {

    Zaidejas zaidejas[10];
    double vidurkis[10];
    double max = 0;
    int indeksas;

    ifstream fin("zaidejai.txt");
    if (!fin) {
        cout << "Failas nerastas." << endl;
        return 1;
    }
    int i = 0;

    while (i < 7 && fin >> ws && getline(fin, zaidejas[i].vardasPavarde)) {

        fin >> zaidejas[i].komanda
            >> zaidejas[i].rungtynes
            >> zaidejas[i].taskai;
        vidurkis[i] = (double)zaidejas[i].taskai / zaidejas[i].rungtynes;
        cout << zaidejas[i].vardasPavarde << " " << zaidejas[i].komanda << " " << "Jo vidurkis - " << vidurkis[i] << endl;
        if (vidurkis[i] > max) {
            max = vidurkis[i];
            indeksas = i;
        }
        i++;
    }
    cout << "Didziausias vidurkis: " << zaidejas[indeksas].vardasPavarde << " " << zaidejas[indeksas].komanda << " " << vidurkis[indeksas] << endl;
    fin.close();
    return 0;
}