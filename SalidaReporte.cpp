#include "SalidaReporte.h"

#include <iostream>

#include "Archivos.h"
#include "GuardarEnArchivoTexto.h"
#include "GuardarEnConsola.h"

using namespace std;

void SalidaReporte::generarSalida(const string& contenido) const {
    Archivos gestorArchivos;
    IGuardarReporte* guardador;

    char op;
    cout << "Elija el formato de salida: " << endl;
    cout << "a. Consola" << endl;
    cout << "b. Archivo de texto" << endl;
    cout << "Seleccione: ";
    cin >> op;

    switch (op) {
        case 'a':
            guardador = new GuardarEnConsola();
            break;
        case 'b': {
            string nombreArchivo;
            cout << "Ingrese el nombre del archivo: ";
            cin >> nombreArchivo;
            guardador = new GuardarEnArchivoTexto(nombreArchivo);
            break;
        }
        default:
            cout << "Opcion invalida, se usara consola por defecto." << endl;
            guardador = new GuardarEnConsola();
    }

    gestorArchivos.agregarGuardador(guardador);
    gestorArchivos.guardarArchivo(contenido);
}

