#include <iostream>

#include "ContenedorEquipos.h"
#include "Equipo.h"
#include "ErrorNoEncontrado.h"
#include "Servidores.h"
using namespace std;
int main() {
    try {
        Servidores* servidor1 = new Servidores(2,"Servidor1", 5, 10, 8, true);
        servidor1->setUso(false);
        Servidores* servidor2 = new Servidores(4,"Servidor2", 3, 5, 9, true);
        Servidores* servidor3= new Servidores(1,"Servidor3", 0, 0, 7, false);
        ContenedorEquipos contenedor;
        contenedor.agregarEquipo(servidor1);
        contenedor.agregarEquipo(servidor2);
        contenedor.agregarEquipo(servidor3);
        cout << contenedor.mostrarEquipos() << endl;
        contenedor.ordenarPorPrioridad();
        cout << contenedor.mostrarEquipos() << endl;
    }catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
    }


    return 0;
}