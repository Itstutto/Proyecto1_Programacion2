#include "MenuSimulacion.h"

#include <iostream>
#include <sstream>

#include "Archivos.h"
#include "ErrorArgumentoInvalido.h"

using namespace std;

void MenuSimulacion::ajustarSensibilidad(Simulador *simulador) const {
    if (simulador->getSimulacionEjecutada()) {
        cout << "No se puede ajustar la sensibilidad despues de ejecutar la simulacion" << endl;
        return;
    }
    double nuevaSensibilidad;
    cout<< "Ingrese la nueva sensibilidad para la asignacion de incidencias (0 a 100): ";
    cin >> nuevaSensibilidad;
    if (cin.fail() || nuevaSensibilidad < 0 || nuevaSensibilidad > 100) {
        cout << "Entrada invalida. La sensibilidad debe ser un numero entre 0 y 100." << endl;
        cin.clear();
        cin.ignore(1000, '\n');
        return;
    }
    try {
        simulador->setSensibilidadIncidencias(nuevaSensibilidad / 100.0); // Convertir a un valor entre 0 y 1
        cout << "Sensibilidad ajustada exitosamente a " << nuevaSensibilidad << "%" << endl;
    }catch (ErrorArgumentoInvalido& e) {
        cout << "Error: " << e.what() << endl;
    }
}

void MenuSimulacion::cargarEquiposDesdeArchivo(Simulador* simulador) const {
    Archivos gestorArchivos;
    ContenedorEquipos* contenedor = nullptr;
    string nombreArchivo;

    cout << "En que archivo se encuentran los equipos?" << endl;
    cin >> nombreArchivo;

    try {
        contenedor = gestorArchivos.cargarEquipos(nombreArchivo);
        simulador->agregarEquipos(contenedor);
        cout << "Equipos cargados exitosamente desde el archivo: " << nombreArchivo << endl;
    } catch (const exception& e) {
        cerr << "Error al cargar el archivo: " << e.what() << endl;
    }
}

void MenuSimulacion::ingresarEquiposManualmente(Simulador* simulador) const {
    Archivos gestorArchivos;
    int cantidadEquipos;

    cout << "Cuantos equipos desea ingresar? ";
    cin >> cantidadEquipos;
    cin.ignore();

    for (int i = 0; i < cantidadEquipos; ++i) {
        string tipo, nombre;
        int id, incidenciasActivas, tiempoInactivo, criticidad;
        bool enUso;

        try {
            cout << "Ingrese el tipo de equipo (Servidor, Laptop, ComputadoraEscritorio, AireAcondicionado, Grabadora, Camara): ";
            getline(cin, tipo);
            cout << "Ingrese el ID del equipo: ";
            cin >> id;
            if (cin.fail()) {
                throw ErrorArgumentoInvalido("ID debe ser un numero entero");
            }

            cout << "Ingrese el nombre del equipo: ";
            cin.ignore();
            getline(cin, nombre);

            cout << "Ingrese las incidencias del equipo: ";
            cin >> incidenciasActivas;
            if (cin.fail()) {
                throw ErrorArgumentoInvalido("Incidencias activas debe ser un numero entero");
            }

            cout << "Ingrese el tiempo inactivo del equipo: ";
            cin >> tiempoInactivo;
            if (cin.fail()) {
                throw ErrorArgumentoInvalido("Tiempo inactivo debe ser un numero entero");
            }

            cout << "Ingrese la criticidad del equipo: ";
            cin >> criticidad;
            if (cin.fail()) {
                throw ErrorArgumentoInvalido("Criticidad debe ser un numero entero");
            }

            cout << "Ingrese si el equipo esta en uso (1 para si, 0 para no): ";
            cin >> enUso;
            if (cin.fail() || (enUso != 0 && enUso != 1)) {
                throw ErrorArgumentoInvalido("En uso debe ser 1 para si o 0 para no");
            }
            cin.ignore();
        } catch (const exception& e) {
            cout << "Error en la entrada: " << e.what() << endl << endl;
            cin.clear();
            cin.ignore(1000, '\n');
            i--;
            continue;
        }

        stringstream ss;
        ss << id << "," << nombre << "," << criticidad << "," << enUso << "," << incidenciasActivas << "," << tiempoInactivo;

        try {
            Equipo* nuevoEquipo = gestorArchivos.crearEquipo(tipo, ss.str());
            simulador->agregarEquipo(nuevoEquipo);
        } catch (const exception& e) {
            cerr << "Error al crear el equipo: " << e.what() << endl;
            i--;
        }
    }
}

void MenuSimulacion::cambiarNombreTecnico(Simulador* simulador) const {
    int id;
    string nuevoNombre;

    cout << simulador->getListaPersonas() << endl;
    cout << "Ingrese el ID del tecnico que desea renombrar: ";
    cin >> id;
    cout << "Ingrese el nuevo nombre del tecnico: ";
    cin.ignore();
    getline(cin, nuevoNombre);

    try {
        simulador->cambiarNombreTecnico(id, nuevoNombre);
    } catch (const ErrorArgumentoInvalido& e) {
        cout << "Error: " << e.what() << endl;
    }
}

