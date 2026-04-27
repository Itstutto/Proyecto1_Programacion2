//
// Created by yense on 4/25/2026.
//

#ifndef PROYECTO1_MENU_H
#define PROYECTO1_MENU_H
#include<iostream>
#include<string>
#include"Simulador.h"
#include "MenuSimulacion.h"
#include "MenuReportes.h"
#include "SalidaReporte.h"

using namespace std;

class Menu {
private:
    SalidaReporte salidaReporte;
    MenuSimulacion menuSimulacion;
    MenuReportes menuReportes;
public:
    Menu();
    void menuPrincipal(Simulador* simulador);
    void menuFinal(Simulador* simulador);

};


#endif //PROYECTO1_MENU_H