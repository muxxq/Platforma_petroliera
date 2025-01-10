#include "Derivate.h"

Derivat::Derivat(const std::string& nume, double pret)
    : nume(nume), cantitate(0), pret(pret) {}

void Derivat::produce(double cantitatePetrol) 
{
    cantitate += cantitatePetrol * 0.8; // Presupunem un randament de 80%
    std::cout << "Produs: " << nume << ", Cantitate produsă: " << cantitate << "\n";
}

double Derivat::calculeazaVenit() const 
{
    return cantitate * pret;
}

void Derivat::afiseazaInformatii() const 
{
    std::cout << "Derivat: " << nume << "\nCantitate: " << cantitate << "\nPret: " << pret << "\n";
}
