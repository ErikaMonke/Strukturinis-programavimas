using namespace std;
#include <iostream>

int main() {
    int v1, v2, v3, v4, v5;
    double Vidurkis;
    cout << "Iveskite vidurkius mokiniu atskirdami tarpais" << endl;
    cin >> v1 >> v2 >> v3 >> v4 >> v5;
    Vidurkis = (v1 + v2 + v3 + v4 + v5) / 5;
    if (Vidurkis > 4) cout << "Vidurkis yra teigiamas: " << Vidurkis << endl;
    else cout << "Vidurkis yra neigiamas: " << Vidurkis << endl;
    return 0;
}