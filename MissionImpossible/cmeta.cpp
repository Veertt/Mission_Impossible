#include "cmeta.h"

CMeta::CMeta(int x, int y):CObiekt(x,y)
{
}

Rezultat_Ruchu CMeta::Ruch(CMapa *mapa)
{
    return Nic;
}

void CMeta::Wyswietl()
{
    cout<<"-";
}

bool CMeta::czy_za_pomoca_mnie_mozna_wygrac()
{
    return true;
}

