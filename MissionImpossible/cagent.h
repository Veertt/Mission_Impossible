#ifndef CAGENT_H
#define CAGENT_H
#include "czarzadca_agentow.h"
#include <chrono>

using namespace std::chrono;

class CAgent : public CZarzadca_Agentow
{
private:
    static const system_clock::duration krok;
    system_clock::time_point czas;

public:
    CAgent(int x, int y, bool orientacja);

    virtual Rezultat_Ruchu Ruch(CMapa* mapa);

    SKoordynaty_obiektu do_Ruchu_dla_pionowych(CMapa* mapa);
    SKoordynaty_obiektu do_Ruchu_dla_poziomych(CMapa* mapa);
};

#endif // CAGENT_H


//orientacja = false - oznacza, że agent ma się poruszać pionowo
//orientacja = true - oznacza, że agent ma się poruszać poziomo
// jeśli w_ktora_strone jest true to odejmuje do współrzednej
// jeśli w_ktora_strone jest false to dodaje od współrzędnej
