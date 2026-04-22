//
// Created by cesar on 21/4/2026.
//

#ifndef PROYECTO1_IREPORTEDELDIA_H
#define PROYECTO1_IREPORTEDELDIA_H
#include <string>
using namespace std;

class IReporteDelDia {
public:
    virtual ~IReporteDelDia() = default;
    virtual string generarReporte() = 0;
};


#endif //PROYECTO1_IREPORTEDELDIA_H