//
// Created by cesar on 24/4/2026.
//

#ifndef PROYECTO1_DECORADORRE_H
#define PROYECTO1_DECORADORRE_H
#include "IDecoradorReportes.h"


class DecoradorRE : public IDecoradorReportes {
private:
    IReporteDelDia* reporteEquipo;
public:
    DecoradorRE(IReporteDelDia* reporteEquipo, IReporte* reporte) : IDecoradorReportes(reporte) {
        this->reporteEquipo = reporteEquipo;
    }

    ~DecoradorRE() = default; //Esto guarda un equipo dentro de reporteEquipo, no es dueño de ese equipo, por lo que no debe eliminarlo

    string generarReporte() override {
        return reporteEquipo->generarReporte() + reporte->generarReporte();
    }

};


#endif //PROYECTO1_DECORADORRE_H