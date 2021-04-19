#include "czarzadca_agentow.h"
#include "cmapa.h"

int CZarzadca_Agentow::ile_agentow = 0;
bool CZarzadca_Agentow::czy_wiemy_gdzie_jest_gracz = false;
SKoordynaty_obiektu CZarzadca_Agentow::wspolrzedne_gracza = {INT_MAX,INT_MAX};

CZarzadca_Agentow::CZarzadca_Agentow(int x, int y, bool orientation):
    CObiekt(x,y)
{
    orientacja = orientation;
    w_ktora_strone = false;
    ktory_agent=ile_agentow;
    ile_agentow++;
    wielkosc_obszaru_poszukiwan = 4;
}

bool CZarzadca_Agentow::czy_mozna_za_pomoca_mnie_przegrac()
{
    return true;
}

void CZarzadca_Agentow::Wyswietl()
{
    cout<<"A";
}

SKoordynaty_obiektu CZarzadca_Agentow::Sprawdzajaca_czy_wiemy_gdzie_jest_gracz(CMapa *mapa)
{
    int ktory_rzad = 0;
    int ktora_kolumna = 0;
    int rlewo = wielkosc_obszaru_poszukiwan;
    int rprawo = wielkosc_obszaru_poszukiwan;
    int kgora = wielkosc_obszaru_poszukiwan;
    int kdol = wielkosc_obszaru_poszukiwan;

    Ustawiajaca_do_kazdego_agenta_widocznosc(rlewo,rprawo,kdol,kgora);

    SKoordynaty_obiektu aktualne = Get_koordynaty();

    //czy_wiemy_gdzie_jest_gracz = false;
    for(int i = aktualne.R-rlewo;i<aktualne.R+rprawo;i++)
    {
        for(int j = aktualne.K-kdol;j<aktualne.K+kgora;j++)
        {
            if(i<mapa->Get_liczba_Wierszy()&&i>=0)
            {
                ktory_rzad = i;
            }
            else
            {
                if(i<0)
                {
                    ktory_rzad = 0;
                }
                else if(i>=mapa->Get_liczba_Wierszy())
                {
                    ktory_rzad = mapa->Get_liczba_Wierszy()-1;
                }
            }

            if(j<mapa->Get_liczba_Kolumn()&&j>=0)
            {
                ktora_kolumna = j;
            }
            else
            {
                if(j<0)
                {
                    ktora_kolumna = 0;
                }
                else if(j>=mapa->Get_liczba_Kolumn())
                {
                    ktora_kolumna = mapa->Get_liczba_Kolumn()-1;
                }
            }

            CObiekt *pom = mapa->Get_co_jest_na_mapie(ktory_rzad,ktora_kolumna);

            if(pom!=NULL&&pom->czy_mozna_mnie_sledzic())
            {
                czy_wiemy_gdzie_jest_gracz = true;
                wspolrzedne_gracza.R = ktory_rzad;
                wspolrzedne_gracza.K = ktora_kolumna;
            }
        }
    }
}

void CZarzadca_Agentow::Ustawiajaca_do_kazdego_agenta_widocznosc(int &rl, int &rp, int &kd, int &kg)
{
    if(orientacja==false&&w_ktora_strone==false)
    {
       kd = 0;
    }

    if(orientacja==false&&w_ktora_strone==true)
    {
        kg = 0;
    }

    if(orientacja==true&&w_ktora_strone==false)
    {
        rl = 0;
    }

    if(orientacja==true&&w_ktora_strone==true)
    {
        rp = 0;
    }
}

/*
niedokończona funkcja
bool CZarzadca_Agentow::Czy_na_pewno_widze_agenta(CMapa *mapa, int rl, int rp, int kg, int kd)
{
    // dla przypadku pionowego
    bool **mapa_widocznosci;
    if(orientacja == false)
    {
        mapa_widocznosci = new bool *[wielkosc_obszaru_poszukiwan];

        for(int i = koordynaty.R-rl; i<koordynaty.R+rp;i++)
        {
            mapa_widocznosci[i] = new bool [];
        }

        for(int i = 0;i<wielkosc_obszaru_poszukiwan;i++)
        {
            for(int j = 0;j<2*wielkosc_obszaru_poszukiwan;j++)
            {
                mapa_widocznosci[i][j] = false;
            }
        }
    }
}
*/
