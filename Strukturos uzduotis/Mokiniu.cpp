#include <iostream>

using namespace std;

struct Mokinys{
    string vardas;
    int amzius;
    double pazymys;
};

int main() {

    double Suma = 0;
    Mokinys mokinys[2];
    cout << "Si programa leidzia ivesti mokinio varda, amziu ir pazymi. Taip pat apskaiciuoju ju vidurkius" << endl;

        cout << "Iveskite pirmo mokinio varda: "  << endl;
        cin >> mokinys[0].vardas;
        cout << "Iveskite pirmo mokinio amziu: " << endl;
        cin >> mokinys[0].amzius;
        cout << "Iveskite pirmo mokinio pazymi: " << endl;
        cin >> mokinys[0].pazymys;

    cout << "Iveskite antro mokinio varda: "  << endl;
    cin >> mokinys[1].vardas;
    cout << "Iveskite antro mokinio amziu: " << endl;
    cin >> mokinys[1].amzius;
    cout << "Iveskite antro mokinio pazymi: " << endl;
    cin >> mokinys[1].pazymys;

    cout << "Iveskite trecio mokinio varda: "  << endl;
    cin >> mokinys[2].vardas;
    cout << "Iveskite trecio mokinio amziu: " << endl;
    cin >> mokinys[2].amzius;
    cout << "Iveskite trecio mokinio pazymi: " << endl;
    cin >> mokinys[2].pazymys;
    for (int i = 0; i < 2; i++) {
        Suma += mokinys[i].pazymys;
    }

    cout << "Visu mokiniu vidurkis: " << Suma/3 << endl;
    return 0;
}