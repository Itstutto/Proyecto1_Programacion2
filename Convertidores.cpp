//
// Created by cesar on 26/4/2026.
//

#include "Convertidores.h"

Convertidores::Convertidores() {
    tam = 0;
    convertidores = new Convertidor*[tam];

}

Convertidores::~Convertidores() {
    for (int i = 0; i < tam; i++) {
        delete convertidores[i];
    }
    delete[] convertidores;
}

void Convertidores::agregarConvertidor(Convertidor *convertidor) {
        Convertidor** nuevoConvertidores = new Convertidor*[tam + 1];
        for (int i = 0; i < tam; i++) {
            nuevoConvertidores[i] = convertidores[i];
        }
        nuevoConvertidores[tam] = convertidor;
        delete[] convertidores;
        convertidores = nuevoConvertidores;
        tam++;
}


Convertidor * Convertidores::getConvertidor(string tipo) {
    for (int i = 0; i < tam; i++) {
        if (convertidores[i]->getTipo() == tipo) {
            return convertidores[i];
        }
    }
    return nullptr;
}
