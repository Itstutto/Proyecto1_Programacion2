//
// Created by cesar on 12/4/2026.
//

#ifndef PROYECTO1_CONTENEDOREQUIPOS_H
#define PROYECTO1_CONTENEDOREQUIPOS_H
#include "ErrorEspacio.h"
#include "ErrorNoEncontrado.h"
#include "Equipo.h"
#include <iostream>
#include <sstream>
//Contenedor de equipos, siempre es de tamanio 100
class ContenedorEquipos {
private:
    Equipo** equipos;
    int tam;
    int cant;
    bool ordenadoPorId = false;
public:
    ContenedorEquipos();
    ~ContenedorEquipos();

    void liberarContenedor();

    int getCant();

    void agregarEquipo(Equipo* equipo);
    void eliminarEquipo(int id);
    Equipo* buscarEquipo(int id);
    Equipo* buscarEquipoIndice(int indice);

    string mostrarEquipos();
    string mostrarEquiposLista();
    string serializar();
    string tresEquiposMasPrioritarios();
    string reporteTipoEquipo(string tipo);

    void agregarEquipos(ContenedorEquipos* nuevoContenedor);

    void nuevoDiaEquipos();

    void ordenarPorPrioridad();
    void aumentarInactividad();

    void ordernarPorId();

};



#endif //PROYECTO1_CONTENEDOREQUIPOS_H
