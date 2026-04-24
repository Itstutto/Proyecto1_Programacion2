//
// Created by yense on 4/24/2026.
//

#ifndef PROYECTO1_CREAADORGRABADORAS_H
#define PROYECTO1_CREAADORGRABADORAS_H
#include "CreadorEquipos.h"
#include <sstream>
#include "Grabadoras.h"
using namespace std;
class CreadorGrabadoras : public CreadorEquipos{
public:
    CreadorGrabadoras();
    Equipo* crearEquipos(const string& linea) override;
};


#endif //PROYECTO1_CREAADORGRABADORAS_H