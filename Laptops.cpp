//
// Created by yense on 4/13/2026.
//

#include "Laptops.h"

Laptops::Laptops(): Equipo() {
}

Laptops::Laptops(int id, string const &nombre, int criticidad, bool enUso, int incidenciasActivas, int tiempoInactivo): Equipo(id, nombre, incidenciasActivas, tiempoInactivo, criticidad, enUso) {
    //Si la criticidad no está entre 6 y 9, ajustarla (si es menor a 6 ponerla en 6, si es mayor a 9 ponerla en 9
    if (criticidad <6) {
        this->criticidad = 6;
    } else if (criticidad > 9) {
        this->criticidad = 9;
    }
    //Si la laptop no está en uso, ajustar el tiempo inactivo a 0 y bajar 5 puntos de criticidad (en este caso si se puede tener una criticidad menor a 6, ya que la laptop no está en uso)
    if (!enUso) {
        this->tiempoInactivo = 0;
        this->criticidad = this->criticidad-5;
    }
}

string Laptops::toString() {
    stringstream ss;
    ss<< "ID: " << getId() << endl;
    ss << "Laptop: " << getNombre() << endl;
    ss << "Incidencias Activas: " << getIncidenciasActivas() << endl;
    ss << "Tiempo Inactivo: " << getTiempoInactivo() << " horas" << endl;
    ss << "Criticidad: " << getCriticidad() << endl;
    ss << "Prioridad: " << prioridad() << endl;
    return ss.str();
}

string Laptops::serializar() {
    stringstream ss;
    ss << "Laptop," << id << "," << getNombre() << "," << getIncidenciasActivas() << "," << getTiempoInactivo() << "," << getCriticidad() << "," << enUso << endl;
    return ss.str();
}
