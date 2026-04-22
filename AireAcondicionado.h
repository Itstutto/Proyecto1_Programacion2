//
// Created by yense on 4/13/2026.
//

#ifndef PROYECTO1_AIREACONDICIONADO_H
#define PROYECTO1_AIREACONDICIONADO_H


#include "Equipo.h"
#include <iostream>
#include <sstream>
using namespace std;

/*
 * Niveles de criticidad(1-10)
 * 1-3: Baja
 * 4-7: Media
 * 8-10: Alta
 * Prioridad = (Incidencias Activas * 0.3) + (Tiempo Inactivo * 0.2) + (Criticidad * 0.5)
 * AireAcondicionado criticidad: 5-8;
 */
class AireAcondicionado : public Equipo {
public:
    AireAcondicionado();
    AireAcondicionado(int id, string const &nombre, int criticidad = 0, bool enUso = false, int incidenciasActivas = 0, int tiempoInactivo = 0);
    ~AireAcondicionado() override = default;

    string toString() override;
    string serializar() override;
};


#endif //PROYECTO1_AIREACONDICIONADO_H