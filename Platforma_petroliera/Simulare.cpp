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

    for (auto& derivat : derivate) 
    {
        derivat.produce(cantitateTotala / derivate.size());
    }
}

void Simulare::afiseazaRaport() const 
{
    std::cout << "\n--- Raport Simulare ---\n";
    for (const auto& platforma : platforme) 
    {
        platforma.afiseazaInformatii();
    }
    for (const auto& derivat : derivate) 
    {
        derivat.afiseazaInformatii();
    }
}
