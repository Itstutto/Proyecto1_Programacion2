#include <iostream>
#include <mutex>
#include <random>

#include "ContenedorEquipos.h"
#include "Equipo.h"
#include "ErrorNoEncontrado.h"
#include "Servidores.h"
#include "ComputadorasEscritorio.h"
#include "Laptops.h"
#include "AireAcondicionado.h"
#include "Grabadoras.h"
#include "Camaras.h"
#include "Incidencias.h"
#include "Simulador.h"
#include "Archivos.h"
#include "CreadorServidores.h"
#include "DecoradorRE.h"
#include "ErrorArchivoCorrupto.h"
#include "GuardarEnArchivoTexto.h"
#include "IReporte.h"
#include "Menu.h"
#include "ReporteEquipos.h"
using namespace std;

//Proyecto 1 de Programación 2 de César Segura y Fernanda Alfaro

int main() {
    Simulador sim(30, 300, 2);
    Menu    menu;
    menu.menuPrincipal(&sim);


    return 0;
}