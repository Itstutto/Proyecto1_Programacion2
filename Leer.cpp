//
// Created by cesar on 25/4/2026.
//

#include "Leer.h"

Leer::Leer() {
    this->creadores = new Creadores();

}

Leer::~Leer() {
    delete creadores;
}


ContenedorEquipos* Leer::cargarEquipos(const string &nombreArchivo) {
    ContenedorEquipos* contenedor = new ContenedorEquipos();
    ifstream archivo(nombreArchivo);
    if (!archivo.is_open()) {
        delete contenedor;
        throw Error("No se pudo abrir el archivo para leer");
    }
    string tipo;
    string datos;
    string linea;
    stringstream buffer;
    while (getline(archivo, linea)) {
        if (linea.empty()) {
            continue; // Saltar líneas vacías
        }
        buffer.clear();
        buffer.str(linea);
        if (!getline(buffer, tipo, ',')) {
            throw ErrorArchivoCorrupto("Archivo corrupto: no se pudo leer el tipo de equipo");
        }
        if (!getline(buffer, datos)) {
            throw ErrorArchivoCorrupto("Archivo corrupto: no se pudo leer los datos del equipo");
        }
        CreadorEquipos* creador = creadores->getCreador(tipo);
        if (creador == nullptr) {
            delete contenedor;
            throw ErrorArgumentoInvalido("No se posee un creador para el tipo de objeto "+tipo);
        }

        contenedor->agregarEquipo(creador->crearEquipos(datos));

    }
    return contenedor;
}

void Leer::agregarCreador(CreadorEquipos *creador) {
    if (creador == nullptr) {
        throw ErrorArgumentoInvalido("El creador no puede ser nulo");
    }
    creadores->agregarCreador(creador);
}