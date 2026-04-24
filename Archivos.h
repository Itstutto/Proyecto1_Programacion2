//
// Created by cesar on 23/4/2026.
//

#ifndef PROYECTO1_ARCHIVOS_H
#define PROYECTO1_ARCHIVOS_H
#include <iostream>
#include <fstream>
#include <sstream>
#include "Creadores.h"
#include "ContenedorEquipos.h"
using namespace std;

class Archivos {
    Creadores* creadores;
public:
    Archivos();
    ~Archivos();
    static void guardarArchivo(const string& nombreArchivo, const string& reporte);
    ContenedorEquipos* cargarEquipos(const string& nombreArchivo);
    void agregarCreador(CreadorEquipos* creador);
};



#endif //PROYECTO1_ARCHIVOS_H
