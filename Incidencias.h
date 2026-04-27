//
// Created by cesar on 20/4/2026.
//

#ifndef PROYECTO1_INCIDENCIAS_H
#define PROYECTO1_INCIDENCIAS_H
#include <iostream>
#include <sstream>
#include "IReporteDelDia.h"
#include <random>

#include "ContenedorEquipos.h"

using namespace std;


class Incidencias : public IReporteDelDia{
private:
    int incidencias; //incidencias que se van asignando
    int incidenciasRestantes; //inicia en la cantidad total de incidencias, a medida que se asignan, va disminuyendo
    int plazo; //plazo en dias para asignar las incidencias, a medida que se acerca el plazo, aumenta la posibilidad de que haya una incidencia
    int diasCompletados; //dias que han pasado desde el inicio del plazo, a medida que se acerca al plazo, aumenta la posibilidad de que haya una incidencia

    double sensibilidad;
    //a mayor sensibilidad, mayor posibilidad de que haya una incidencia, se puede usar para simular
    //diferentes escenarios, por ejemplo, si se tiene equipos muy sensibles, se puede aumentar la
    //sensibilidad para simular que son mas propenso a tener incidencias
    string reporte;

public:

    Incidencias(int incidenciasRestantes = 100, int plazo = 30, double sensibilidad = 0.7);


    void setSensibilidad(double nuevaSensibilidad);

    int calculoIncidencias();
    void asignarIncidencias(ContenedorEquipos* contenedor);

    int getIncidencias();
    int getIncidenciasRestantes();


    string generarReporte() override;



};


#endif //PROYECTO1_INCIDENCIAS_H