//
// Created by cesar on 11/4/2026.
//

#ifndef PROYECTO1_EQUIPO_H
#define PROYECTO1_EQUIPO_H

#include <iostream>
#include "IReporteDelDia.h"
#include <string>
#include <sstream>
using namespace std;

class Equipo : public IReporteDelDia{
protected:
    int id;
    char nombre[50];
    int incidenciasActivas;
    //Tiempo inactivo en horas
    int tiempoInactivo;
    int criticidad;
    bool enUso;
    //si el equipo esta siendo utilizado, si es false no aumenta tiempo inactivo y se baja criticidad
    //(es menos critico en una oficina un equipo que no se usa)
    bool danado;
    //si el equipo esta danado, aumenta tiempo inactivo , no se modifica criticidad

    string *reporte;
    int diasReporte;
public:
    Equipo();
    Equipo(int id,string const &nombre, int incidenciasActivas = 0, int tiempoInactivo = 0, int criticidad = 0, bool enUso = false);
    virtual ~Equipo() = default;

    float prioridad();

    int getId();
    string getNombre();
    int getIncidenciasActivas();
    int getTiempoInactivo();
    int getCriticidad();
    bool getUso();
    bool getDanado();

    void setId(int id);
    void setNombre(string const &nombre);

    void agregarIncidencia();
    void reparar();

    void agregarTiempoInactivo();
    void eliminarTiempoInactivo();

    void agregarDiaReporte();

    void setCriticidad(int criticidad);
    void setUso(bool enUso);

    virtual  string toString() = 0;
    virtual string serializar() = 0;

    string infoBasica();
    string generarReporte() override;
};



#endif //PROYECTO1_EQUIPO_H
