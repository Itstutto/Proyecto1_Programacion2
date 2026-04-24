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
    this->diasSimulacion = diasSimulacion;
    this->contenedor = new ContenedorEquipos();
    this->incidencias = new Incidencias(totalIncidencias, diasSimulacion, sensibilidad);
    this->reparacion = new Reparar();
    this->contenedorPersonas = new ContenedorDePersonas();
    contenedorPersonas->agregarPersona(new PersonaMantenimiento("Tecnico1","1"));
    contenedorPersonas->agregarPersona(new PersonaMantenimiento("Tecnico2","2"));
    contenedorPersonas->agregarPersona(new PersonaMantenimiento("Tecnico3","3"));

}

Simulador::~Simulador() {


    delete contenedor;
    delete incidencias;
    delete[] reporte;
    delete contenedorPersonas;

}

string Simulador::getEquiposSerializados() {
    return contenedor->serializar();
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

}

string Simulador::getReporteDia(int dia, bool incluirIncidencias, bool incluirReparaciones, bool incluirEstadoEquipos) {

    if (dia < 0 || dia > diasSimulacion+1) {
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

string Simulador::getReporteEquipo(int id) {
    //busqueda binaria por id, como el contenedor se ordena por id al final de la simulacion, se puede usar busqueda binaria

    int izquierda = 0;
    int derecha = contenedor->getCant() - 1;

    while (izquierda <= derecha) {
        int medio = izquierda + (derecha - izquierda) / 2;
        Equipo* equipo = contenedor->buscarEquipoIndice(medio);
        if (equipo->getId() == id) {
            return equipo->generarReporte();
        }
        else if (equipo->getId() < id) {
            izquierda = medio + 1;
        }
        else {
            derecha = medio - 1;
        }
    }
        throw ErrorNoEncontrado("No se encontró un equipo con el ID proporcionado");

}

string Simulador::generarReporte() {
    stringstream s;
    for (int i=0; i<=diasSimulacion; i++) {
        for (int j=0; j<3; j++) {
            if (!reporte[i][j].empty()) {
                s<<"------------------------Dia "<<i<<"------------------------"<<endl;
                if (j == 0) {
                    s<<"Incidencias:"<<endl;
                } else if (j == 1) {
                    s<<"Reparaciones:"<<endl;
                } else if (j == 2) {
                    s<<"Estado de los equipos:"<<endl;
                }
                s<<reporte[i][j]<<endl;
            }
        }
    }
    return s.str();
}




