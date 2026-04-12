//
// Created by cesar on 11/4/2026.
//

#ifndef PROYECTO1_SERVIDORES_H
#define PROYECTO1_SERVIDORES_H
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
 * Servidor criticidad: 8-10;
 */
class Servidores : public Equipo {
public:
    Servidores();
    Servidores(string const &nombre, int incidenciasActivas = 0, int tiempoInactivo = 0, int criticidad = 0, bool enUso = false);
    ~Servidores() override = default;

    string toString() override;
    string serializar() override;
};


#endif //PROYECTO1_SERVIDORES_H