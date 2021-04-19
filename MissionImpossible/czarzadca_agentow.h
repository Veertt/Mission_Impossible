#ifndef CZARZADCA_AGENTOW_H
#define CZARZADCA_AGENTOW_H
#include "cobiekt.h"

class CZarzadca_Agentow : public CObiekt
{
protected:
    bool orientacja;
    bool w_ktora_strone;
    int ktory_agent;
    int wielkosc_obszaru_poszukiwan;
public:
    CZarzadca_Agentow(int x, int y, bool orientation);
    static int ile_agentow;
    static bool czy_wiemy_gdzie_jest_gracz;
    static SKoordynaty_obiektu wspolrzedne_gracza;

    virtual Rezultat_Ruchu Ruch(CMapa *mapa)=0;
    void Wyswietl();

    virtual bool czy_mozna_za_pomoca_mnie_przegrac();

    void Sprawdzajaca_czy_wiemy_gdzie_jest_gracz(CMapa *mapa);
    void Ustawiajaca_do_kazdego_agenta_widocznosc(int &rl,int &rp, int &kd, int &kg);
    //bool Czy_na_pewno_widze_agenta(CMapa *mapa,int rl, int rp, int kg, int kd);
};

#endif // CZARZADCA_AGENTOW_H


//orientacja = false - oznacza, że agent ma się poruszać pionowo
//orientacja = true - oznacza, że agent ma się poruszać poziomo
// jeśli w_ktora_strone jest true to odejmuje do współrzednej
// jeśli w_ktora_strone jest false to dodaje od współrzędnej
