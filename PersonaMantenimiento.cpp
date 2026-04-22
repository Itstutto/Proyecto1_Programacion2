//
// Created by yense on 4/21/2026.
//

#include "PersonaMantenimiento.h"

PersonaMantenimiento::PersonaMantenimiento(string nombre, string id) {
    this->nombre = nombre;
    this->id= id;
}

string PersonaMantenimiento::getNombre() {
    return this->nombre;
}

string PersonaMantenimiento::getId() {
    return this->id;
}

string PersonaMantenimiento::toString() {
    stringstream s;
    s<<"Nombre: "<<nombre<<", Id: "<<id;
    return s.str();
}

string PersonaMantenimiento::serializar() {
    stringstream s;
    s<<nombre<<","<<id;
    return s.str();
}

void PersonaMantenimiento::setNombre(string nombre) {
    this->nombre= nombre;

}

void PersonaMantenimiento::setId(string id) {
    this->id= id;
}
