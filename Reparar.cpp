//
// Created by cesar on 22/4/2026.
//

#include "Reparar.h"

void Reparar::repararEquipo(Equipo *equipo, PersonaMantenimiento *persona) {
    stringstream s;

    if (equipo == nullptr || persona == nullptr) {
        throw ErrorPunteroNulo("El equipo o la persona de mantenimiento no pueden ser nulos");
    }

    if (equipo->getIncidenciasActivas() == 0 ) {
        s<<"El trabajador "<<persona->getNombre()<<" no pudo reparar el equipo "<<equipo->getNombre()<<" porque no tiene incidencias activas."<<endl;
    }
    else {
        equipo->reparar();
        s<<"El trabajador "<<persona->getNombre()<<" reparó las incidencias del equipo "<<equipo->getNombre()<<endl;
    }

    reporte = s.str();
}

string Reparar::generarReporte() {
    return reporte;
}
