//
// Created by cesar on 22/4/2026.
//

#include "ContenedorDePersonas.h"

#include "ErrorArgumentoInvalido.h"
#include "ErrorEspacio.h"
#include "ErrorRepetido.h"

ContenedorDePersonas::ContenedorDePersonas() {
    this->cant = 0;
    this->tam = 3;
    for (int i=0; i<tam; i++) {
        personas[i] = nullptr;
    }
}

ContenedorDePersonas::~ContenedorDePersonas() {
    for (int i=0; i<tam; i++) {
        if (personas[i] != nullptr) {
            delete personas[i];
        }
    }
}

void ContenedorDePersonas::agregarPersona(PersonaMantenimiento *persona) {
    if (cant >= tam) {
        throw ErrorEspacio("No se pueden agregar mas personas, el contenedor esta lleno");
    }
    personas[cant] = persona;
    cant++;
}

PersonaMantenimiento * ContenedorDePersonas::getPersona(const int indice) {
    if (indice < 0 || indice >= cant) {
        throw ErrorArgumentoInvalido("Indice fuera de rango");
    }
    return personas[indice];
}

void ContenedorDePersonas::nuevoDiaPersonas() {
    for (int i=0; i<tam; i++) {
        if (personas[i] != nullptr) {
            personas[i]->nuevoReporte();
        }
    }
}
