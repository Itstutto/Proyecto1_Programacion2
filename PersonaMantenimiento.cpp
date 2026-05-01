//
// Created by yense on 4/21/2026.
//

#include "PersonaMantenimiento.h"

PersonaMantenimiento::PersonaMantenimiento(string nombre, string id) {
    this->nombre = nombre;
    this->id= id;
    diasReporte = 0;
    reporte = new string[0];
}

PersonaMantenimiento::~PersonaMantenimiento() {
    delete[] reporte;
    reporte = nullptr;
}

string PersonaMantenimiento::getNombre() {
    return this->nombre;
}

string PersonaMantenimiento::getId() {
    return this->id;
}

string PersonaMantenimiento::toString() {
    stringstream s;
    s<<"Nombre: "<<nombre<<", Id: "<<id;
    return s.str();
}

string PersonaMantenimiento::serializar() {
    stringstream s;
    s<<nombre<<","<<id;
    return s.str();
}

void PersonaMantenimiento::setNombre(string nombre) {
    this->nombre= nombre;

}

void PersonaMantenimiento::setId(string id) {
    this->id= id;
}

void PersonaMantenimiento::reporteReparacion(Equipo *equipo) {
    stringstream s;
    s<<"Reparacion del equipo "<<equipo->getId()<<" - "<<equipo->getNombre()<<endl;
    s<<"Estado del equipo al inicio de la reparacion: "<<setprecision(4)<<equipo->prioridad()<<"%"<<endl;
    s<<"Tiempo inactivo del equipo al inicio de la reparacion: "<<equipo->getTiempoInactivo()<<" horas"<<endl;
    s<<"Incidencias activas del equipo al inicio de la reparacion: "<<equipo->getIncidenciasActivas()<<endl;
    reporte[diasReporte-1] += s.str();
}

void PersonaMantenimiento::nuevoReporte() {
    string* nuevoReporte = new string[diasReporte+1];
     for (int i = 0; i < diasReporte; i++) {
         nuevoReporte[i] = reporte[i];
     }
     delete[] reporte;
     reporte = nuevoReporte;
     diasReporte++;
}

string PersonaMantenimiento::generarReporte() {
    stringstream s;
    s<<"Reporte del tecnico "<<nombre<<" - "<<id<<endl<<endl;
    for (int i=0; i<diasReporte; i++) {
        s<<"------------------------Dia "<<i<<"------------------------"<<endl;
        if (reporte[i].empty()) {
            s<<"No ha realizado ninguna reparacion en este dia."<<endl;
        } else {
            s<<reporte[i]<<endl;
        }
    }
    return s.str();
}
