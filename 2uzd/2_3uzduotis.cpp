#include <iostream>

using namespace std;

int main () {
    double egz;
    cout << "Iveskite egzamino ivertinima: " << endl;
    cin >> egz;
    if (egz == 10) cout << "Puiku" << endl;
    else if (egz >= 9 && egz < 10) cout << "Labai gerai" << endl;
    else if (egz >= 7 && egz < 9) cout << "Gerai" << endl;
    else if (egz >= 5 && egz < 7) cout << "Patenkinamai" << endl;
    else if (egz < 5 && egz > 0) cout << "Egzaminas neislaikytas" << endl;
    else cout << "Blogai ivestas rezultatas. Paleiskite programa is naujo" << endl;
    return 0;
}