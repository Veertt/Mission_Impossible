#include "cagent.h"
#include "cmapa.h"

const system_clock::duration CAgent::krok = milliseconds(120);

CAgent::CAgent(int x, int y, bool orientacja):
    CZarzadca_Agentow(x,y,orientacja),
    czas(system_clock::now() + krok)
{
}

Rezultat_Ruchu CAgent::Ruch(CMapa* mapa)
{
    auto aktualny_czas = system_clock::now();

    for(int i = Get_koordynaty().R-1; i<=Get_koordynaty().R+1; i++)
    {
       for(int j = Get_koordynaty().K-1; j<=Get_koordynaty().K+1; j++)
       {
            CObiekt* pom = mapa->Get_co_jest_na_mapie(i,j);

            if(pom!=NULL&&pom->czy_mozna_mnie_sledzic())
            {
                return Przegrana;
            }
        }
   }

    if( aktualny_czas > czas )
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
        }

        Set_koordynaty(aktualne);

        for(int i = aktualne.R-1; i<=aktualne.R+1; i++)
        {
           for(int j = aktualne.K-1; j<=aktualne.K+1; j++)
           {
                CObiekt* pom = mapa->Get_co_jest_na_mapie(i,j);

                if(pom!=NULL&&pom->czy_mozna_mnie_sledzic())
                {
                    return Przegrana;
                }
            }
       }

        czas = czas + krok;
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

    return aktualne;
}
