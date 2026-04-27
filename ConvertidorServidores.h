//
// Created by cesar on 26/4/2026.
//

#ifndef PROYECTO1_CONVERTIDORSERVIDORES_H
#define PROYECTO1_CONVERTIDORSERVIDORES_H
#include "Convertidor.h"
#include "Servidores.h"


class ConvertidorServidores : public Convertidor {
public:
    ConvertidorServidores() : Convertidor("Servidor") {}
    ~ConvertidorServidores() override = default;
    Servidores* convertirEquipo(Equipo* equipo) override {
        Servidores* servidor = dynamic_cast<Servidores*>(equipo);
        return servidor;
    }
};


#endif //PROYECTO1_CONVERTIDORSERVIDORES_H