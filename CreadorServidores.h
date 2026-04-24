//
// Created by cesar on 23/4/2026.
//

#ifndef PROYECTO1_CREADORSERVIDORES_H
#define PROYECTO1_CREADORSERVIDORES_H
#include "CreadorEquipos.h"
#include <sstream>
#include "Servidores.h"
class CreadorServidores : public CreadorEquipos{
public:
    CreadorServidores();
    Equipo* crearEquipos(const string& linea) override;
};


#endif //PROYECTO1_CREADORSERVIDORES_H