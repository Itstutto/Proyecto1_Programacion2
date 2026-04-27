//
// Created by cesar on 26/4/2026.
//

#ifndef PROYECTO1_CONVERTIDORGRABADORAS_H
#define PROYECTO1_CONVERTIDORGRABADORAS_H
#include "Convertidor.h"
#include "Grabadoras.h"

class ConvertidorGrabadoras : public Convertidor {
public:
    ConvertidorGrabadoras() : Convertidor("Grabadoras") {}
    ~ConvertidorGrabadoras() override = default;
    Grabadoras* convertirEquipo(Equipo* equipo) override {
        Grabadoras* grabadora = dynamic_cast<Grabadoras*>(equipo);
        return grabadora;
    }
};

#endif //PROYECTO1_CONVERTIDORGRABADORAS_H

