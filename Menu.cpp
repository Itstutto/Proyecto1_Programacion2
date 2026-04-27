#include "Menu.h"
#include "ErrorNoEncontrado.h"
Menu::Menu() : menuReportes(salidaReporte) {
}
void Menu::menuPrincipal(Simulador* simulador) {
    int op1 = 0;
    while (op1 != -1) {
        cout << "--- SIMULACION ---" << endl;
        cout << "1. Cargar equipos desde archivos" << endl;
        cout << "2. Ingresar equipos manualmente" << endl;
        cout << "3. Ejecutar Simulacion" << endl;
        cout << "4. Cambiar nombre de tecnico" << endl;
        cout << "Seleccione: ";
        cin >> op1;
        try {
            if (cin.fail()) throw "Entrada invalida";
            switch (op1) {
                case 1:
                    menuSimulacion.cargarEquiposDesdeArchivo(simulador);
                    break;
                case 2:
                    menuSimulacion.ingresarEquiposManualmente(simulador);
                    break;
                case 3:
                    cout << "-------- EJECUTANDO SIMULACION --------" << endl;
                    try {
                        simulador->ejecutarSimulacion();
                    } catch (const ErrorNoEncontrado& e) {
                        cout << "No se puede iniciar la simulacion sin al menos un equipo: " << endl;
                        cout << e.what() << endl;
                        break;
                    }
                    menuFinal(simulador);
                    op1 = -1;
                    break;
                case 4:
                    menuSimulacion.cambiarNombreTecnico(simulador);
                    break;
                default:
                    throw "Opcion no valida";
            }
        } catch (const char* msg) {
            cout << endl << "Error: " << msg << endl;
            cin.clear();
            cin.ignore(1000, '\n');
        }
    }
}
void Menu::menuFinal(Simulador* simulador) {
    int op;
    do {
        cout << "--- MENU ---" << endl;
        cout << "1. Generar Reporte" << endl;
        cout << "2. Salir" << endl;
        cout << "Seleccione: ";
        cin >> op;
        cout << endl << endl;
        try {
            if (cin.fail()) throw "Entrada invalida";
            switch (op) {
                case 1:
                    menuReportes.menuReportes(simulador);
                    break;
                case 2:
                    cout << "Saliendo..." << endl;
                    break;
                default:
                    throw "Opcion no valida";
            }
        } catch (const char* msg) {
            cout << "Error: " << msg << endl;
            cin.clear();
            cin.ignore(1000, '\n');
        }
    } while (op != 2);
}
