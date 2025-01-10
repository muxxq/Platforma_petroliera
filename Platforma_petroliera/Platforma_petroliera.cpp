#include "Simulare.h"
using namespace std;

int main() 
{
    Simulare simulare;

    // Adaugam platforme
    simulare.adaugaPlatforma(Platforma("Platforma 1", 100, 500));
    simulare.adaugaPlatforma(Platforma("Platforma 2", 150, 600));

    // Adaugam derivate
    simulare.adaugaDerivat(Derivat("Benzină", 5.0));
    simulare.adaugaDerivat(Derivat("Motorină", 4.5));

    // Simulam mai multe zile
    for (int i = 0; i < 3; ++i) 
    {
        cout << "\nZiua " << i + 1 << ":\n";
        simulare.simuleazaZi();
        simulare.afiseazaRaport();
    }

    return 0;
}
