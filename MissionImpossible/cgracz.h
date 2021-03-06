#ifndef CGRACZ_H
#define CGRACZ_H
#include "cobiekt.h"
#include "conio.h"

class CGracz : public CObiekt
{
private:
    int sterowanie;
public:
    CGracz(int x, int y);

    virtual Rezultat_Ruchu Ruch(CMapa* mapa);
    virtual void Wyswietl();
    virtual bool czy_mozna_mnie_sledzic();
    virtual bool czy_mozna_we_mnie_wejsc(); //zmiana
};

#endif // CGRACZ_H
