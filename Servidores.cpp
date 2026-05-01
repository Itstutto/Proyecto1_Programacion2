//
// Created by cesar on 11/4/2026.
//

#include "Servidores.h"


Servidores::Servidores() : Equipo() {
}

Servidores::Servidores(int id, string const &nombre, int criticidad, bool enUso, int incidenciasActivas, int tiempoInactivo) : Equipo(id, nombre, incidenciasActivas, tiempoInactivo, criticidad, enUso){

    //Si la criticidad no esta entre 8 y 10, ajustarla (si es menor a 8 ponerla en 8, si es mayor a 10 ponerla en 10)
    if (criticidad < 8) {
        this->criticidad = 8;
    } else if (criticidad > 10) {
        this->criticidad = 10;
    }

    //Si el servidor no esta en uso, ajustar el tiempo inactivo a 0 y bajar 5 puntos de criticidad (en este caso si se puede tener una criticidad menor a 8, ya que el servidor no esta en uso)
    if (!enUso) {
        this->tiempoInactivo = 0;
        this->criticidad = this->criticidad-5;
    }
}

void Servidores::degradar() {
    estado -= 0.5 + (0.3 * getIncidenciasActivas()) + (0.2 * getTiempoInactivo() / 24 );
    //el servidor se degrada un 0.5% cada dia, mas un 0.3% por cada incidencia activa, mas un 0.2% por cada dia que esta inactiva (se divide entre 24 para que sea un porcentaje por hora)
     if (estado < 0) {
         estado = 0;
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
    ss << "Estado: " << estado << "% " << endl;
    ss << (enUso ? "El servidor esta en uso" : "El servidor no esta en uso") << endl;
    return ss.str();
}

string Servidores::serializar() {
    stringstream ss;

    ss << "Servidor," << id << "," << getNombre() << "," << getCriticidad() << "," << enUso << "," << getIncidenciasActivas() << "," << getTiempoInactivo() << endl;
    return ss.str();
}
