#include <iostream>

using namespace std;

int main(){
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
    cin >> pasirinkimas;

    switch (pasirinkimas) {
    case 1: {
        cout << "Įveskite eurų kiekį: " << endl;
        cin >> eur;

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
            cout << "Iveskite euru kieki: " << endl;
            cin >> eur;
            suma = eur * GBP_Pirkti;
            cout << "Jus nupirkote - " << suma << " GBP" << endl;
            break;
        case 2:
            cout << "Iveskite euru kieki: " << endl;
            cin >> eur;
            suma = eur * USD_Pirkti;
            cout << "Jus nupirkote - " << suma << " USD" << endl;
            break;
        case 3:
            cout << "Iveskite euru kieki: " << endl;
            cin >> eur;
            suma = eur * INR_Pirkti;
            cout << "Jus nupirkote - " << suma << " INR" << endl;
            break;
        default:
            cout << "Neteisingas valiutos pasirinkimas.\n";
            break;
    }
        break;
    }

    case 3: {
        cout << "Pasirinkite valiutą kuria norite parduoti: " << endl;
        cout << "1 - GBP;\n2 - USD;\n3 - INR." << endl;
        cin >> pasirinkimas;
        break;
    }
    default:
    cout << "Netinkamas formatas. Pradėkite iš naujo." << endl;
    }
    return 0;
}