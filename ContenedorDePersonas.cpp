//
// Created by cesar on 22/4/2026.
//

#include "ContenedorDePersonas.h"

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
        throw ErrorEspacio("No se pueden agregar más personas, el contenedor está lleno");
    }
    if (getPersona(persona->getId()) != nullptr) {
        throw ErrorRepetido("No se pueden agregar más personas, ya existe una persona con el mismo id");
    }
    personas[cant] = persona;
    cant++;
}

PersonaMantenimiento * ContenedorDePersonas::getPersona(const string &id) {
    for (int i=0; i<tam; i++) {
        if (personas[i] != nullptr && personas[i]->getId() == id) {
            return personas[i];
        }
    }
    return nullptr;
}
