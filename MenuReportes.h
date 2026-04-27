#ifndef PROYECTO1_MENUREPORTES_H
#define PROYECTO1_MENUREPORTES_H

#include "SalidaReporte.h"
#include "Simulador.h"

class MenuReportes {
private:
    SalidaReporte& salidaReporte;
    void reporteTotal(Simulador* simulador) const;
    void reporteRangoDias(Simulador* simulador) const;
    void reporteEquipos(Simulador* simulador) const;

public:
    explicit MenuReportes(SalidaReporte& salidaReporte);
    void menuReportes(Simulador* simulador) const;
};

#endif //PROYECTO1_MENUREPORTES_H

