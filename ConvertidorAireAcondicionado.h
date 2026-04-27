//
// Created by cesar on 26/4/2026.
//

#ifndef PROYECTO1_CONVERTIDORAIREACONDICIONADO_H
#define PROYECTO1_CONVERTIDORAIREACONDICIONADO_H
#include "Convertidor.h"
#include "AireAcondicionado.h"

class ConvertidorAireAcondicionado : public Convertidor {
public:
    ConvertidorAireAcondicionado() : Convertidor("AireAcondicionado") {}
    ~ConvertidorAireAcondicionado() override = default;
    AireAcondicionado* convertirEquipo(Equipo* equipo) override {
        AireAcondicionado* aire = dynamic_cast<AireAcondicionado*>(equipo);
        return aire;
    }
};

#endif //PROYECTO1_CONVERTIDORAIREACONDICIONADO_H

