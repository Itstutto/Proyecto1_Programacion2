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
    Equipo* equipo = nullptr;
    while (getline(archivo, linea)) {
        if (linea.empty()) {
            continue; // Saltar lineas vacias
        }
        buffer.clear();
        buffer.str(linea);
        if (!getline(buffer, tipo, ',')) {
            throw ErrorArchivoCorrupto("Archivo corrupto: no se pudo leer el tipo de equipo");
        }
        if (!getline(buffer, datos)) {
            throw ErrorArchivoCorrupto("Archivo corrupto: no se pudo leer los datos del equipo");
        }
        try {
            equipo = crearEquipo(tipo, datos);
        } catch (const exception& e) {
            delete contenedor;
            throw ErrorArchivoCorrupto("Archivo corrupto: " + string(e.what()));
        }


        contenedor->agregarEquipo(equipo);

    }
    return contenedor;
}

Equipo * Leer::crearEquipo(const string &tipo, const string &datos) {
    CreadorEquipos* creador = creadores->getCreador(tipo);
    if (creador == nullptr) {
        throw ErrorArgumentoInvalido("No se posee un creador para el tipo de objeto "+tipo);
    }
    return creador->crearEquipos(datos);
}

void Leer::agregarCreador(CreadorEquipos *creador) {
    if (creador == nullptr) {
        throw ErrorArgumentoInvalido("El creador no puede ser nulo");
    }
    creadores->agregarCreador(creador);
}
