//
// Created by yense on 4/24/2026.
//

#ifndef PROYECTO1_CREADORCOMPUTADORASESCRITORIO_H
#define PROYECTO1_CREADORCOMPUTADORASESCRITORIO_H
#include "CreadorEquipos.h"
#include <sstream>
#include"ComputadorasEscritorio.h"
using namespace std;

class CreadorComputadorasEscritorio: public CreadorEquipos {
public:
    CreadorComputadorasEscritorio();
    Equipo* crearEquipos(const string& linea) override;
};


#endif //PROYECTO1_CREADORCOMPUTADORASESCRITORIO_H