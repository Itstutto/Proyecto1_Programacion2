//
// Created by cesar on 21/4/2026.
//

#include "Simulador.h"

Simulador::Simulador(int diasSimulacion, int totalIncidencias, double sensibilidad) {
    this->reporte = " ";
    this->diasSimulacion = diasSimulacion;
    this->contenedor = new ContenedorEquipos();
    this->incidencias = new Incidencias(totalIncidencias, diasSimulacion, sensibilidad);
}

Simulador::~Simulador() {
    delete contenedor;
    delete incidencias;

}

void Simulador::agregarEquipo(Equipo *equipo) {
    contenedor->agregarEquipo(equipo);
}

void Simulador::ejecutarSimulacion() {
    stringstream s;
    for (int i=0; i<diasSimulacion; i++) {
        s<<"Dia "<<i<<":"<<endl;
        incidencias->asignarIncidencias(contenedor);
        s<<incidencias->generarReporte()<<endl;
    }
    reporte += s.str();

}

string Simulador::generarReporte() {
        return reporte;
}




