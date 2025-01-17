#ifndef DERIVATE_H
#define DERIVATE_H

#include <string>
#include <iostream>
using namespace std;

class Derivat 
{
private:
    string nume;
    double cantitate;
    double pret;

public:
    Derivat(const string& nume, double pret);

    void produce(double cantitatePetrol);
    void setPret(double pretNou);
    double calculeazaVenit() const;
    void afiseazaInformatii() const;
    string getNume() const { return nume; }
    

    

};

#endif // DERIVATE_H
