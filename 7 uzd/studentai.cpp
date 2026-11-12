#include <iostream>
#include <fstream>
#include <string>

using namespace std;
int main () {
    ifstream fin("studentai.txt");
    if (!fin) {
        cout << "Nepavyko atidaryti" << endl;
        return 1;
    }
    int pazymis;
    string Vardas;
    while (fin >> Vardas >> pazymis) {
        if (pazymis > 8) {
            cout << Vardas << endl;
        }
    }
    fin.close();
    return 0;
}