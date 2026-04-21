//
// Created by cesar on 20/4/2026.
//

#ifndef PROYECTO1_ERRORPUNTERONULO_H
#define PROYECTO1_ERRORPUNTERONULO_H
#include "Error.h"

class ErrorPunteroNulo : public Error{
public:
    ErrorPunteroNulo(const string& mensaje) : Error(mensaje) {}
};


#endif //PROYECTO1_ERRORPUNTERONULO_H