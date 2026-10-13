#include <iomanip>
#include <iostream>
#include <string>

using namespace std;

int main() {
    const double GBP_Bendras = 0.8729;
    const double GBP_Pirkti = 0.8600;
    const double GBP_Parduoti = 0.9220;

    const double USD_Bendras = 1.1793;
    const double USD_Pirkti = 1.1460;
    const double USD_Parduoti = 1.2340;

    const double INR_Bendras = 104.6918;
    const double INR_Pirkti = 101.3862;
    const double INR_Parduoti = 107.8546;

    int veiksmas;
    cout << "Valiutos keitykla\n";
    cout << "1 - palyginti valiutos kursą su euru\n";
    cout << "2 - pirkti valiutą (EUR -> valiuta)\n";
    cout << "3 - parduoti valiutą (valiuta -> EUR)\n";
    cout << "4 - išeiti\n";
    cout << "Pasirinkite veiksmą: ";

    if (!(cin >> veiksmas)) {
        cout << "Neteisingas meniu pasirinkimas.\n";
        return 0;
    }

    if (veiksmas == 4) {
        cout << "Programa baigta.\n";
        return 0;
    }

    if (veiksmas < 1 || veiksmas > 3) {
        cout << "Neteisingas meniu pasirinkimas.\n";
        return 0;
    }

    int valiutosPasirinkimas;
    cout << "\nPasirinkite valiutą:\n";
    cout << "1 - GBP\n";
    cout << "2 - USD\n";
    cout << "3 - INR\n";
    cout << "Jūsų pasirinkimas: ";

    if (!(cin >> valiutosPasirinkimas)) {
        cout << "Neteisingas valiutos pasirinkimas.\n";
        return 0;
    }

    string valiuta;
    double bendrasKursas;
    double pirkimoKursas;
    double pardavimoKursas;

    switch (valiutosPasirinkimas) {
        case 1:
            valiuta = "GBP";
            bendrasKursas = GBP_Bendras;
            pirkimoKursas = GBP_Pirkti;
            pardavimoKursas = GBP_Parduoti;
            break;
        case 2:
            valiuta = "USD";
            bendrasKursas = USD_Bendras;
            pirkimoKursas = USD_Pirkti;
            pardavimoKursas = USD_Parduoti;
            break;
        case 3:
            valiuta = "INR";
            bendrasKursas = INR_Bendras;
            pirkimoKursas = INR_Pirkti;
            pardavimoKursas = INR_Parduoti;
            break;
        default:
            cout << "Neteisingas valiutos pasirinkimas.\n";
            return 0;
    }

    cout << fixed << setprecision(2);

    if (veiksmas == 1) {
        cout << "\nBendras valiutos kursas:\n";
        cout << "1.00 EUR = " << bendrasKursas << " " << valiuta << "\n";
        cout << "1.00 " << valiuta << " = "
             << 1.0 / bendrasKursas << " EUR\n";
    } else {
        double suma;

        if (veiksmas == 2) {
            cout << "Įveskite eurų sumą, už kurią norite pirkti: ";
        } else {
            cout << "Įveskite parduodamos valiutos sumą: ";
        }

        if (!(cin >> suma)) {
            cout << "Neteisinga suma.\n";
            return 0;
        }

        if (suma <= 0) {
            cout << "Suma turi būti didesnė už nulį.\n";
            return 0;
        }

        if (veiksmas == 2) {
            const double gautaSuma = suma * pirkimoKursas;
            cout << "Pradinė suma: " << suma << " EUR\n";
            cout << "Pasirinkta valiuta: " << valiuta << "\n";
            cout << "Gaunama suma: " << gautaSuma << " " << valiuta << "\n";
        } else {
            const double gautaSuma = suma / pardavimoKursas;
            cout << "Pradinė suma: " << suma << " " << valiuta << "\n";
            cout << "Pasirinkta valiuta: " << valiuta << "\n";
            cout << "Gaunama suma: " << gautaSuma << " EUR\n";
        }
    }

    return 0;
}
