//
// Created by cesar on 24/4/2026.
//

#include "Guardar.h"

#include "ErrorArchivoCorrupto.h"
#include "ErrorArgumentoInvalido.h"

Guardar::Guardar(IGuardarReporte *estrategiaGuardado) {
    this->estrategiaGuardado = estrategiaGuardado;
}

Guardar::~Guardar() {
        delete estrategiaGuardado;
}

void Guardar::guardarReporte(const string &reporte) {
    if (estrategiaGuardado == nullptr) {
        throw ErrorArchivoCorrupto("No se ha establecido una estrategia de guardado");
    }

        estrategiaGuardado->guardarReporte(reporte);
}

void Guardar::setGuardado(IGuardarReporte *nuevaEstrategia) {
    if (nuevaEstrategia == nullptr) {
        throw ErrorArgumentoInvalido("La nueva estrategia de guardado no puede ser nula");
    }
    if (estrategiaGuardado) {
        delete estrategiaGuardado;
    }
    this->estrategiaGuardado = nuevaEstrategia;
}