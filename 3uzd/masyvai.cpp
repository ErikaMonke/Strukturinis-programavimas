#include <iostream>
using namespace std;

int main() {
    int m[4];
    int sum = 0;
    int max = 0, min = 0;
    cout << "Iveskite 5 sveikuosius skaicius: " << endl;
    for (int i = 0; i <= 4; i++) {
        cin >> m[i];
    }
    min = m[0];
    for (int i = 0; i <= 4; i++) {
        sum += m[i];
    }
    for (int i = 0; i <= 4; i++) {
        if (m[i] > max) max = m[i];
    }
    for (int i = 0; i <= 4; i++) {
        if (m[i] < min) min = m[i];
    }
    cout << "Visu skaiciu suma: " << sum << endl;
    cout << "Didziausias masyvo skaicius: " << max << endl;
    cout << "Maziausias masyvo skaicius: " << min << endl;

    return 0;
}