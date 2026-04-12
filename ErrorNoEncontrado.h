//
// Created by cesar on 12/4/2026.
//

#ifndef PROYECTO1_ERRORNOENCONTRADO_H
#define PROYECTO1_ERRORNOENCONTRADO_H
#include "Error.h"


class ErrorNoEncontrado : public Error{
public:
    explicit ErrorNoEncontrado(string const &mensaje) : Error(mensaje) {}
};


#endif //PROYECTO1_ERRORNOENCONTRADO_H