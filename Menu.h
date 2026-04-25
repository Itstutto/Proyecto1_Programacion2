//
// Created by yense on 4/25/2026.
//

#ifndef PROYECTO1_MENU_H
#define PROYECTO1_MENU_H
#include<iostream>
#include<string>
#include"Simulador.h"

using namespace std;

class Menu {
public:
    void menuPrincipal(Simulador* simulador);
    void menuFinal(Simulador* simulador);
private:
    void menuReportes(Simulador* simulador);

    void reporteTotal(Simulador* simulador);
    void reporteRangoDias(Simulador* simulador);
    void reporteEquipos(Simulador* simulador);

    void generarSalida(Simulador* simulador, string contenido);
};


#endif //PROYECTO1_MENU_H