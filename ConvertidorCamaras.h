//
// Created by cesar on 26/4/2026.
//

#ifndef PROYECTO1_CONVERTIDORCAMARAS_H
#define PROYECTO1_CONVERTIDORCAMARAS_H
#include "Convertidor.h"
#include "Camaras.h"

class ConvertidorCamaras : public Convertidor {
public:
    ConvertidorCamaras() : Convertidor("Camara") {}
    ~ConvertidorCamaras() override = default;
    Camaras* convertirEquipo(Equipo* equipo) override {
        Camaras* camara = dynamic_cast<Camaras*>(equipo);
        return camara;
    }
};

#endif //PROYECTO1_CONVERTIDORCAMARAS_H

