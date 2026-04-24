//
// Created by yense on 4/24/2026.
//

#ifndef PROYECTO1_CREADORAIREACONDICIONADO_H
#define PROYECTO1_CREADORAIREACONDICIONADO_H
#include "CreadorEquipos.h"
#include <sstream>
#include "AireAcondicionado.h"
using namespace std;

class CreadorAireAcondicionado : public CreadorEquipos{
public:
    CreadorAireAcondicionado();
    Equipo* crearEquipos(const string& linea) override;
};


#endif //PROYECTO1_CREADORAIREACONDICIONADO_H