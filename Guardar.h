//
// Created by cesar on 24/4/2026.
//

#ifndef PROYECTO1_GUARDAR_H
#define PROYECTO1_GUARDAR_H
#include "IGuardarReporte.h"


class Guardar {
private:
    IGuardarReporte* estrategiaGuardado;
public:
    Guardar(IGuardarReporte* estrategiaGuardado);
    ~Guardar();
    void setGuardado(IGuardarReporte* nuevaEstrategia);
    void guardarReporte(const string& reporte);

};


#endif //PROYECTO1_GUARDAR_H