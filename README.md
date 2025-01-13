# Documentatie README

## Descriere Proiect

Acest proiect simuleaza gestionarea platformelor petroliere si a produselor derivate din petrol. Include functionalitati precum extragerea petrolului, transformarea acestuia in produse derivate, si generarea rapoartelor financiare.

### Functionalitati principale:

1. Gestionarea platformelor petroliere.
2. Adaugarea si gestionarea derivatelor petroliere.
3. Simularea activitatilor zilnice ale platformelor.
4. Generarea rapoartelor financiare.

## Structura Proiectului

### Fisiere principale:

- **Derivate.h / Derivate.cpp**:
  - Defineaza clasa `Derivat` pentru produse derivate din petrol.
  - Functionalitati:
    - Producerea derivatelor.
    - Calculul veniturilor din derivate.
    - Modificarea pretului derivatelor.
- **Platforma.h / Platforma.cpp**:
  - Defineaza clasa `Platforma` pentru gestionarea platformelor petroliere.
  - Functionalitati:
    - Extragerea petrolului.
    - Transportarea petrolului.
    - Gestionarea stocurilor.
- **Simulare.h / Simulare.cpp**:
  - Clasa principala care gestioneaza simularea.
  - Functionalitati:
    - Adaugarea platformelor si derivatelor.
    - Simularea activitatii zilnice.
    - Generarea rapoartelor.
- **Platforma\_petroliera.cpp**:
  - Punctul de intrare al aplicatiei.
  - Interfata de tip consola pentru interactiunea cu utilizatorul.

### Clase utilizate:

- **Derivat**:
  - Atribute: nume, cantitate, pret.
  - Metode:
    - `produce(double cantitatePetrol)`
    - `calculeazaVenit()`
    - `setPret(double pretNou)`
    - `afiseazaInformatii()`
- **Platforma**:
  - Atribute: nume, cantitate zilnica, stoc curent, capacitate maxima.
  - Metode:
    - `extragePetrol()`
    - `transportaPetrol(double cantitate)`
    - `consumaPetrol(double cantitate)`
    - `afiseazaInformatii()`
- **Simulare**:
  - Atribute: lista de platforme, lista de derivate.
  - Metode:
    - `adaugaPlatforma(const Platforma& platforma)`
    - `adaugaDerivat(const Derivat& derivat)`
    - `simuleazaZi()`
    - `genereazaRaportFinanciar()`

## Instructiuni de Utilizare

1. Compilati proiectul folosind un compilator compatibil C++ (ex: g++):
   ```bash
   g++ -o simulare Derivate.cpp Platforma.cpp Simulare.cpp Platforma_petroliera.cpp
   ```
2. Rulati executabilul generat:
   ```bash
   ./simulare
   ```
3. Navigati prin meniul aplicatiei pentru a:
   - Adauga platforme sau derivate.
   - Modifica preturile derivatelor.
   - Transforma petrol in derivate.
   - Simula activitatea zilnica a platformelor.
   - Genera rapoarte financiare.

## Exemplu de Rulare

```text
--- Meniu Principal ---
1. Adauga platforma
2. Adauga derivat
3. Afiseaza platforme
4. Modifica pret derivat
5. Transforma petrol in derivat
6. Simuleaza o zi
7. Genereaza raport financiar
8. Iesi
Alege o optiune: 1
Nume platforma: Platforma_A
Cantitate zilnica: 100
Capacitate maxima: 1000
```

## Dependinte

- Limbaj de programare: C++
- Biblioteca standard: `<iostream>`, `<vector>`, `<string>`
