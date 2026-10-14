#include <iostream>
#include <iomanip>

using namespace std;

int main(){
    cout << fixed << setprecision(2);
    int pasirinkimas;
    double eur = 0, suma = 0;
    const double GBP_Bendras = 0.8729, GBP_Pirkti  = 0.8600, GBP_Parduoti = 0.9220;
    const double USD_Bendras = 1.1793, USD_Pirkti  = 1.1460, USD_Parduoti = 1.2340;
    const double INR_Bendras = 104.6918, INR_Pirkti  = 101.3862, INR_Parduoti = 107.8546;

    cout << "Sveiki, čia yra programa kuri leidžia palyginti valiutų kursus su euru, pirkti pasirinktą valiutą už eurus ir parduoti pasirinktą valiutą už eurus." << endl;
    cout << "Įrašykite skaičių: " << endl;
    cout << "1 - palyginti valiutų kursus su euru." << endl;
    cout << "2 - pirkti pasirinktą valiutą už eurus." << endl;
    cout << "3 - parduoti pasirinktą valiutą už eurus." << endl;
    cout << "4 - išeiti iš programos" << endl;
    cin >> pasirinkimas;

    switch (pasirinkimas) {

    case 1: {

        cout << "Įveskite eurų kiekį: " << endl;
        cin >> eur;

        if (eur <= 0) {
                cout << "Klaida! Suma turi būti didesnė už nulį." << endl;
                break;
            }
        double EUR_GBP = eur * GBP_Bendras;
        double EUR_USD = eur * USD_Bendras;
        double EUR_INR = eur * INR_Bendras;
        cout << "Eurai konvertuoti į kitas valiutas: " << endl;
        cout << eur << " Eur - " << EUR_GBP << " GBP" << endl;
        cout << eur << " Eur - " << EUR_USD << " USD" << endl;
        cout << eur << " Eur - " << EUR_INR << " INR" << endl;
        break;
    }

    case 2: {
        cout << "Pasirinkite valiutą norite nupirkti: " << endl;
        cout << "1 - GBP;\n2 - USD;\n3 - INR." << endl;
        cin >> pasirinkimas;

        switch (pasirinkimas){
            case 1:
            cout << "Iveskite eurų kiekį: " << endl;
            cin >> eur;
            if (eur <= 0) {
                cout << "Klaida! Suma turi būti didesnė už nulį." << endl;
                break;
            }
            suma = eur * GBP_Pirkti;
            cout << "Jūs nupirkote - " << suma << " GBP" << endl;
            break;
        case 2:
            cout << "Iveskite eurų kiekį: " << endl;
            cin >> eur;
            if (eur <= 0) {
                cout << "Klaida! Suma turi būti didesnė už nulį." << endl;
                break;
            }
            suma = eur * USD_Pirkti;
            cout << "Jūs nupirkote - " << suma << " USD" << endl;
            break;
        case 3:
            cout << "Iveskite eurų kiekį: " << endl;
            cin >> eur;
            if (eur <= 0) {
                cout << "Klaida! Suma turi būti didesnė už nulį." << endl;
                break;
            }
            suma = eur * INR_Pirkti;
            cout << "Jūs nupirkote - " << suma << " INR" << endl;
            break;
        default:
            cout << "Neteisingas valiutos pasirinkimas.\n";
            break;
    }
        break;
    }

    case 3: {
        cout << "Pasirinkite valiutą kurią norite parduoti: " << endl;
        cout << "1 - GBP;\n2 - USD;\n3 - INR." << endl;
        cin >> pasirinkimas;

        switch (pasirinkimas){
            case 1:
            cout << "Iveskite GPB kiekį: " << endl;
            cin >> eur;

            if (eur <= 0) {
                cout << "Klaida! Suma turi buti didesnė už nulį." << endl;
                break;
            }
            suma = eur / GBP_Parduoti;
            cout << "Parduota: " << eur << " GBP" << endl;
            cout << "Gauta: " << suma << " EUR" << endl;
            break;
        case 2:
            cout << "Iveskite USD kiekį: " << endl;
            cin >> eur;

            if (eur <= 0) {
                cout << "Klaida! Suma turi buti didesnė už nulį." << endl;
                break;
            }
            suma = eur / USD_Parduoti;
            cout << "Parduota: " << eur << " USD" << endl;
            cout << "Gauta: " << suma << " EUR" << endl;
            break;
        case 3:
            cout << "Iveskite INR kiekį: " << endl;
            cin >> eur;

            if (eur <= 0) {
                cout << "Klaida! Suma turi buti didesnė už nulį." << endl;
                break;
            }
            suma = eur / INR_Parduoti;
            cout << "Parduota: " << eur << " INR" << endl;
            cout << "Gauta: " << suma << " EUR" << endl;
            break;
            default:
            cout << "Netinkamas formatas. Pradėkite iš naujo." << endl;
    }
    break;
    }
    case 4: {
        cout << "Jūs baigiate programos darbą. Viso gero :)" << endl;
        break;
    }
    default:
    cout << "Netinkamas formatas. Pradėkite iš naujo." << endl;
    }
    cout << "Programa baigia veikti. Viso gero :)" << endl;
    return 0;
}