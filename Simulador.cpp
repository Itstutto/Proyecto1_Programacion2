//
// Created by cesar on 21/4/2026.
//

#include "Simulador.h"

#include "ErrorArgumentoInvalido.h"

Simulador::Simulador(int diasSimulacion, int totalIncidencias, double sensibilidad) {
    this->reporte = new string[diasSimulacion+1]; // +1 para incluir el estado final
    this->diasSimulacion = diasSimulacion;
    this->contenedor = new ContenedorEquipos();
    this->incidencias = new Incidencias(totalIncidencias, diasSimulacion, sensibilidad);
    this->reparacion = new Reparar();
}

Simulador::~Simulador() {


    delete contenedor;
    delete incidencias;
    delete[] reporte;
}

void Simulador::agregarEquipo(Equipo *equipo) {
    contenedor->agregarEquipo(equipo);
}

void Simulador::ejecutarSimulacion() {
    stringstream s;
    PersonaMantenimiento* persona1 = new PersonaMantenimiento("Juan Perez", "12345"); //PERSONA TEMPORAL CAMBIAR CUANDO SEA POSIBLE
    for (int i=0; i<diasSimulacion; i++) {

        contenedor->agregarDiaReporte();

        s.clear();
        s.str("");

        s<<"Dia "<<i<<":"<<endl;
        incidencias->asignarIncidencias(contenedor);
        s<<incidencias->generarReporte()<<endl;

        contenedor->ordenarPorPrioridad();
        s<<"Tres equipos mas criticos:"<<endl;
        for (int j=0; j<3 && j<contenedor->getCant(); j++) {
            s<<"PRIORIDAD "<<contenedor->buscarEquipoIndice(j)->prioridad()<<endl;
            s<<contenedor->buscarEquipoIndice(j)->serializar()<<endl;
        }
        for (int j=0; j<3 && j<contenedor->getCant(); j++) {

            reparacion->repararEquipo(contenedor->buscarEquipoIndice(j),persona1);
            s<<reparacion->generarReporte()<<endl;
        }

        contenedor->aumentarInactividad();
        reporte[i] = s.str();

    }

    s.clear();
    delete persona1;
    s<<"Estado final de los equipos:"<<endl;
    s<<contenedor->mostrarEquipos()<<endl;
    reporte[diasSimulacion] = s.str();
    contenedor->ordernarPorId();
}

string Simulador::getReporteDia(int dia) {

    if (dia < 0 || dia > diasSimulacion+1) {
        throw ErrorArgumentoInvalido("Día fuera de rango");
    }
    return reporte[dia];

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
        s<<reporte[i]<<endl;
    }
    return s.str();
}




