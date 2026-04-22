//
// Created by cesar on 21/4/2026.
//

#ifndef PROYECTO1_SIMULADOR_H
#define PROYECTO1_SIMULADOR_H
#include "ContenedorEquipos.h"
#include "Incidencias.h"
#include <sstream>
using namespace std;

class Simulador : public IReporteDelDia{
private:

    int diasSimulacion;
    ContenedorEquipos* contenedor;
    Incidencias* incidencias;
    string reporte;

public:
    Simulador(int diasSimulacion = 31, int totalIncidencias = 100, double sensibilidad = 0.7);
    // 31 dias porque existe el dia 0
    ~Simulador();



    void agregarEquipo(Equipo* equipo);



    void ejecutarSimulacion();


    string generarReporte() override;
};


#endif //PROYECTO1_SIMULADOR_H