//
// Created by cesar on 21/4/2026.
//

#ifndef PROYECTO1_SIMULADOR_H
#define PROYECTO1_SIMULADOR_H
#include "ContenedorEquipos.h"
#include "Incidencias.h"
#include "Reparar.h"
#include <sstream>

#include "ContenedorDePersonas.h"
using namespace std;

class Simulador : public IReporteDelDia{
private:

    int diasSimulacion;
    ContenedorEquipos* contenedor;
    ContenedorDePersonas* contenedorPersonas;
    Incidencias* incidencias;
    string** reporte;
    Reparar* reparacion;

public:
    Simulador(int diasSimulacion = 31, int totalIncidencias = 100, double sensibilidad = 0.7);
    // 31 dias porque existe el dia 0
    ~Simulador();

    string getEquiposSerializados();

    void agregarEquipo(Equipo* equipo);
    void agregarPersona(PersonaMantenimiento* persona);

    void cambiarNombreTecnico(int indice, string nuevoNombre);

    void ejecutarSimulacion();

    string getReporteDia(int dia, bool incluirIncidencias = false, bool incluirReparaciones = false, bool incluirEstadoEquipos = false);
    string getReporteEquipo(int id);

    string generarReporte() override;
};


#endif //PROYECTO1_SIMULADOR_H