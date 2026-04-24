//
// Created by yense on 4/24/2026.
//

#ifndef PROYECTO1_CREADORCAMARAS_H
#define PROYECTO1_CREADORCAMARAS_H
#include "CreadorEquipos.h"
#include <sstream>
#include "Camaras.h"
using namespace std;
class CreadorCamaras : public CreadorEquipos{
    CreadorCamaras();
    Equipo* crearEquipos(const string& linea) override;
};


#endif //PROYECTO1_CREADORCAMARAS_H