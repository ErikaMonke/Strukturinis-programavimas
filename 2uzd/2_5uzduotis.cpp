#include <iostream>

using namespace std;
int main () {
    int Suma = 0;
    for (int i = 1; i <= 20; i++) {
        if (i % 2 != 0) {
            Suma += i;
            cout << "Skaicius: " << i << endl;
        }

    }
    cout << "Suma visu nelyginiu skaiciu nuo 1 iki 20: " << Suma << endl;
    return 0;
}