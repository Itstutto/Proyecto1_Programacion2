//
// Created by yense on 4/21/2026.
//

#ifndef PROYECTO1_PERSONAMANTENIMIENTO_H
#define PROYECTO1_PERSONAMANTENIMIENTO_H
#include<iostream>
#include <iomanip>
#include<string>
#include <sstream>
#include "IReporteDelDia.h"
#include "Equipo.h"

using namespace std;

class PersonaMantenimiento : public IReporteDelDia {
private:
    string nombre;
    string id;
    string* reporte;
    int diasReporte;
public:
    PersonaMantenimiento(string nombre, string id);
    ~PersonaMantenimiento()= default;

    string getNombre();
    string getId();
    string toString();
    string serializar();

    void setNombre(string nombre); //por si acaso, aunque me parece que no son necesarios
    void setId(string id);
    void reporteReparacion(Equipo* equipo); // se hace el reporte de la reparacion del equipo

    void nuevoReporte();
    string generarReporte() override;
};


#endif //PROYECTO1_PERSONAMANTENIMIENTO_H