//
// Created by yense on 4/13/2026.
//

#include "Grabadoras.h"

Grabadoras::Grabadoras(): Equipo() {
}

Grabadoras::Grabadoras(int id, string const &nombre, int incidenciasActivas, int tiempoInactivo, int criticidad,
    bool enUso): Equipo(id, nombre, incidenciasActivas, tiempoInactivo, criticidad, enUso) {
    //Si la criticidad no está entre 4 y 7, ajustarla (si es menor a 4 ponerla en 4, si es mayor a 7 ponerla en 7
    if (criticidad <4) {
        this->criticidad = 4;
    } else if (criticidad > 7) {
        this->criticidad = 7;
    }
    //Si la grabadora no está en uso, ajustar el tiempo inactivo a 0 y bajar 5 puntos de criticidad (en este caso si se puede tener una criticidad menor a 4, ya que la grabadora no está en uso)
    if (!enUso) {
        this->tiempoInactivo = 0;
        this->criticidad = this->criticidad-5;
    }
}

string Grabadoras::toString() {
    stringstream ss;
    ss<< "ID: " << getId() << endl;
    ss << "Grabadora: " << getNombre() << endl;
    ss << "Incidencias Activas: " << getIncidenciasActivas() << endl;
    ss << "Tiempo Inactivo: " << getTiempoInactivo() << " horas" << endl;
    ss << "Criticidad: " << getCriticidad() << endl;
    ss << "Prioridad: " << prioridad() << endl;
    return ss.str();
}

string Grabadoras::serializar() {
    stringstream ss;
    ss << id<<",Grabadora," << getNombre() << "," << getIncidenciasActivas() << "," << getTiempoInactivo() << "," << getCriticidad() << "," << enUso<<endl;
    return ss.str();
}
