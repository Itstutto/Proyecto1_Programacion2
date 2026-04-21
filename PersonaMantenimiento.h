//
// Created by yense on 4/21/2026.
//

#ifndef PROYECTO1_PERSONAMANTENIMIENTO_H
#define PROYECTO1_PERSONAMANTENIMIENTO_H
#include<iostream>
#include<string>
using namespace std;

class PersonaMantenimiento {
private:
    string nombre;
    string id;
public:
    PersonaMantenimiento(string nombre, string id);
    ~PersonaMantenimiento()= default;

    string getNombre();
    string getId();

    void setNombre(string nombre); //por si acaso, aunque me parece que no son necesarios
    void setId(string id);
};


#endif //PROYECTO1_PERSONAMANTENIMIENTO_H