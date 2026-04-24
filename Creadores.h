//
// Created by cesar on 23/4/2026.
//

#ifndef PROYECTO1_CREADORES_H
#define PROYECTO1_CREADORES_H
#include "CreadorEquipos.h"

class Creadores {
private:
    CreadorEquipos** creadores;
    int tam;
public:
    Creadores();
    ~Creadores();

    CreadorEquipos* getCreador(string tipo);
    void agregarCreador(CreadorEquipos* creador);

};


#endif //PROYECTO1_CREADORES_H