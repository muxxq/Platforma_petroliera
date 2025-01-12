#include "Simulare.h"
#include <iostream>

void afiseazaMeniu() {
    cout << "\n--- Meniu Principal ---\n";
    cout << "1. Adauga platforma\n";
    cout << "2. Adauga derivat\n";
    cout << "3. Afiseaza platforme\n";
    cout << "4. Modifica pret derivat\n";
    cout << "5. Transforma petrol in derivat\n";
    cout << "6. Simuleaza o zi\n";
    cout << "7. Genereaza raport financiar\n";
    cout << "8. Iesi\n";
    cout << "Alege o optiune: ";
}

int main() {
    Simulare simulare;
    bool rulare = true;

    while (rulare) {
        afiseazaMeniu();

        int optiune;
        cin >> optiune;

        switch (optiune) {
        case 1: {
            string nume;
            double cantitateZilnica, capacitateMaxima;
            cout << "Nume platforma: ";
            cin >> nume;
            cout << "Cantitate zilnica: ";
            cin >> cantitateZilnica;
            cout << "Capacitate maxima: ";
            cin >> capacitateMaxima;
            simulare.adaugaPlatforma(Platforma(nume, cantitateZilnica, capacitateMaxima));
            break;
        }
        case 2: {
            string nume;
            double pret;
            cout << "Nume derivat: ";
            cin >> nume;
            cout << "Pret derivat: ";
            cin >> pret;
            simulare.adaugaDerivat(Derivat(nume, pret));
            break;
        }
        case 3:
            simulare.afiseazaPlatforme();
            break;
        case 4: {
            string nume;
            double pretNou;
            cout << "Nume derivat: ";
            cin >> nume;


            // Cautăm derivatul și actualizăm prețul
            bool gasit = false;
            for (auto& derivat : simulare.getDerivate()) 
            {
                if (derivat.getNume() == nume) 
                {
                    cout << "Pret nou: ";
                    cin >> pretNou;
                    derivat.setPret(pretNou);
                    gasit = true;
                    break;
                }
            }
            if (!gasit) 
            {
                cout << "Derivatul " << nume << " nu exista.\n";
            }
            break;

        }
        case 5: {
            string numeDerivat, numePlatforma;
            double cantitatePetrol;

            // Solicităm utilizatorului numele derivatului
            cout << "Nume derivat: ";
            cin >> numeDerivat;

            // Verificăm dacă derivatul există
            auto& derivate = simulare.getDerivate();
            auto derivatIt = find_if(derivate.begin(), derivate.end(),
                [&numeDerivat](const Derivat& d) 
                {
                    return d.getNume() == numeDerivat;
                });
            if (derivatIt == derivate.end()) 
            {
                cout << "Eroare: Derivatul \"" << numeDerivat << "\" nu exista.\n";
                break;
            }

            // Solicităm utilizatorului numele platformei
            cout << "Nume platforma: ";
            cin >> numePlatforma;

            // Verificăm dacă platforma există
            auto& platforme = simulare.getPlatforme(); // Adăugăm o metodă getPlatforme()
            auto platformaIt = find_if(platforme.begin(), platforme.end(),
                [&numePlatforma](const Platforma& p) {
                    return p.getNume() == numePlatforma;
                });
            if (platformaIt == platforme.end()) {
                cout << "Eroare: Platforma \"" << numePlatforma << "\" nu exista.\n";
                break;
            }

            // Solicităm cantitatea de petrol de transformat
            cout << "Cantitate petrol pentru conversie: ";
            cin >> cantitatePetrol;

            // Verificăm dacă platforma are suficient petrol
            if (platformaIt->getStocCurent() < cantitatePetrol) 
            {
                cout << "Eroare: Platforma \"" << numePlatforma
                    << "\" nu are suficient petrol. Stoc curent: "
                    << platformaIt->getStocCurent() << " unitati.\n";
                break;
            }

            // Efectuăm conversia
            platformaIt->consumaPetrol(cantitatePetrol); // Adăugăm o metodă consumaPetrol()
            derivatIt->produce(cantitatePetrol); // Producem derivatul

            cout << "Conversie reusita: " << cantitatePetrol << " unitati de petrol din platforma \""
                << numePlatforma << "\" au fost transformate in " << numeDerivat << ".\n";
            break;
        }
        case 6:
            simulare.simuleazaZi();
            break;
        case 7:
            simulare.genereazaRaportFinanciar();
            break;
        case 8:
            cout << "Program incheiat. La revedere!\n";
            rulare = false;
            break;
        default:
            cout << "Optiune invalida! Incearca din nou.\n";
            break;
        }
    }

    return 0;
}
