#include "cagent.h"
#include "cmapa.h"

CZarzadca_Agentow CAgent::zarzadca;

CAgent::CAgent(int x, int y, bool orientation, int krok_agenta):
    CObiekt(x,y)
{
    orientacja = orientation;
    w_ktora_strone = false;
    ktory_agent=zarzadca.ile_agentow;
    zarzadca.Dodaj_kolejnego_agenta(ktory_agent);
    zarzadca.ile_agentow++;
    wielkosc_obszaru_poszukiwan = 3;

    krok = milliseconds(krok_agenta);
    czas = system_clock::now() + krok;
}

void CAgent::Wyswietl()
{
    cout<<"A";
}

bool CAgent::czy_mozna_za_pomoca_mnie_przegrac()
{
    return true;
}

bool CAgent::czy_mozna_we_mnie_wejsc()
{
    return false;
}

Rezultat_Ruchu CAgent::Ruch(CMapa* mapa) //zmiana
{
    auto aktualny_czas = system_clock::now();

    if( aktualny_czas > czas )
    {
        zarzadca.Sprawdzajaca_czy_wiemy_gdzie_jest_gracz(mapa, wielkosc_obszaru_poszukiwan, Get_koordynaty(),orientacja,w_ktora_strone, ktory_agent);
        zarzadca.Aktualizujaca_czy_na_pewno_nadal_widze_gracza();

        SKoordynaty_obiektu aktualne = Get_koordynaty();

        if(zarzadca.czy_wiemy_gdzie_jest_gracz == false)
        {
            if(wielkosc_obszaru_poszukiwan!=3)
            {
                wielkosc_obszaru_poszukiwan = 3;
            }

            if(orientacja == false)
            {
                aktualne = do_Ruchu_dla_pionowych(mapa);
            }
            else if(orientacja == true)
            {
                aktualne = do_Ruchu_dla_poziomych(mapa);
            }

        }else if(zarzadca.czy_wiemy_gdzie_jest_gracz == true)
        {
            if(wielkosc_obszaru_poszukiwan!=5)
            {
                wielkosc_obszaru_poszukiwan = 5;
            }

            aktualne = mapa->Znajdz_najkrotsza_do_gracza(Get_koordynaty(),zarzadca.wspolrzedne_gracza);
        }

        Set_koordynaty(aktualne);

        for(int i = aktualne.R-1; i<=aktualne.R+1; i++)
        {
           for(int j = aktualne.K-1; j<=aktualne.K+1; j++)
           {
                CObiekt* pom = mapa->Get_co_jest_na_mapie(i,j);

                if(pom!=NULL&&pom->czy_mozna_mnie_sledzic()==true)
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
