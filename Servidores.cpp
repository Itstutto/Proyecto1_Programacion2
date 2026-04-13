//
// Created by cesar on 11/4/2026.
//

#include "Servidores.h"


Servidores::Servidores() : Equipo() {
}

Servidores::Servidores(int id, string const &nombre, int incidenciasActivas, int tiempoInactivo, int criticidad, bool enUso) : Equipo(id, nombre, incidenciasActivas, tiempoInactivo, criticidad, enUso){

    //Si la criticidad no está entre 8 y 10, ajustarla (si es menor a 8 ponerla en 8, si es mayor a 10 ponerla en 10)
    if (criticidad < 8) {
        this->criticidad = 8;
    } else if (criticidad > 10) {
        this->criticidad = 10;
    }

    //Si el servidor no está en uso, ajustar el tiempo inactivo a 0 y bajar 5 puntos de criticidad (en este caso si se puede tener una criticidad menor a 8, ya que el servidor no está en uso)
    if (!enUso) {
        this->tiempoInactivo = 0;
        this->criticidad = this->criticidad-5;
    }
}

string Servidores::toString() {
    stringstream ss;
    ss << "ID: " << getId() << endl;
    ss << "Servidor: " << getNombre() << endl;
    ss << "Incidencias Activas: " << getIncidenciasActivas() << endl;
    ss << "Tiempo Inactivo: " << getTiempoInactivo() << " horas" << endl;
    ss << "Criticidad: " << getCriticidad() << endl;
    ss << "Prioridad: " << prioridad() << endl;
    return ss.str();
}

string Servidores::serializar() {
    stringstream ss;
    ss << id<<",Servidor," << getNombre() << "," << getIncidenciasActivas() << "," << getTiempoInactivo() << "," << getCriticidad() << "," << enUso;
    return ss.str();
}
