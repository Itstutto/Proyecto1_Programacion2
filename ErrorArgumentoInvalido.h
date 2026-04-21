//
// Created by cesar on 20/4/2026.
//

#ifndef PROYECTO1_ERRORARGUMENTOINVALIDO_H
#define PROYECTO1_ERRORARGUMENTOINVALIDO_H
#include "Error.h"


class ErrorArgumentoInvalido : public Error {
public:
    ErrorArgumentoInvalido(const string& mensaje) : Error(mensaje) {}
};


#endif //PROYECTO1_ERRORARGUMENTOINVALIDO_H