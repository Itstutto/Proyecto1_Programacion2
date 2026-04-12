//
// Created by cesar on 12/4/2026.
//

#ifndef PROYECTO1_ERRORESPACIO_H
#define PROYECTO1_ERRORESPACIO_H
#include <exception>

#include "Error.h"

using namespace std;

class ErrorEspacio : public Error {
public:
    explicit ErrorEspacio(string const &mensaje) : Error(mensaje) {}
};


#endif //PROYECTO1_ERRORESPACIO_H