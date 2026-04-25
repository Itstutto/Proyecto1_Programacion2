//
// Created by cesar on 23/4/2026.
//

#include "Archivos.h"

#include "ErrorArgumentoInvalido.h"
#include "ErrorArchivoCorrupto.h"
Archivos::Archivos() :  guardador(nullptr) {
     //creadores de gestor
    lector.agregarCreador(new CreadorServidores());
    lector.agregarCreador(new CreadorLaptops());
    lector.agregarCreador(new CreadorComputadorasEscritorio());
    lector.agregarCreador(new CreadorAireAcondicionado());
    lector.agregarCreador(new CreadorGrabadoras());
    lector.agregarCreador(new CreadorCamaras());
}

Archivos::~Archivos() {
}

void Archivos::guardarArchivo(const string &reporte) {
    guardador.guardarReporte(reporte);
}

void Archivos::agregarGuardador(IGuardarReporte *nuevaEstrategia) {
    if (nuevaEstrategia == nullptr) {
        throw ErrorArgumentoInvalido("La estrategia de guardado no puede ser nula");
    }
    guardador.setGuardado(nuevaEstrategia);
}

ContenedorEquipos* Archivos::cargarEquipos(const string &nombreArchivo) {
    ContenedorEquipos* contenedor = lector.cargarEquipos(nombreArchivo);
    if (contenedor == nullptr) {
        throw ErrorArchivoCorrupto("El archivo está corrupto o no tiene el formato correcto");
    }
    return contenedor;
}

void Archivos::agregarCreador(CreadorEquipos *creador) {
    if (creador == nullptr) {
        throw ErrorArgumentoInvalido("El creador no puede ser nulo");
    }
    lector.agregarCreador(creador);
}
