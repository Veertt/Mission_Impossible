#ifndef COBIEKT_H
#define COBIEKT_H
#include <iostream>

using namespace std;

enum Rezultat_Ruchu
{
    Nic,
    Przegrana,
    Wygrana
};

struct SKoordynaty_obiektu
{
    int R;
    int K;
};

class CMapa;

class CObiekt
{

private:
    SKoordynaty_obiektu koordynaty;

public:
    CObiekt(int x, int y);
    SKoordynaty_obiektu Get_koordynaty();
    void Set_koordynaty(SKoordynaty_obiektu wspolrzedne);

    virtual Rezultat_Ruchu Ruch(CMapa* mapa)=0;
    virtual void Wyswietl()=0;
    virtual bool czy_za_pomoca_mnie_mozna_wygrac();
    virtual bool czy_mozna_we_mnie_wejsc();
    virtual bool czy_mozna_mnie_sledzic();
    virtual bool czy_mozna_za_pomoca_mnie_przegrac();
};

#endif // COBIEKT_H
