//
// Created by yense on 4/13/2026.
//

#ifndef PROYECTO1_LAPTOPS_H
#define PROYECTO1_LAPTOPS_H

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
 * Laptops criticidad: 6-9;
 */
class Laptops: public Equipo {
public:
    Laptops();
    Laptops(int id, string const &nombre, int criticidad = 0, bool enUso = false, int incidenciasActivas = 0, int tiempoInactivo = 0);
    ~Laptops() override = default;

    void degradar() override;
    string toString() override;
    string serializar() override;
};


#endif //PROYECTO1_LAPTOPS_H