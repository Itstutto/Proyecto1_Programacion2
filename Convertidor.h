//
// Created by cesar on 26/4/2026.
//

#ifndef PROYECTO1_CONVERTIDOR_H
#define PROYECTO1_CONVERTIDOR_H
#include "Equipo.h"

class Convertidor {
private:
    string tipo;
public:
    Convertidor(string tipo) : tipo(tipo) {}
    string getTipo() const {
        return tipo;
    }
    virtual ~Convertidor() = default;
    virtual Equipo* convertirEquipo(Equipo* equipo) = 0;
};


#endif //PROYECTO1_CONVERTIDOR_H