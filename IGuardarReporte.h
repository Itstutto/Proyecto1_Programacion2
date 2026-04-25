//
// Created by cesar on 24/4/2026.
//

#ifndef PROYECTO1_IGUARDARREPORTE_H
#define PROYECTO1_IGUARDARREPORTE_H
#include <iostream>
using namespace std;

class IGuardarReporte {
public:
    virtual ~IGuardarReporte() = default;
    virtual void guardarReporte(const string& reporte) = 0;
};


#endif //PROYECTO1_IGUARDARREPORTE_H