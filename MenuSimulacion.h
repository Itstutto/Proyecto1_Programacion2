#ifndef PROYECTO1_MENUSIMULACION_H
#define PROYECTO1_MENUSIMULACION_H

#include "Simulador.h"

class MenuSimulacion {
public:
    void cargarEquiposDesdeArchivo(Simulador* simulador) const;
    void ingresarEquiposManualmente(Simulador* simulador) const;
    void cambiarNombreTecnico(Simulador* simulador) const;
};

#endif //PROYECTO1_MENUSIMULACION_H

