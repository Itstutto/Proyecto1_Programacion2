//
// Created by cesar on 24/4/2026.
//

#ifndef PROYECTO1_GUARDARENARCHIVOTEXTO_H
#define PROYECTO1_GUARDARENARCHIVOTEXTO_H
#include "IGuardarReporte.h"
#include <fstream>

class GuardarEnArchivoTexto : public IGuardarReporte{
private:
    string nombreArchivo;
public:
    GuardarEnArchivoTexto(const string& nombreArchivo);
    ~GuardarEnArchivoTexto() override = default;
    void guardarReporte(const string& reporte) override;
};


#endif //PROYECTO1_GUARDARENARCHIVOTEXTO_H