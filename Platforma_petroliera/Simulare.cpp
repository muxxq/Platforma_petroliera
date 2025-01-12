#include "Simulare.h"

void Simulare::adaugaPlatforma(const Platforma& platforma) 
{
    platforme.push_back(platforma);
}

void Simulare::adaugaDerivat(const Derivat& derivat) 
{
    derivate.push_back(derivat);
}

void Simulare::simuleazaZi() 
{
    for (auto& platforma : platforme) 
    {
        platforma.extragePetrol();
    }

    double cantitateTotala = 0;
    for (const auto& platforma : platforme) 
    {
        cantitateTotala += platforma.getStocCurent();
    }

    //for (auto& derivat : derivate) 
    //{
    //    derivat.produce(cantitateTotala / derivate.size());
    //}
}
void Simulare::afiseazaPlatforme() const 
{
    if (platforme.empty()) 
    {
        cout << "Nu exista platforme adaugate.\n";
        return;
    }

    cout << "\n--- Lista Platformelor ---\n";
    for (const auto& platforma : platforme) 
    {
        platforma.afiseazaInformatii();
    }
}
void Simulare::afiseazaRaport() const 
{
    cout << "\n--- Raport Simulare ---\n";
    for (const auto& platforma : platforme) 
    {
        platforma.afiseazaInformatii();
    }
    for (const auto& derivat : derivate) 
    {
        derivat.afiseazaInformatii();
    }
}
void Simulare::genereazaRaportFinanciar() const 
{
    if (derivate.empty()) 
    {
        cout << "Nu exista derivate pentru a genera un raport financiar.\n";
        return;
    }

    double venituriTotale = 0;

    cout << "\n--- Raport Financiar ---\n";
    for (const auto& derivat : derivate) 
    {
        double venit = derivat.calculeazaVenit();
        venituriTotale += venit;
        derivat.afiseazaInformatii();
        cout << "Venit din acest derivat: " << venit << "\n";
    }

    cout << "Venituri totale: " << venituriTotale << "\n";
}
void Simulare::produceDerivat(const string& numeDerivat, double cantitatePetrol) {
    // Căutăm derivatul după nume
    for (auto& derivat : derivate) {
        if (derivat.getNume() == numeDerivat) 
        {
            // Calculăm cantitatea produsă cu un randament de 90%
            double cantitateProdusa = cantitatePetrol * 0.9;
            derivat.produce(cantitateProdusa);
            cout << "Din " << cantitatePetrol << " unitati de petrol s-au produs "
                << cantitateProdusa << " unitati de " << numeDerivat << ".\n";
            return;
        }
    }
    cout << "Derivatul " << numeDerivat << " nu exista.\n";
}
vector<Derivat>& Simulare::getDerivate()
{
    return derivate;
}
vector<Platforma>& Simulare::getPlatforme()
{
    return platforme;
}

