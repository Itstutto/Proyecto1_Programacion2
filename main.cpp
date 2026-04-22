#include <iostream>
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
using namespace std;

int main() {
    Simulador sim(30, 50, 1);

    try {
        Servidores* servidor1 = new Servidores(2,"Servidor1", 0, 0, 8, true);
        servidor1->setUso(false);
        Servidores* servidor2 = new Servidores(4,"Servidor2", 0, 0, 9, true);
        Servidores* servidor3= new Servidores(1,"Servidor3", 0, 0, 7, false);
        ComputadorasEscritorio* compuE1 = new ComputadorasEscritorio(5,"ComputadoraEscritorio1", 0, 0, 8, true);
        Laptops* laptop1 = new Laptops(3,"Laptop1", 0, 0, 7, false);
        AireAcondicionado* aire1 = new AireAcondicionado(6,"AireAcondicionado1", 0, 0, 6, true);
        Grabadoras* grabadora1 = new Grabadoras(7,"Grabadora1", 0, 0, 3, false);
        Camaras* camara1 = new Camaras(8,"Camara1", 0, 0, 2, true);


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


    sim.ejecutarSimulacion();
    cout<<sim.generarReporte()<<endl;

    return 0;
}