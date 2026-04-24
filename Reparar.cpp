//
// Created by cesar on 22/4/2026.
//

#include "Reparar.h"

bool Reparar::repararEquipo(Equipo *equipo, PersonaMantenimiento *persona) {
    stringstream s;

    if (equipo == nullptr || persona == nullptr) {
        throw ErrorPunteroNulo("El equipo o la persona de mantenimiento no pueden ser nulos");
    }

    if (equipo->getIncidenciasActivas() == 0 ) {
        s<<"El trabajador "<<persona->getNombre()<<" al revisar "<<equipo->getNombre()<<" no encontró ninguna incidencia activa, por lo que procedio a revisar el siguiente equipo."<<endl;
        reporte = s.str();
        return false;
    }
    else {
        equipo->reparar();
        s<<"El trabajador "<<persona->getNombre()<<" reparó las incidencias del equipo "<<equipo->getNombre()<<endl;
        reporte = s.str();
        return true;
    }


}

string Reparar::generarReporte() {
    return reporte;
}
