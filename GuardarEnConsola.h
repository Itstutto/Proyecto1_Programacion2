//
// Created by cesar on 24/4/2026.
//

#ifndef PROYECTO1_GUARDARENCONSOLA_H
#define PROYECTO1_GUARDARENCONSOLA_H
#include "IGuardarReporte.h"


class GuardarEnConsola : public IGuardarReporte {
public:
    ~GuardarEnConsola() override = default;
    void guardarReporte(const string& reporte) override{
        cout << reporte << endl;
    }

};

#endif //PROYECTO1_GUARDARENCONSOLA_H