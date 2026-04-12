//
// Created by cesar on 12/4/2026.
//

#include "ContenedorEquipos.h"

#include "ErrorNoEncontrado.h"

ContenedorEquipos::ContenedorEquipos() {
    tam=100;
    cant = 0;
    equipos = new Equipo*[tam];
    for (int i = 0; i < tam; i++) {
        equipos[i] = nullptr;
    }
}

ContenedorEquipos::~ContenedorEquipos() {
    for (int i = 0; i < cant; i++) {
        delete equipos[i];
        equipos[i] = nullptr;
    }
    delete[] equipos;
    equipos = nullptr;
}

void ContenedorEquipos::agregarEquipo(Equipo *equipo) {
        if (cant >= tam) {
            throw ErrorEspacio("El contenedor de equipos está lleno");
        }
        equipos[cant++] = equipo;

}

void ContenedorEquipos::eliminarEquipo(int id) {
    for (int i = 0; i < cant; i++) {
        if (equipos[i]->getId() == id) {
            delete equipos[i];
            equipos[i] = nullptr;
            //Mover los equipos restantes para llenar el espacio vacío
            for (int j = i; j < cant - 1; j++) {
                equipos[j] = equipos[j + 1];
            }
            equipos[--cant] = nullptr;
            return;
        }
    }
     throw ErrorNoEncontrado("No se encontró un equipo con el ID proporcionado");

}

Equipo * ContenedorEquipos::buscarEquipo(int id) {
    for (int i = 0; i < cant; i++) {
        if (equipos[i]->getId() == id) {
            return equipos[i];
        }
    }
     throw ErrorNoEncontrado("No se encontró un equipo con el ID proporcionado");

}

string ContenedorEquipos::mostrarEquipos() {
    stringstream ss;
    for (int i = 0; i < cant; i++) {
        ss<<"Equipo #"<<i+1<<endl;
        ss << equipos[i]->toString() << endl;
        ss<<"----------------------------------------------"<<endl;
    }
    return ss.str();

}

string ContenedorEquipos::serializar() {
    stringstream ss;
    for (int i = 0; i < cant; i++) {
        ss << equipos[i]->serializar() << endl;
    }
    return ss.str();
}
