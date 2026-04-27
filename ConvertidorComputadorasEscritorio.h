//
// Created by cesar on 26/4/2026.
//

#ifndef PROYECTO1_CONVERTIDORCOMPUTADORASESCRITORIO_H
#define PROYECTO1_CONVERTIDORCOMPUTADORASESCRITORIO_H
#include "Convertidor.h"
#include "ComputadorasEscritorio.h"

class ConvertidorComputadorasEscritorio : public Convertidor {
public:
        ConvertidorComputadorasEscritorio() : Convertidor("ComputadoraEscritorio") {}
    ~ConvertidorComputadorasEscritorio() override = default;
    ComputadorasEscritorio* convertirEquipo(Equipo* equipo) override {
        ComputadorasEscritorio* computadora = dynamic_cast<ComputadorasEscritorio*>(equipo);
        return computadora;
    }
};

#endif //PROYECTO1_CONVERTIDORCOMPUTADORASESCRITORIO_H

