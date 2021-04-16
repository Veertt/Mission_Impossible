#ifndef CGRA_H
#define CGRA_H
#include <windows.h>
#include "cmapa.h"
#include "cobiekt.h"

class CGra
{
private:
    struct SCzy_koniec
    {
        bool czy_wygrales;
        bool czy_przegrales;
    };

    SCzy_koniec koniec;
    bool poziom_trudnosci;
    CMapa map;

    void Wyswietl_aktualna();
    void Ruch_obiektow();
    void Ustawienie_obiektow();

public:
    CGra();
};

//funkcja służaca do odświeżania
void gotoxy( int x, int y );

#endif // CGRA_H

