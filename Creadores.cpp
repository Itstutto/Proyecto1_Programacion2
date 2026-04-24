//
// Created by cesar on 23/4/2026.
//

#include "Creadores.h"

Creadores::Creadores() {
    creadores  = new CreadorEquipos*[1];
    tam = 1;

    for (int i = 0; i < tam; i++){
        creadores[i] = nullptr;
    }

}

Creadores::~Creadores() {
    for (int i = 0; i < tam; i++) {
        delete creadores[i];
    }
    delete[] creadores;
}

CreadorEquipos * Creadores::getCreador(string tipo) {
    for (int i = 0; i < tam; i++) {
        if (creadores[i] != nullptr && creadores[i]->getTipo() == tipo) {
            return creadores[i];
        }
    }
    return nullptr;
}

void Creadores::agregarCreador(CreadorEquipos *creador) {
    CreadorEquipos** temp = new CreadorEquipos*[tam + 1];
    for (int i = 0; i < tam; i++) {
        temp[i] = creadores[i];
    }
    temp[tam++] = creador;
    delete[] creadores;
    creadores = temp;
}
