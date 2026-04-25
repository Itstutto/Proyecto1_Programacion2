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
#include "ReporteEquipos.h"
using namespace std;

int main() {
    Simulador sim(31, 300, 0.1);
    /*
    try {
        Servidores* servidor1 = new Servidores(2,"Servidor1",8, true);
        servidor1->setUso(false);
        Servidores* servidor2 = new Servidores(4,"Servidor2", 8, true);
        Servidores* servidor3= new Servidores(1,"Servidor3", 7);
        ComputadorasEscritorio* compuE1 = new ComputadorasEscritorio(5,"ComputadoraEscritorio1", 8, true);
        Laptops* laptop1 = new Laptops(3,"Laptop1", 7);
        AireAcondicionado* aire1 = new AireAcondicionado(6,"AireAcondicionado1", 6, true);
        Grabadoras* grabadora1 = new Grabadoras(7,"Grabadora1", 3);
        Camaras* camara1 = new Camaras(8,"Camara1", 2, true);


        sim.agregarEquipo(servidor1);
        sim.agregarEquipo(servidor2);
        sim.agregarEquipo(servidor3);
        sim.agregarEquipo(compuE1);
        sim.agregarEquipo(laptop1);
        sim.agregarEquipo(aire1);
        sim.agregarEquipo(grabadora1);
        sim.agregarEquipo(camara1);


    }catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
    }
*/
    Archivos gestorArchivos;
    ContenedorEquipos* contenedor = nullptr;
    try {
        contenedor = gestorArchivos.cargarEquipos("equipos.txt");
        sim.setEquipos(contenedor);
    } catch (const exception& e) {
        cerr << "Error al cargar el archivo: " << e.what() << endl;
        return 1; // Salir con código de error
    }
    sim.ejecutarSimulacion();
    string reporteCompleto = sim.generarReporte();
    IGuardarReporte* guardador = new GuardarEnArchivoTexto("reporte.txt");
    gestorArchivos.agregarGuardador(guardador);
     try {
        gestorArchivos.guardarArchivo(reporteCompleto);
    } catch (const exception& e) {
        cerr << "Error al guardar el archivo: " << e.what() << endl;
    }



    return 0;
}