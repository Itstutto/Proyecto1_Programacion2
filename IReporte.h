//
// Created by cesar on 24/4/2026.
//

#ifndef PROYECTO1_IREPORTEEQUIPOS_H
#define PROYECTO1_IREPORTEEQUIPOS_H
#include <iostream>
using namespace std;

class IReporte {
public:
    virtual ~IReporte() = default;
    virtual string generarReporte() = 0;
};


#endif //PROYECTO1_IREPORTEEQUIPOS_H