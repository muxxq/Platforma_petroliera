#include "Platforma.h"

Platforma::Platforma(const string& nume, double cantitateZilnica, double capacitateMaxima)
    : nume(nume), cantitateZilnica(cantitateZilnica), stocCurent(0), 
    capacitateMaxima(capacitateMaxima) {}

void Platforma::extragePetrol() 
{
    if (stocCurent + cantitateZilnica <= capacitateMaxima) 
    {
        stocCurent += cantitateZilnica;
        cout << nume << ": Extras " << cantitateZilnica <<" unitati de petrol.Stoc curent : " << stocCurent << "\n";
    }
    else 
    {
        double cantitateRamasa = capacitateMaxima - stocCurent;
        stocCurent = capacitateMaxima;
        cout << nume <<": Capacitate maxima atinsa! Doar " << cantitateRamasa << " unitati au fost extrase.\n";
    }
}

double Platforma::transportaPetrol(double cantitate) 
{
    if (cantitate > stocCurent) 
    {
        double livrat = stocCurent;
        stocCurent = 0;
        return livrat;
    }
    else 
    {
        stocCurent -= cantitate;
        return cantitate;
    }
}

void Platforma::afiseazaInformatii() const 
{
    cout << "Platforma: " << nume
        << "\nCantitate zilnica: " << cantitateZilnica
        << "\nStoc curent: " << stocCurent
        << "\nCapacitate maxima: " << capacitateMaxima << "\n";
}

void Platforma::consumaPetrol(double cantitate) 
{
    if (cantitate > stocCurent) {
        cerr << "Eroare: Cantitatea solicitata depaseste stocul curent al platformei.\n";
        return;
    }
    stocCurent -= cantitate;
}

