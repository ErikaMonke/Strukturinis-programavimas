#include <iostream>
using namespace std;
int main() {

    int ivertinimas[11] = {0};
    int i = 0, a;
    while (i != 40) {
        cout << "Iveskite ivertinima zaidimo nuo 1 iki 10: " << endl;
        cin >> a;
        if (a > 0 || a < 10) {
            ivertinimas[a]++;
            i++;
        }
        else cout << "Blogai ivestas ivertinimas, pabandykite dar karta. " << endl;
    }
    cout << "Apibendrinimas: " << endl;
    for (int i = 1; i <= 10; i++) {
        cout << "Tiek pasirinko " << i << " ivertinima - " << ivertinimas[i] << endl;
    }


    return 0;
}
