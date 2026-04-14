#include <iostream>

#include "ContenedorEquipos.h"
#include "Equipo.h"
#include "ErrorNoEncontrado.h"
#include "Servidores.h"
#include "ComputadorasEscritorio.h"
#include "Laptops.h"
#include "AireAcondicionado.h"
#include "Grabadoras.h"
#include "Camaras.h"
using namespace std;

int main() {
    try {
        Servidores* servidor1 = new Servidores(2,"Servidor1", 5, 10, 8, true);
        servidor1->setUso(false);
        Servidores* servidor2 = new Servidores(4,"Servidor2", 3, 5, 9, true);
        Servidores* servidor3= new Servidores(1,"Servidor3", 0, 0, 7, false);
        ComputadorasEscritorio* compuE1 = new ComputadorasEscritorio(5,"ComputadoraEscritorio1", 5, 10, 8, true);
        Laptops* laptop1 = new Laptops(3,"Laptop1", 2, 4, 7, false);
        AireAcondicionado* aire1 = new AireAcondicionado(6,"AireAcondicionado1", 5, 3, 6, true);
        Grabadoras* grabadora1 = new Grabadoras(7,"Grabadora1", 1, 2, 3, false);
        Camaras* camara1 = new Camaras(8,"Camara1", 0, 0, 2, true);

        ContenedorEquipos contenedor;
        contenedor.agregarEquipo(servidor1);
        contenedor.agregarEquipo(servidor2);
        contenedor.agregarEquipo(servidor3);
        contenedor.agregarEquipo(compuE1);
        contenedor.agregarEquipo(laptop1);
        contenedor.agregarEquipo(aire1);
        contenedor.agregarEquipo(grabadora1);
        contenedor.agregarEquipo(camara1);

        cout << contenedor.mostrarEquipos() << endl;
        contenedor.ordenarPorPrioridad();
        cout << contenedor.mostrarEquipos() << endl;
    }catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
    }


    return 0;
}