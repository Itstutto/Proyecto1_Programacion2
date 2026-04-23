//
// Created by cesar on 11/4/2026.
//

#include "Equipo.h"

#include <cstring>

#include "ErrorContradiccion.h"

Equipo::Equipo() {
    id = 0;
    nombre[0] =  ' ';
    incidenciasActivas = 0;
    tiempoInactivo = 0;
    criticidad = 0;
    enUso = false;
    danado = false;
    reporte = new string[1];
    diasReporte = 0;
}

Equipo::Equipo(int id, string const &nombre, int incidenciasActivas, int tiempoInactivo, int criticidad, bool enUso) {
    if (id < 0) {
        throw invalid_argument("El ID no puede ser negativo");
    }
    this->id = id;
    if (nombre.length() >= sizeof(this->nombre)) {
       throw invalid_argument("El nombre del equipo es demasiado largo");
    }
    strncpy(this->nombre, nombre.c_str(), sizeof(this->nombre) - 1);
    if (incidenciasActivas < 0) {
        throw invalid_argument("El número de incidencias activas no puede ser negativo");
    }
    this->incidenciasActivas = incidenciasActivas;
    if (tiempoInactivo < 0) {
        throw invalid_argument("El tiempo inactivo no puede ser negativo");
    }
    this->tiempoInactivo = tiempoInactivo;
    if (criticidad < 0) {
        throw invalid_argument("La criticidad no puede ser negativa");
    }
    this->criticidad = criticidad;

    this->enUso = enUso;
    danado = false;
    reporte = new string[1];
    diasReporte = 0;
}

float Equipo::prioridad() {
    //Pendiente falta, cantidad de
        return ((float)incidenciasActivas * 0.3) + ((float)tiempoInactivo * 0.2) + ((float)(criticidad<0 ? 0 : criticidad) * 0.5);
}

int Equipo::getId() {
        return id;
}

void Equipo::setId(int id) {
    if (id < 0) {
        throw invalid_argument("El ID no puede ser negativo");
    }
    this->id = id;
}

string Equipo::getNombre() {
        return string(nombre);
}

int Equipo::getIncidenciasActivas() {
    return incidenciasActivas;
}

int Equipo::getTiempoInactivo() {
    return tiempoInactivo;
}

int Equipo::getCriticidad() {
    return (criticidad < 0 ? 0 : criticidad);
}

bool Equipo::getUso() {
    return enUso;
}

bool Equipo::getDanado() {
    return danado;
}

void Equipo::setNombre(string const &nombre) {
    if (nombre.length() >= sizeof(this->nombre)) {
        throw invalid_argument("El nombre del equipo es demasiado largo");
    }
    strncpy(this->nombre, nombre.c_str(), sizeof(this->nombre) - 1);
}

void Equipo::agregarIncidencia() {
    stringstream s;
    incidenciasActivas++;
    if (incidenciasActivas > 3) {
        danado = true;
    }


    s<<"La ha ocurrido una incidencia al equipo "<<endl;
    s<<"Cantidad de incidencias activas: "<<incidenciasActivas<<endl;

    reporte[diasReporte-1] += s.str();


}

void Equipo::reparar() {
    incidenciasActivas = 0; //al reparar se reparan todas sus incidencias
    if (danado) danado = false;
    eliminarTiempoInactivo();
}

void Equipo::agregarTiempoInactivo() {
    if (!danado) {
        throw ErrorContradiccion("No se puede agregar tiempo inactivo a un equipo que no esta dañado");
    }
    tiempoInactivo+=24;
}

void Equipo::eliminarTiempoInactivo() {
    tiempoInactivo = 0;
}

void Equipo::agregarDiaReporte() {
    //aumenta el arreglo reporte en 1
    string * nuevoReporte = new string[diasReporte + 1];
    for (int i = 0; i < diasReporte; i++) {
        nuevoReporte[i] = reporte[i];
    }
    delete[] reporte;
    reporte = nuevoReporte;
    diasReporte++;
}


void Equipo::setCriticidad(int criticidad) {
    if (criticidad < 0) {
        throw invalid_argument("La criticidad no puede ser negativa");
    }
    this->criticidad = criticidad;
}

void Equipo::setUso(bool enUso) {
    if (!enUso && this->enUso) {
        //Tiempo inactivo no significa que el equipo no este en uso (esta en uso pero no esta funcionando), por lo que no se puede ajustar el tiempo inactivo a 0,
        //pero si se puede bajar 5 puntos de criticidad
        this->criticidad = this->criticidad-5;

    }
    if (enUso && !this->enUso) {
        //Si el equipo pasa de no estar en uso a estar en uso, ajustar el tiempo inactivo a 0 y subir 5 puntos de criticidad
        this->criticidad = this->criticidad+5;
    }


    this->enUso = enUso;
}



string Equipo::generarReporte() {
    stringstream s;
    for (int i=0; i<diasReporte; i++) {
        s<<"------------------------Dia "<<i<<"------------------------"<<endl;
        if (reporte[i].empty()) {
            s<<"No ha ocurrido ninguna incidencia en este día."<<endl;
        } else {
            s<<reporte[i]<<endl;
        }
        s<<endl<<endl;
    }

    return s.str();
}
