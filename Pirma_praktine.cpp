#include <iostream>

using namespace std;

int main(){
    double eur;
    double GBP_Bendras   = 0.8729, GBP_Pirkti    = 0.8600, GBP_Parduoti  = 0.9220;
    double USD_Bendras   = 1.1793, USD_Pirkti    = 1.1460, USD_Parduoti  = 1.2340;
    double INR_Bendras   = 104.6918, INR_Pirkti    = 101.3862, INR_Parduoti  = 107.8546;

    cout << "Sveiki, čia yra programa kuri leidžia palyginti valiutų kursus su euru, pirkti pasirinktą valiutą už eurus ir parduoti pasirinktą valiutą už eurus." << endl;
    cout << "Įrašykite skaičių: " << endl;
    cout << "1 - palyginti valiutų kursus su euru." << endl;
    cout << "2 - pirkti pasirinktą valiutą už eurus." << endl
    cout << "3 - parduoti pasirinktą valiutą už eurus." << endl;
    cin << eur;

    return 0;
}