#include <iostream>
#include <algorithm>
using namespace std;

void sukeisti(int &pirmas, int &antras);

int main() {
    int pirmas, antras;
    cout << "Iveskite du skaicius kuriuos norite sukeisti: " << endl;
    cin >> pirmas;
    cin >> antras;
    sukeisti(pirmas, antras);
    cout << "Jusu skaiciai: " << pirmas << " " << antras << endl;
    return 0;
}

void sukeisti(int &pirmas, int &antras) {
    swap(pirmas, antras);
}