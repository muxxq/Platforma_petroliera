#ifndef PLATFORMA_H
#define PLATFORMA_H

#include <string>
#include <iostream>
using namespace std;

class Platforma 
{
private:
    string nume;
    double cantitateZilnica;
    double stocCurent;
    double capacitateMaxima;

public:
    Platforma(const string& nume, double cantitateZilnica, double capacitateMaxima);

    void extragePetrol();
    double transportaPetrol(double cantitate);
    void afiseazaInformatii() const;
    void consumaPetrol(double cantitate);


    double getStocCurent() const { return stocCurent; }
    string getNume() const { return nume; }

};

#endif // PLATFORMA_H
