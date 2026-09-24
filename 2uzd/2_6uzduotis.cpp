#include <iostream>
using namespace std;

int main() {
    double p = 1000;
    for (int i = 1; i <= 10; i++) {
        p = p * 1.05;
        cout << "Po " << i << " metu kiek gaus pinigu: " << p << " Eur." << endl;
    }
    cout << "Jus gausite tiek pinigu po 10 metu: " << p << " Eur." << endl;
    return 0;
}