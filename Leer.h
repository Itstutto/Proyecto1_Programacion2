//
// Created by cesar on 25/4/2026.
//

#ifndef PROYECTO1_LEER_H
#define PROYECTO1_LEER_H
#include "Creadores.h"
#include "ContenedorEquipos.h"
#include "ErrorArchivoCorrupto.h"
#include "ErrorArgumentoInvalido.h"
#include <iostream>
#include <fstream>
using namespace std;
class Leer {
private:
    Creadores* creadores;
public:
    Leer();
    ~Leer();
    ContenedorEquipos* cargarEquipos(const string& nombreArchivo);
    Equipo* crearEquipo(const string& tipo, const string& datos);
    void agregarCreador(CreadorEquipos* creador);
};


#endif //PROYECTO1_LEER_H