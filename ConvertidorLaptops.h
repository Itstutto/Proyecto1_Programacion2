//
// Created by cesar on 26/4/2026.
//

#ifndef PROYECTO1_CONVERTIDORLAPTOPS_H
#define PROYECTO1_CONVERTIDORLAPTOPS_H
#include "Convertidor.h"
#include "Laptops.h"

class ConvertidorLaptops : public Convertidor {
public:
        ConvertidorLaptops() : Convertidor("Laptop") {}
    ~ConvertidorLaptops() override = default;
    Laptops* convertirEquipo(Equipo* equipo) override {
        Laptops* laptop = dynamic_cast<Laptops*>(equipo);
        return laptop;
    }
};

#endif //PROYECTO1_CONVERTIDORLAPTOPS_H

