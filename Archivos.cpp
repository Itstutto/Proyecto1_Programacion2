//
// Created by cesar on 23/4/2026.
//

#include "Archivos.h"

#include "ErrorArgumentoInvalido.h"
#include "ErrorArchivoCorrupto.h"
Archivos::Archivos() {
    creadores = new Creadores();
}

Archivos::~Archivos() {
    delete creadores;
}

void Archivos::guardarArchivo(const string &nombreArchivo, const string &reporte) {
    ofstream archivo(nombreArchivo);
    if (!archivo.is_open()) {
        archivo.close();
        throw runtime_error("No se pudo abrir el archivo para escribir");
    }
    archivo << reporte;
    archivo.close();

}

ContenedorEquipos* Archivos::cargarEquipos(const string &nombreArchivo) {
    ContenedorEquipos* contenedor = new ContenedorEquipos();
    ifstream archivo(nombreArchivo);
    if (!archivo.is_open()) {
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

void Archivos::agregarCreador(CreadorEquipos *creador) {
    if (creador == nullptr) {
        throw ErrorArgumentoInvalido("El creador no puede ser nulo");
    }
    creadores->agregarCreador(creador);
}
