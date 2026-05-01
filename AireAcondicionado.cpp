//
// Created by yense on 4/13/2026.
//

#include "AireAcondicionado.h"

AireAcondicionado::AireAcondicionado(): Equipo() {
}

AireAcondicionado::AireAcondicionado(int id, string const &nombre, int criticidad, bool enUso, int incidenciasActivas, int tiempoInactivo): Equipo(id, nombre, incidenciasActivas, tiempoInactivo, criticidad, enUso) {
    //Si la criticidad no esta entre 5 y 8, ajustarla (si es menor a 5 ponerla en 5, si es mayor a 8 ponerla en 8
    if (criticidad <5) {
        this->criticidad = 5;
    } else if (criticidad > 8) {
        this->criticidad = 8;

        //Si el aire acondicionado no esta en uso, ajustar el tiempo inactivo a 0 y bajar 5 puntos de criticidad (en este caso si se puede tener una criticidad menor a 5, ya que el aire acondicionado no esta en uso)
    } if (!enUso) {
        this->tiempoInactivo = 0;
        this->criticidad = this->criticidad-5;
    }
}

void AireAcondicionado::degradar() {
    estado -= 0.3 + (0.3 * getIncidenciasActivas()) + (0.1 * getTiempoInactivo() / 24);
    //el aire acondicionado se degrada un 0.3% cada dia, mas un 0.3% por cada incidencia activa, mas un 0.1% por cada dia que esta inactiva (se divide entre 24 para que sea un porcentaje por hora)
     if (estado < 0) {
         estado = 0;
     }
}

string AireAcondicionado::toString() {
    stringstream ss;
    ss << "ID: " << getId() << endl;
    ss << "Aire Acondicionado: " << getNombre() << endl;
    ss << "Incidencias Activas: " << getIncidenciasActivas() << endl;
    ss << "Tiempo Inactivo: " << getTiempoInactivo() << " horas" << endl;
    ss << "Criticidad: " << getCriticidad() << endl;
    ss << "Prioridad: " << prioridad() << endl;
    ss << "Estado: " << estado << "% " << endl;
    ss << (enUso ? "El aire acondicionado esta en uso" : "El aire acondicionado no esta en uso") << endl;
    return ss.str();
}

string AireAcondicionado::serializar() {
    stringstream ss;
    ss << "AireAcondicionado," << id << "," << getNombre() << "," << getCriticidad() << "," << enUso << "," << getIncidenciasActivas() << "," << getTiempoInactivo() << endl;
    return ss.str();
}
