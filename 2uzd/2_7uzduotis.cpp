#include <iostream>

using namespace std;
int main () {
    int s = 0;
    for (int i = 1; i <= 20; i++) {
        if (i % 4 == 0) {
            cout << "Sis skaiciu dalinasi is 4: " << i << endl;
        }
    }
    return 0;
}