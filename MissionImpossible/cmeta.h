#ifndef CMETA_H
#define CMETA_H
#include "cobiekt.h"

class CMeta : public CObiekt
{
public:
    CMeta(int x,int y);
    virtual Rezultat_Ruchu Ruch(CMapa* mapa);
    virtual void Wyswietl();
    virtual bool czy_za_pomoca_mnie_mozna_wygrac();
};

#endif // CMETA_H
