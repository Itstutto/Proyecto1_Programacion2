//
// Created by cesar on 12/4/2026.
//

#include "Error.h"

Error::Error(string const &mensaje) {
    this->mensaje = mensaje;
}

const char * Error::what() const noexcept {
    return mensaje.c_str();
}
