#include "cgra.h"

CGra::CGra()
{
    cout<<"Opracowal: Bartlomiej Gus gr.IPAUT-151 nr albumu: 297415"<<endl;
    cout<<"Witaj w MissionImpossible!"<<endl;

    koniec.czy_wygrales = false;
    koniec.czy_przegrales = false;

    do
    {
        Wyswietl_aktualna();
        Ruch_obiektow();
        Ustawienie_obiektow();
    }
    while(koniec.czy_wygrales == false&&koniec.czy_przegrales == false);

    if(koniec.czy_wygrales == true)
    {
        Wyswietl_aktualna();
        cout<<"Brawo, wygrales!";
    }
    else if(koniec.czy_przegrales == true)
    {
        Wyswietl_aktualna();
        cout<<"Niestety przegrales.";
    }
}

void CGra::Wyswietl_aktualna()
{
    gotoxy(0,2);
    map.Wyswietl();
}

void CGra::Ruch_obiektow()
{
    for(int i = 0;i<map.Get_liczba_Wierszy();i++)
    {
        for(int j = 0;j<map.Get_liczba_Kolumn();j++)
        {
            CObiekt *pom = map.Get_co_jest_na_mapie(i,j);

            if(pom!=NULL)
            {
                Rezultat_Ruchu rezultat_aktualny = pom->Ruch(&map);

                if(rezultat_aktualny==Przegrana)
                {
                    koniec.czy_przegrales = true;
                    return;
                }
                else if(rezultat_aktualny==Wygrana)
                {
                    koniec.czy_wygrales = true;
                    return;
                }
            }
        }
    }
}

void CGra::Ustawienie_obiektow()
{
    for(int i = 0;i<map.Get_liczba_Wierszy();i++)
    {
        for(int j = 0;j<map.Get_liczba_Kolumn();j++)
        {
            CObiekt *pom = map.Get_co_jest_na_mapie(i,j);

            if(pom!=NULL)
            {
                SKoordynaty_obiektu koordynaty_obiektu_na_mapie;
                koordynaty_obiektu_na_mapie.R = i;
                koordynaty_obiektu_na_mapie.K = j;

                SKoordynaty_obiektu koordynaty_obiektu_w_obiekcie = pom->Get_koordynaty();

                if(koordynaty_obiektu_w_obiekcie.R!=i||koordynaty_obiektu_w_obiekcie.K!=j)
                {
                    map.Set_na_mape(koordynaty_obiektu_w_obiekcie,pom);
                    map.Set_na_mape(koordynaty_obiektu_na_mapie,NULL);
                }
            }
        }
    }
}

void gotoxy( int x, int y )
{
    COORD c;
    c.X = x;
    c.Y = y;
    SetConsoleCursorPosition( GetStdHandle( STD_OUTPUT_HANDLE ), c );
}
