//
// Created by cesar on 26/4/2026.
//

#include "FabricaConvertidores.h"
#include "ConvertidorServidores.h"
#include "ConvertidorComputadorasEscritorio.h"
#include "ConvertidorAireAcondicionado.h"
#include "ConvertidorCamaras.h"
#include "ConvertidorLaptops.h"
#include "ConvertidorGrabadoras.h"


void FabricaConvertidores::cargarConvertidores(Convertidores *convertidores) {
    convertidores->agregarConvertidor(new ConvertidorServidores());
    convertidores->agregarConvertidor(new ConvertidorComputadorasEscritorio());
    convertidores->agregarConvertidor(new ConvertidorAireAcondicionado());
    convertidores->agregarConvertidor(new ConvertidorCamaras());
    convertidores->agregarConvertidor(new ConvertidorLaptops());
    convertidores->agregarConvertidor(new ConvertidorGrabadoras());
}