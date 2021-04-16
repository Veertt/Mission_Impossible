#include "csciana.h"

CSciana::CSciana(int x, int y):CObiekt(x,y)
{

}

Rezultat_Ruchu CSciana::Ruch(CMapa* mapa)
{
    return Nic;
}

void CSciana::Wyswietl()
{
    cout << '*';
}

bool CSciana::czy_mozna_we_mnie_wejsc()
{
    return false;
}
