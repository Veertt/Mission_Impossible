#include "cagent.h"
#include "cmapa.h"

CAgent::CAgent(int x, int y, bool orientacja):
    CZarzadca_Agentow(x,y,orientacja)
{
}

Rezultat_Ruchu CAgent::Ruch(CMapa* mapa)
{
    if( clock() > czas )
    {

    Sprawdzajaca_czy_wiemy_gdzie_jest_gracz(mapa);

    SKoordynaty_obiektu aktualne = Get_koordynaty();

    if(czy_wiemy_gdzie_jest_gracz == false)
    {
        if(orientacja == false)
        {
            aktualne = do_Ruchu_dla_pionowych(mapa);
        }
        else if(orientacja == true)
        {
            aktualne = do_Ruchu_dla_poziomych(mapa);
        }

    }else if(czy_wiemy_gdzie_jest_gracz == true)
    {
        aktualne = mapa->Znajdz_najkrotsza_do_gracza(Get_koordynaty(),wspolrzedne_gracza);
        cout<<wspolrzedne_gracza.R<<" "<<wspolrzedne_gracza.K<<endl;
        Set_koordynaty(aktualne);
    }

    CObiekt *pom = mapa->Get_co_jest_na_mapie(aktualne.R,aktualne.K);

    for(int i = aktualne.R-1; i<=aktualne.R+1; i++)
    {
        for(int j = aktualne.K-1; j<=aktualne.K+1; j++)
        {
            pom = mapa->Get_co_jest_na_mapie(i,j);

            if(pom!=NULL&&pom->czy_mozna_mnie_sledzic())
            {
                return Przegrana;
            }
        }
    }

    czas = clock() + 0.08 * CLOCKS_PER_SEC;

    }

    return Nic;
}

SKoordynaty_obiektu CAgent::do_Ruchu_dla_pionowych(CMapa *mapa)
{
    SKoordynaty_obiektu aktualne = Get_koordynaty();
    if(w_ktora_strone == true)
    {
        CObiekt *pom = mapa->Get_co_jest_na_mapie(aktualne.R-1,aktualne.K);
        if (pom == NULL || pom->czy_mozna_we_mnie_wejsc())
        {
            aktualne.R--;
        }
        else
        {
            w_ktora_strone = false;
            aktualne.R++;
        }
    }
    else if (w_ktora_strone == false)
    {
        CObiekt *pom = mapa->Get_co_jest_na_mapie(aktualne.R+1,aktualne.K);
        if (pom == NULL || pom->czy_mozna_we_mnie_wejsc())
        {
            aktualne.R++;
        }
        else
        {
            w_ktora_strone = true;
            aktualne.R--;
        }
    }

    Set_koordynaty(aktualne);

    return aktualne;

}

SKoordynaty_obiektu CAgent::do_Ruchu_dla_poziomych(CMapa* mapa)
{
    SKoordynaty_obiektu aktualne = Get_koordynaty();
    if(w_ktora_strone == true)
    {
        CObiekt *pom = mapa->Get_co_jest_na_mapie(aktualne.R, aktualne.K - 1);
        if (pom == NULL || pom->czy_mozna_we_mnie_wejsc())
        {
            aktualne.K--;
        }
        else
        {
            w_ktora_strone = false;
            aktualne.K++;
        }
    }
    else if (w_ktora_strone == false)
    {
        CObiekt *pom = mapa->Get_co_jest_na_mapie(aktualne.R, aktualne.K + 1);
        if (pom == NULL || pom->czy_mozna_we_mnie_wejsc())
        {
            aktualne.K++;
        }
        else
        {
            w_ktora_strone = true;
            aktualne.K--;
        }
    }

    Set_koordynaty(aktualne);

    return aktualne;
}
