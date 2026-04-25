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
#include "Guardar.h"
#include "Leer.h"
#include "CreadorServidores.h"
#include "CreadorLaptops.h"
#include "CreadorComputadorasEscritorio.h"
#include "CreadorAireAcondicionado.h"
#include "CreadorGrabadoras.h"
#include "CreadorCamaras.h"
#include "ErrorArgumentoInvalido.h"
#include "ErrorArchivoCorrupto.h"

using namespace std;

class Archivos {
    Leer lector;
    Guardar guardador;
public:
    Archivos();
    ~Archivos();
    void guardarArchivo(const string& reporte);
    void agregarGuardador(IGuardarReporte* nuevaEstrategia);
    ContenedorEquipos* cargarEquipos(const string& nombreArchivo);
    void agregarCreador(CreadorEquipos* creador);
};



#endif //PROYECTO1_ARCHIVOS_H
