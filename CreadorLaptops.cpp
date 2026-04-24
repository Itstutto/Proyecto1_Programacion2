//
// Created by yense on 4/24/2026.
//

#include "CreadorLaptops.h"
#include"ErrorArchivoCorrupto.h"

CreadorLaptops::CreadorLaptops() : CreadorEquipos("Laptop"){
}

Equipo * CreadorLaptops::crearEquipos(const string &linea) {
    stringstream s(linea);
    int id;
    string nombre;
    int incidenciasActivas;
    int tiempoInactivo;
    int criticidad;
    bool enUso;
    string buffer;

    getline(s, buffer, ','); // Ignorar el tipo de equipo
    try {
        id = stoi(buffer);
    } catch (const invalid_argument& e) {
        throw ErrorArchivoCorrupto("No se puede crear el objeto");
    }
    getline(s,nombre,',');
    getline(s, buffer, ',');
    try {
        criticidad = stoi(buffer);
    } catch (const invalid_argument& e) {
        throw ErrorArchivoCorrupto("No se puede crear el objeto");
    }
    getline(s, buffer, ',');
    if (buffer == "1") {
        enUso = true;
    } else if (buffer == "0") {
        enUso = false;
    } else {
        throw ErrorArchivoCorrupto("No se puede crear el objeto");
    }
    getline(s, buffer, ',');
    try {
        incidenciasActivas = stoi(buffer);
    } catch (const invalid_argument& e) {
        throw ErrorArchivoCorrupto("No se puede crear el objeto");
    }
    getline(s, buffer, ',');
    try {
        tiempoInactivo = stoi(buffer);
    } catch (const invalid_argument& e) {
        throw ErrorArchivoCorrupto("No se puede crear el objeto");
    }


    Laptops* laptop = new Laptops(id, nombre, criticidad, enUso, incidenciasActivas, tiempoInactivo);

    return laptop;

}
