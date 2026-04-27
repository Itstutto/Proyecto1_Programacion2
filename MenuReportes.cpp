#include "MenuReportes.h"

#include <iostream>

#include "DecoradorRE.h"
#include "ErrorArgumentoInvalido.h"
#include "ErrorNoEncontrado.h"
#include "IReporte.h"
#include "ReporteEquipos.h"

using namespace std;

MenuReportes::MenuReportes(SalidaReporte& salidaReporte) : salidaReporte(salidaReporte) {
}

void MenuReportes::menuReportes(Simulador* simulador) const {
    char op;

    do {
        cout << "--- REPORTES ---" << endl;
        cout << "a. Reporte total" << endl;
        cout << "b. Reporte rango de dias" << endl;
        cout << "c. Reporte de equipo" << endl;
        cout << "d. Volver" << endl;
        cout << "Seleccione: ";
        cin >> op;

        try {
            switch (op) {
                case 'a': reporteTotal(simulador); break;
                case 'b': reporteRangoDias(simulador); break;
                case 'c': reporteEquipos(simulador); break;
                case 'd': break;
                default: throw "Opcion invalida";
            }
        } catch (const char* msg) {
            cout << "Error: " << msg << endl;
        }

    } while (op != 'd');
}

void MenuReportes::reporteTotal(Simulador* simulador) const {
    salidaReporte.generarSalida(simulador->generarReporte());
}

void MenuReportes::reporteRangoDias(Simulador* simulador) const {
    int inicio, final;
    char inc, rep, estado;
    bool incluirIncidencias, incluirReparaciones, incluirEstado;
    string reporte;

    cin.ignore();

    cout << "Ingrese el dia inicial : ";
    cin >> inicio;

    cout << "Ingrese el dia final : ";
    cin >> final;

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
        reporte = simulador->getReporteRangoDias(inicio, final, incluirIncidencias, incluirReparaciones, incluirEstado);
        salidaReporte.generarSalida(reporte);
    } catch (const ErrorArgumentoInvalido& e) {
        cout << "Error: " << e.what() << endl;
    }
}

void MenuReportes::reporteEquipos(Simulador* simulador) const {
    char op = ' ';
    while (op != 'c') {
        cout << "a. Crear reporte de uno (o varios) equipos especificos" << endl;
        cout << "b. Crear reporte de un tipo de equipo especifico" << endl;
        cout << "c. Volver" << endl;
        cout << "Seleccione: ";
        cin >> op;
        if (cin.fail()) {
            cout << "Entrada invalida" << endl;
            cin.clear();
            cin.ignore(1000, '\n');
            return;
        }

        switch (op) {
            case 'a': {
                IReporte* reporteBase = new ReporteEquipos();
                IReporte* reporteDecorado;
                cout << simulador->getListaEquipos() << endl;
                cout << "----------------------Se genererara un reporte con todos los equipos que seleccione----------------------------" << endl;
                int id = 0;
                while (id != -1) {
                    cout << "Ingrese el ID del equipo que desea agregar al reporte (o -1 para salir): ";
                    cin >> id;
                    try {
                        reporteDecorado = new DecoradorRE(simulador->getReporteEquipo(id), reporteBase);
                        reporteBase = reporteDecorado;
                    } catch (const ErrorNoEncontrado& e) {
                        cout << "Error: " << e.what() << endl;
                    }
                }
                salidaReporte.generarSalida(reporteBase->generarReporte());
                delete reporteBase;
                break;
            }
            case 'b': {
                string tipo;
                cout << "Ingrese el tipo de equipo que desea agregar al reporte (Servidor, Laptop, ComputadoraEscritorio, AireAcondicionado, Grabadora, Camara): ";
                cin >> tipo;
                try {
                    string reporte = simulador->getReporteTipoEquipo(tipo);
                    salidaReporte.generarSalida(reporte);
                } catch (const ErrorNoEncontrado& e) {
                    cout << "Error: " << e.what() << endl;
                }
                break;
            }
            default:
                break;
        }
    }
}

