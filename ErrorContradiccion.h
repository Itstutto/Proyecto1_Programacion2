//
// Created by cesar on 20/4/2026.
//

#ifndef PROYECTO1_ERRORCONTRADICCION_H
#define PROYECTO1_ERRORCONTRADICCION_H
#include "Error.h"


class ErrorContradiccion : public Error {
public:
     ErrorContradiccion(const string& mensaje) : Error(mensaje) {}
};


#endif //PROYECTO1_ERRORCONTRADICCION_H