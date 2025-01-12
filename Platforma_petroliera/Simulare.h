#ifndef SIMULARE_H
#define SIMULARE_H

#include "Platforma.h"
#include "Derivate.h"
#include <vector>
#include <memory>
using namespace std;

class Simulare 
{
private:
    vector<Platforma> platforme;
    vector<Derivat> derivate;

public:
    void adaugaPlatforma(const Platforma& platforma);
    void adaugaDerivat(const Derivat& derivat);
    void simuleazaZi();
    void afiseazaRaport() const;
    void afiseazaPlatforme() const;
    void genereazaRaportFinanciar() const;
    void produceDerivat(const string& numeDerivat, double cantitatePetrol);
    vector<Derivat>& getDerivate();
    vector<Platforma>& getPlatforme();

};

#endif // SIMULARE_H