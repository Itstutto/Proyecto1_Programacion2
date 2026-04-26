//
// Created by cesar on 21/4/2026.
//

#include "Simulador.h"

#include "ErrorArgumentoInvalido.h"

Simulador::Simulador(int diasSimulacion, int totalIncidencias, double sensibilidad) {
    this->reporte = new string * [diasSimulacion+1];// +1 para incluir el estado final
    for (int i=0; i<=diasSimulacion; i++) {
        reporte[i] = new string[3];
    }
    this->simulacionEjecutada = false;
    this->diasSimulacion = diasSimulacion;
    this->contenedor = new ContenedorEquipos();
    this->incidencias = new Incidencias(totalIncidencias, diasSimulacion, sensibilidad);
    this->reparacion = new Reparar();
    this->contenedorPersonas = new ContenedorDePersonas();
    contenedorPersonas->agregarPersona(new PersonaMantenimiento("Tecnico1","1"));
    contenedorPersonas->agregarPersona(new PersonaMantenimiento("Tecnico2","2"));
    contenedorPersonas->agregarPersona(new PersonaMantenimiento("Tecnico3","3"));
    //craeadores de gesto


}

Simulador::~Simulador() {
    delete contenedor;
    delete incidencias;
    delete reparacion;
    for (int i=0; i<=diasSimulacion; i++) {
        delete[] reporte[i];
    }
    delete[] reporte;
    delete contenedorPersonas;

}

string Simulador::getListaEquipos() {
    return contenedor->mostrarEquiposLista();
}

string Simulador::getEquiposSerializados() {
    return contenedor->serializar();
}

void Simulador::setEquipos(ContenedorEquipos *nuevoContenedor) {
    if (simulacionEjecutada) {
        throw ErrorArgumentoInvalido("No se pueden cambiar los equipos después de ejecutar la simulación");
    }
    if (nuevoContenedor == nullptr) {
        throw ErrorPunteroNulo("El nuevo contenedor no puede ser nulo");
    }
    delete contenedor;
    contenedor = nuevoContenedor;
}

void Simulador::agregarEquipo(Equipo *equipo) {
    contenedor->agregarEquipo(equipo);
}

void Simulador::agregarPersona(PersonaMantenimiento *persona) {
    contenedorPersonas->agregarPersona(persona);
}

void Simulador::cambiarNombreTecnico(int indice, string nuevoNombre) {

    contenedorPersonas->getPersona(indice)->setNombre(nuevoNombre);

}

void Simulador::ejecutarSimulacion() {
    stringstream s;
    for (int i=0; i<diasSimulacion; i++) {

        contenedor->agregarDiaReporte();

        s.clear();
        s.str("");

        s<<"Dia "<<i<<":"<<endl;
        incidencias->asignarIncidencias(contenedor);
        s<<incidencias->generarReporte()<<endl;

        reporte[i][0] = s.str();
        if (i == 0) {
            reporte[i][1] = "DIA INICIAL, NO SE REPARAN EQUIPOS";
            reporte[i][2] = contenedor->mostrarEquipos();
            continue;
        }

        s.clear();
        s.str("");

        contenedor->ordenarPorPrioridad();
        s<<"Tres equipos mas criticos:"<<endl;
        for (int j=0, k = 0; k<3 && j<contenedor->getCant(); j++) {
            s<<"PRIORIDAD "<<contenedor->buscarEquipoIndice(j)->prioridad()<<endl;
            s<<contenedor->buscarEquipoIndice(j)->infoBasica()<<endl;
            if (reparacion->repararEquipo(contenedor->buscarEquipoIndice(j),contenedorPersonas->getPersona(k))) {
                k++;
            }
            s<<reparacion->generarReporte()<<endl;
        }

        contenedor->aumentarInactividad();
        reporte[i][1]= s.str();
        reporte[i][2] = contenedor->mostrarEquipos();

    }
    contenedor->ordernarPorId();
    s.clear();
    reporte[diasSimulacion][2] = contenedor->mostrarEquipos();
    simulacionEjecutada = true;

}


string Simulador::getReporteDia(int dia, bool incluirIncidencias, bool incluirReparaciones, bool incluirEstadoEquipos) {

    if (dia < 0 || dia > diasSimulacion) {
        throw ErrorArgumentoInvalido("Día fuera de rango");
    }


    stringstream s;
    s<<"Reporte del dia "<<dia<<":"<<endl;
    if (incluirIncidencias) {
        s<<"Incidencias:"<<endl;
        s<<reporte[dia][0]<<endl;
    }
    if (incluirReparaciones) {
        s<<"Reparaciones:"<<endl;
        s<<reporte[dia][1]<<endl;
    }
    if (incluirEstadoEquipos) {
        s<<"Estado de los equipos:"<<endl;
        s<<reporte[dia][2]<<endl;
    }
    return s.str();

}

string Simulador::getReporteRangoDias(int diaInicio, int diaFin, bool incluirIncidencias, bool incluirReparaciones,
    bool incluirEstadoEquipos) {
    stringstream s;
    if (diaInicio < 0 || diaFin > diasSimulacion || diaInicio > diaFin) {
        throw ErrorArgumentoInvalido("Rango de días inválido");
    }

    for (int i=diaInicio; i<=diaFin; i++) {
        s<<getReporteDia(i, incluirIncidencias, incluirReparaciones, incluirEstadoEquipos)<<endl;
    }
    return s.str();
}

IReporteDelDia * Simulador::getReporteEquipo(int idEquipo) {
    Equipo* equipo = contenedor->buscarEquipo(idEquipo);
    if (!equipo) {
        throw ErrorNoEncontrado("No se encontró un equipo con el ID proporcionado");
    }
    return equipo;
}


string Simulador::generarReporte() {
    stringstream s;
    for (int i=0; i<=diasSimulacion; i++) {
        s<<"------------------------Dia "<<i<<"------------------------"<<endl;
        for (int j=0; j<2; j++) {
            if (!reporte[i][j].empty()) {

                if (j == 0) {
                    s<<"Incidencias:"<<endl;
                } else if (j == 1) {
                    s<<"Reparaciones:"<<endl;
                }
                s<<reporte[i][j]<<endl;
            }
        }
    }
    return s.str();
}




