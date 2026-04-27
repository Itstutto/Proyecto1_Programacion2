//
// Created by yense on 4/13/2026.
//

#ifndef PROYECTO1_CAMARAS_H
#define PROYECTO1_CAMARAS_H
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
 * Camaras criticidad: 3-6;
 */

class Camaras : public Equipo {
public:
    Camaras();
    Camaras(int id, string const &nombre, int criticidad = 0, bool enUso = false, int incidenciasActivas = 0, int tiempoInactivo = 0);
    ~Camaras() override = default;

    void degradar() override;
    string toString() override;
    string serializar() override;

};


#endif //PROYECTO1_CAMARAS_H