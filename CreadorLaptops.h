//
// Created by yense on 4/24/2026.
//

#ifndef PROYECTO1_CREADORLAPTOPS_H
#define PROYECTO1_CREADORLAPTOPS_H

#include "CreadorEquipos.h"
#include <sstream>
#include"Laptops.h"
using namespace std;

class CreadorLaptops: public CreadorEquipos {
public:
    CreadorLaptops();
    Equipo* crearEquipos(const string& linea) override;
};


#endif //PROYECTO1_CREADORLAPTOPS_H