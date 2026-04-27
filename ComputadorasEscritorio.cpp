//
// Created by yense on 4/13/2026.
//

#include "ComputadorasEscritorio.h"

ComputadorasEscritorio::ComputadorasEscritorio(): Equipo() {
}

ComputadorasEscritorio::ComputadorasEscritorio(int id, string const &nombre, int criticidad, bool enUso, int incidenciasActivas, int tiempoInactivo) : Equipo(id, nombre, incidenciasActivas, tiempoInactivo, criticidad, enUso) {
        //Si la criticidad no esta entre 7 y 9, ajustarla (si es menor a 7 ponerla en 7, si es mayor a 9 ponerla en 9
    if (criticidad <7) {
        this->criticidad = 7;
    } else if (criticidad > 9) {
        this->criticidad = 9;
    }
    //Si la computadora de escritorio no esta en uso, ajustar el tiempo inactivo a 0 y bajar 5 puntos de criticidad (en este caso si se puede tener una criticidad menor a 7, ya que la computadora de escritorio no esta en uso)
    if (!enUso) {
        this->tiempoInactivo = 0;
        this->criticidad = this->criticidad-5;
    }
}

void ComputadorasEscritorio::degradar() {
    estado -= 0.4 + (0.3 * getIncidenciasActivas()) + (0.2 * getTiempoInactivo());
     if (estado < 0) {
         estado = 0;
     }
}

string ComputadorasEscritorio::toString() {
    stringstream ss;
    ss<< "ID: " << getId() << endl;
    ss << "Computadora de Escritorio: " << getNombre() << endl;
    ss << "Incidencias Activas: " << getIncidenciasActivas() << endl;
    ss << "Tiempo Inactivo: " << getTiempoInactivo() << " horas" << endl;
    ss << "Criticidad: " << getCriticidad() << endl;
    ss << "Prioridad: " << prioridad() << endl;
    return ss.str();
}

string ComputadorasEscritorio::serializar() {
    stringstream ss;
    ss << "ComputadoraEscritorio," << id << "," << getNombre() << "," << getCriticidad() << "," << enUso << "," << getIncidenciasActivas() << "," << getTiempoInactivo() << endl;
    return ss.str();
}
