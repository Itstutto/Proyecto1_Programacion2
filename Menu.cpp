//
// Created by yense on 4/25/2026.
//

#include "Menu.h"
#include "ErrorArgumentoInvalido.h"
#include"GuardarEnArchivoTexto.h"
#include"GuardarEnConsola.h"

void Menu::menuPrincipal(Simulador* simulador) {
  /*  int op;

    do {
        cout << "--- MENU ---"<<endl;
        cout << "1. Generar Reporte"<<endl;
        cout << "2. Salir"<<endl;
        cout << "Seleccione: ";
        cin >> op;

        try {
            if (cin.fail()) throw "Entrada invalida";

            switch(op) {
                case 1:
                    menuReportes(simulador);
                    break;
                case 2:
                    cout << "Saliendo..."<<endl;
                    break;
                default:
                    throw "Opcion no valida";
            }
        } catch(const char* msg) {
            cout << "Error: " << msg << endl;
            cin.clear();
            cin.ignore(1000, '\n');
        }

    } while(op != 2);*/
}

void Menu::menuFinal(Simulador *simulador) {
    int op;

    do {
        cout << "--- MENU ---"<<endl;
        cout << "1. Generar Reporte"<<endl;
        cout << "2. Salir"<<endl;
        cout << "Seleccione: ";
        cin >> op;

        try {
            if (cin.fail()) throw "Entrada invalida";

            switch(op) {
                case 1:
                    menuReportes(simulador);
                    break;
                case 2:
                    cout << "Saliendo..."<<endl;
                    break;
                default:
                    throw "Opcion no valida";
            }
        } catch(const char* msg) {
            cout << "Error: " << msg << endl;
            cin.clear();
            cin.ignore(1000, '\n');
        }

    } while(op != 2);
}

void Menu::menuReportes(Simulador* simulador) {
    char op;

    do {
        cout << "--- REPORTES ---"<<endl;
        cout << "a. Reporte total"<<endl;
        cout << "b. Reporte rango de dias"<<endl;
        cout << "c. Reporte de equipo"<<endl;
        cout << "d. Volver"<<endl;
        cout << "Seleccione: ";
        cin >> op;

        try {
            switch(op) {
                case 'a': reporteTotal(simulador); break;
                case 'b': reporteRangoDias(simulador); break;
                case 'c': reporteEquipos(simulador); break;
                case 'd': break;
                default: throw "Opcion invalida";
            }
        } catch(const char* msg) {
            cout << "Error: " << msg << endl;
        }

    } while(op != 'd');
}

void Menu::reporteTotal(Simulador* simulador) {

    generarSalida(simulador,simulador->generarReporte());

}

void Menu::reporteRangoDias(Simulador* simulador) {
    int inicio, final;
    char inc, rep, estado;
    bool incluirIncidencias, incluirReparaciones, incluirEstado;
  string reporte;

    cin.ignore();

    cout << "Ingrese el dia inicial : ";
    cin>> inicio;

    cout<<"Ingrese el dia final : ";
    cin>> final;

    cout << "Incluir incidencias? (s/n): ";
    cin >> inc;
    incluirIncidencias = (inc == 's' || inc == 'S');

    cout << "Incluir reparaciones? (s/n): ";
    cin >> rep;
    incluirReparaciones = (rep == 's' || rep == 'S');

    cout << "Incluir estado diario? (s/n): ";
    cin >> estado;
    incluirEstado = (estado == 's' || estado == 'S');
    try {
        reporte = simulador->getReporteDia(inicio, incluirIncidencias, incluirReparaciones, incluirEstado);
        generarSalida(simulador,reporte);
    }catch (const ErrorArgumentoInvalido& e) {
        cout << "Error: " << e.what() << endl;
    }

}

void Menu::reporteEquipos(Simulador* simulador) {


}

void Menu::generarSalida(Simulador* simulador, string contenido) {
    IGuardarReporte* guardador;
    char op;
    cout<<"Elija el formato de salida: "<<endl;
    cout<<"a. Consola"<<endl;
    cout<<"b. Archivo de texto"<<endl;
    cout<<"Seleccione: ";
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
    simulador->setGuardador(guardador);
    simulador->guardarReporte(contenido);
}
