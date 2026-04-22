//
// Created by cesar on 21/4/2026.
//

#include "Simulador.h"

Simulador::Simulador(int diasSimulacion, int totalIncidencias, double sensibilidad) {
    this->reporte = new string[diasSimulacion+1]; // +1 para incluir el estado final
    this->diasSimulacion = diasSimulacion;
    this->contenedor = new ContenedorEquipos();
    this->incidencias = new Incidencias(totalIncidencias, diasSimulacion, sensibilidad);
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
    for (int i=0; i<diasSimulacion; i++) {
        s.clear();
        s<<"Dia "<<i<<":"<<endl;
        incidencias->asignarIncidencias(contenedor);
        s<<incidencias->generarReporte()<<endl;
        reporte[i] = s.str();
    }

    s.clear();
    s<<"Estado final de los equipos:"<<endl;
    s<<contenedor->mostrarEquipos()<<endl;
    reporte[diasSimulacion] = s.str();

}

string Simulador::generarReporte() {
    stringstream s;
    for (int i=0; i<=diasSimulacion; i++) {
        s<<reporte[i]<<endl;
    }
    return s.str();
}




