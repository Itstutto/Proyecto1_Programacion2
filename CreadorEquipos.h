//
// Created by cesar on 23/4/2026.
//

#ifndef PROYECTO1_CREADOREQUIPOS_H
#define PROYECTO1_CREADOREQUIPOS_H
#include <iostream>
#include  "Equipo.h"
using namespace std;

class CreadorEquipos {
private:
    string tipo;
public:
    CreadorEquipos(string const &tipo) : tipo(tipo) {}
    virtual ~CreadorEquipos() = default;
    string getTipo();
    virtual Equipo* crearEquipos(const string& linea) = 0;

};


#endif //PROYECTO1_CREADOREQUIPOS_H