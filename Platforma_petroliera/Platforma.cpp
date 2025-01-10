﻿#include "Platforma.h"

Platforma::Platforma(const string& nume, double cantitateZilnica, double capacitateMaxima)
    : nume(nume), cantitateZilnica(cantitateZilnica), stocCurent(0), 
    capacitateMaxima(capacitateMaxima) {}

void Platforma::extragePetrol() 
{
    if (stocCurent + cantitateZilnica <= capacitateMaxima) 
    {
        stocCurent += cantitateZilnica;
        cout << nume << ": Extras " << cantitateZilnica << " unități de petrol. Stoc curent: " << stocCurent << "\n";
    }
    else 
    {
        double cantitateRamasa = capacitateMaxima - stocCurent;
        stocCurent = capacitateMaxima;
        cout << nume << ": Capacitate maximă atinsă! Doar " << cantitateRamasa << " unități au fost extrase.\n";
    }
}

double Platforma::transportaPetrol(double cantitate) 
{
    if (cantitate > stocCurent) {
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
    std::cout << "Platforma: " << nume
        << "\nCantitate zilnică: " << cantitateZilnica
        << "\nStoc curent: " << stocCurent
        << "\nCapacitate maximă: " << capacitateMaxima << "\n";
}