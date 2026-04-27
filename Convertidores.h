//
// Created by cesar on 26/4/2026.
//

#ifndef PROYECTO1_CONVERTIDORES_H
#define PROYECTO1_CONVERTIDORES_H
#include "Convertidor.h"

class Convertidores {
private:
    Convertidor** convertidores;
    int tam;
public:
    Convertidores();
    ~Convertidores();
    void agregarConvertidor(Convertidor* convertidor);
    Convertidor* getConvertidor(string tipo);
};


#endif //PROYECTO1_CONVERTIDORES_H