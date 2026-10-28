#include <iostream>
using namespace std;

double skaiciuotiPlota(double ilgis, double plotis);
double skaiciuotiPerimetra(double ilgis, double plotis);

int main() {
    double i, p;
    cout << "Iveskite staciakampio ilgi" << endl;
    cin >> i;
    cout << "Iveskite staciakampio ploti" << endl;
    cin >> p;
    cout << "Jusu gautas plotis: " << skaiciuotiPlota(i, p) << endl;
    cout << "Jusu gautas perimetras: " << skaiciuotiPerimetra(i, p) << endl;
    return 0;
}

double skaiciuotiPlota(double ilgis, double plotis) {
    double plotas;
    plotas = ilgis * plotis;
    return plotas;
}
double skaiciuotiPerimetra(double ilgis, double plotis) {
    double perimetras;
    perimetras = (ilgis + plotis) * 2;
    return perimetras;
}