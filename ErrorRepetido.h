//
// Created by cesar on 12/4/2026.
//

#ifndef PROYECTO1_ERRORREPETIDO_H
#define PROYECTO1_ERRORREPETIDO_H
#include "Error.h"


class ErrorRepetido : public Error{
public:
    explicit ErrorRepetido(string const &mensaje) : Error(mensaje) {}
};


#endif //PROYECTO1_ERRORREPETIDO_H