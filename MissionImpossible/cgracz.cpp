#include "cgracz.h"
#include "cmapa.h"

CGracz::CGracz(int x, int y): CObiekt (x,y)
{
}

void CGracz::Wyswietl()
{
    cout << "G";
}

bool CGracz::czy_mozna_mnie_sledzic()
{
    return true;
}

bool CGracz::czy_mozna_we_mnie_wejsc() //zmiana
{
    return false;
}

Rezultat_Ruchu CGracz::Ruch(CMapa *mapa) //zmiana
{
    SKoordynaty_obiektu aktualne = Get_koordynaty();

    if(kbhit())
    {
        sterowanie = getch();

        switch(sterowanie)
        {
            case 119:
                aktualne.R--;
                break;

            case 115:
                aktualne.R++;
                break;

            case 100:
                aktualne.K++;
                break;

            case 97:
                aktualne.K--;
                break;
        }
    }

    CObiekt *pom = mapa->Get_co_jest_na_mapie(aktualne.R,aktualne.K);
    Set_koordynaty(aktualne);

    if(pom!=NULL&&pom->czy_za_pomoca_mnie_mozna_wygrac())
    {
        return Wygrana;
    }

    return Nic;
}
