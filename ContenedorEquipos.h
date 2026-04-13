//
// Created by cesar on 12/4/2026.
//

#ifndef PROYECTO1_CONTENEDOREQUIPOS_H
#define PROYECTO1_CONTENEDOREQUIPOS_H
#include "ErrorEspacio.h"
#include "Equipo.h"
#include <iostream>
#include <sstream>
//Contenedor de equipos, siempre es de tamanio 100
class ContenedorEquipos {
private:
    Equipo** equipos;
    int tam;
    int cant;
public:
    ContenedorEquipos();
    ~ContenedorEquipos();

    void agregarEquipo(Equipo* equipo);
    void eliminarEquipo(int id);
    Equipo* buscarEquipo(int id);
    string mostrarEquipos();
    string serializar();
    void ordenarPorPrioridad();
};


#endif //PROYECTO1_CONTENEDOREQUIPOS_H