#include "Derivate.h"

Derivat::Derivat(const string& nume, double pret)
    : nume(nume), cantitate(0), pret(pret) {}

void Derivat::produce(double cantitatePetrol) 
{
    cantitate += cantitatePetrol * 0.8; // Presupunem un randament de 80%
    cout << "Produs: " << nume << ", Cantitate produsa: " << cantitate << "\n";
}

double Derivat::calculeazaVenit() const 
{
    return cantitate * pret;
}
void Derivat::setPret(double pretNou)
{
    pret = pretNou;
    cout << "Pretul derivatului " << nume << " a fost actualizat la " << pret << ".\n";
}
void Derivat::afiseazaInformatii() const 
{
    cout << "Derivat: " << nume << "\nCantitate: " << cantitate << "\nPret: " << pret << "\n";
}



