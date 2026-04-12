//
// Created by cesar on 11/4/2026.
//

#ifndef PROYECTO1_EQUIPO_H
#define PROYECTO1_EQUIPO_H

#include <iostream>
#include <string>
using namespace std;

class Equipo {
protected:
    char nombre[50];
    int incidenciasActivas;
    //Tiempo inactivo en horas
    int tiempoInactivo;
    int criticidad;
    bool enUso;
public:
    Equipo();
    Equipo(string const &nombre, int incidenciasActivas = 0, int tiempoInactivo = 0, int criticidad = 0, bool enUso = false);
    virtual ~Equipo() = default;

    float prioridad();

    string getNombre();
    int getIncidenciasActivas();
    int getTiempoInactivo();
    int getCriticidad();
    bool getUso();

    void setNombre(string const &nombre);
    void setIncidenciasActivas(int incidencias);
    void setTiempoInactivo(int tiempoInactivo);
    void setCriticidad(int criticidad);
    void setUso(bool enUso);

    virtual  string toString() = 0;
    virtual string serializar() = 0;
};


#endif //PROYECTO1_EQUIPO_H