//
// Created by cesar on 24/4/2026.
//

#ifndef PROYECTO1_IDECORADORREPORTES_H
#define PROYECTO1_IDECORADORREPORTES_H
#include "IReporte.h"
#include "IReporteDelDia.h"


class IDecoradorReportes : public IReporte {
protected:
    IReporte* reporte;
public:
    IDecoradorReportes(IReporte* reporte) {
        this->reporte = reporte;
    };
    ~IDecoradorReportes() override {
        delete reporte;
    };
};


#endif //PROYECTO1_IDECORADORREPORTES_H