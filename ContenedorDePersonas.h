//
// Created by cesar on 22/4/2026.
//

#ifndef PROYECTO1_CONTENEDORDEPERSONAS_H
#define PROYECTO1_CONTENEDORDEPERSONAS_H
#include "PersonaMantenimiento.h"

class ContenedorDePersonas {
private:
    PersonaMantenimiento * personas[3];
    int cant;
    int tam;
public:
    ContenedorDePersonas();
    ~ContenedorDePersonas();
    void agregarPersona(PersonaMantenimiento* persona);
    PersonaMantenimiento* getPersona(const int indice);
    void nuevoDiaPersonas();
    string mostarListaPersonas();

};


#endif //PROYECTO1_CONTENEDORDEPERSONAS_H