//
// Created by cesar on 22/4/2026.
//

#ifndef PROYECTO1_REPARAR_H
#define PROYECTO1_REPARAR_H
#include "PersonaMantenimiento.h"
#include "Equipo.h"
#include "IReporteDelDia.h"
#include "ErrorPunteroNulo.h"

class Reparar : public IReporteDelDia{
    string reporte;
public:
    Reparar() : reporte("") {}
    void repararEquipo(Equipo* equipo, PersonaMantenimiento* persona);
    string generarReporte() override;
};


#endif //PROYECTO1_REPARAR_H