//
// Created by yense on 4/13/2026.
//

#include "Camaras.h"

Camaras::Camaras(): Equipo() {
}

Camaras::Camaras(int id, string const &nombre, int criticidad, bool enUso, int incidenciasActivas, int tiempoInactivo): Equipo(id, nombre, incidenciasActivas, tiempoInactivo, criticidad, enUso) {
    //Si la criticidad no está entre 3 y 6, ajustarla (si es menor a 3 ponerla en 3, si es mayor a 6 ponerla en 6
    if (criticidad <3) {
        this->criticidad = 3;
    } else if (criticidad > 6) {
        this->criticidad = 6;
    }
    //Si la cámara no está en uso, ajustar el tiempo inactivo a 0 y bajar 5 puntos de criticidad (en este caso si se puede tener una criticidad menor a 3, ya que la cámara no está en uso)
    if (!enUso) {
        this->tiempoInactivo = 0;
        this->criticidad = this->criticidad-5;
    }
}

string Camaras::toString() {
    stringstream ss;
    ss<< "ID: " << getId() << endl;
    ss << "Camara: " << getNombre() << endl;
    ss << "Incidencias Activas: " << getIncidenciasActivas() << endl;
    ss << "Tiempo Inactivo: " << getTiempoInactivo() << " horas" << endl;
    ss << "Criticidad: " << getCriticidad() << endl;
    ss << "Prioridad: " << prioridad() << endl;
    return ss.str();
}

string Camaras::serializar() {
    stringstream ss;
    ss << "Camaras," << id << "," << getNombre() << "," << getCriticidad() << "," << enUso << "," << getIncidenciasActivas() << "," << getTiempoInactivo() << endl;
    return ss.str();
}
