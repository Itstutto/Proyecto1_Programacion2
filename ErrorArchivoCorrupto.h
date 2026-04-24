//
// Created by cesar on 23/4/2026.
//

#ifndef PROYECTO1_ERRORARCHIVOCORRUPTO_H
#define PROYECTO1_ERRORARCHIVOCORRUPTO_H
#include "Error.h"

class ErrorArchivoCorrupto : public Error {
public:
    explicit ErrorArchivoCorrupto(const string& mensaje) : Error(mensaje) {}
};


#endif //PROYECTO1_ERRORARCHIVOCORRUPTO_H