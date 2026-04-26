//
// Created by yense on 4/25/2026.
//

#include "Menu.h"

#include "DecoradorRE.h"
#include "ErrorArgumentoInvalido.h"
#include"GuardarEnArchivoTexto.h"
#include"GuardarEnConsola.h"
#include "IReporte.h"
#include "ReporteEquipos.h"

void Menu::menuPrincipal(Simulador* simulador) {
    int op1;
  while (op1 != 1) {
      cout << "--- SIMULACION ---" << endl;
      cout << "1. Cargar equipos desde archivos "<<endl;
      cout << "2. Ingresar equipos manualmente "<<endl;
      cout << "3. Ejecutar Simulacion" << endl;
      cout << "4. Cambiar nombre de tecnico"<<endl;

      cout << "Seleccione: ";
      cin >> op1;
  }
        try {
            if (cin.fail()) throw "Entrada invalida";
            switch (op1) {
                case 1: {
                    Archivos gestorArchivos;
                    ContenedorEquipos* contenedor = nullptr;
                    string nombreArchivo;
                    cout<<"En que archivo se encuentran los equipos?"<<endl;
                    cin>>nombreArchivo;
                    try {
                        contenedor = gestorArchivos.cargarEquipos(nombreArchivo);
                        simulador->setEquipos(contenedor);
                    } catch (const exception& e) {
                        cerr << "Error al cargar el archivo: " << e.what() << endl;
                    }
                    break;
                }
                case 2: {
                    int cantidadEquipos;
                    cout << "Cuantos equipos desea ingresar? ";
                    cin >> cantidadEquipos;
                    cin.ignore(); // Limpiar el buffer

                    for (int i = 0; i < cantidadEquipos; ++i) {
                        string tipo, nombre;
                        int id, incidenciasActivas, tiempoInactivo, criticidad;
                        bool enUso;

                        cout << "Ingrese el tipo de equipo (Servidor, Laptop, ComputadoraEscritorio, AireAcondicionado, Grabadora, Camara): ";
                        getline(cin, tipo);
                        cout << "Ingrese el ID del equipo: ";
                        cin >> id;
                        cout << "Ingrese el nombre del equipo: ";
                        cin.ignore();
                        getline(cin, nombre);
                        cout << "Ingrese las incidencias del equipo: ";
                        cin >> incidenciasActivas;
                        cout << "Ingrese el tiempo inactivo del equipo: ";
                        cin >> tiempoInactivo;
                        cout << "Ingrese la criticidad del equipo: ";
                        cin >> criticidad;
                        cout<<"Ingrese si el equipo esta en uso (1 para si, 0 para no): ";
                        cin >> enUso;

                        Equipo* nuevoEquipo = nullptr;
                        if (tipo == "Servidor") {
                            nuevoEquipo = new Servidores(id, nombre,criticidad, enUso, incidenciasActivas, tiempoInactivo);
                        } else if (tipo == "Laptop") {
                            nuevoEquipo = new Laptops(id, nombre,criticidad, enUso, incidenciasActivas, tiempoInactivo);
                        } else if (tipo == "ComputadoraEscritorio") {
                            nuevoEquipo = new ComputadorasEscritorio(id, nombre,criticidad, enUso, incidenciasActivas, tiempoInactivo);
                        } else if (tipo == "AireAcondicionado") {
                            nuevoEquipo = new AireAcondicionado(id, nombre,criticidad, enUso, incidenciasActivas, tiempoInactivo);
                        } else if (tipo == "Grabadora") {
                            nuevoEquipo = new Grabadoras(id, nombre,criticidad, enUso, incidenciasActivas, tiempoInactivo);
                        } else if (tipo == "Camara") {
                            nuevoEquipo = new Camaras(id, nombre,criticidad, enUso, incidenciasActivas, tiempoInactivo);
                        } else {
                            cout << "Tipo de equipo no reconocido. Intente nuevamente." << endl;
                            --i; // Decrementar para repetir esta iteración
                            continue;
                        }

                        simulador->agregarEquipo(nuevoEquipo);
                    }
                    break;
                }

                case 3:
                    cout<<"-------- EJECUTANDO SIMULACION --------"<<endl;
                    simulador->ejecutarSimulacion();
                    menuFinal(simulador);
                    break;

                case 4: {
                    int id;
                    string nuevoNombre;
                    cout << "Ingrese el ID del tecnico que desea renombrar: ";
                    cin >> id;
                    cout << "Ingrese el nuevo nombre del tecnico: ";
                    cin.ignore();
                    getline(cin, nuevoNombre);
                    simulador->cambiarNombreTecnico(id, nuevoNombre);
                    break;
                }
                default:
                    throw "Opcion no valida";
            }
        } catch (const char* msg) {
            cout << "Error: " << msg << endl;
            cin.clear();
            cin.ignore(1000, '\n');

        }

  }


void Menu::menuFinal(Simulador *simulador) {
    int op;

    do {
        cout << "--- MENU ---"<<endl;
        cout << "1. Generar Reporte"<<endl;
        cout << "2. Salir"<<endl;
        cout << "Seleccione: ";
        cin >> op;
        cout<<endl<<endl;


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

    generarSalida(simulador->generarReporte());

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
        reporte = simulador->getReporteRangoDias(inicio,final,incluirIncidencias, incluirReparaciones, incluirEstado);
        generarSalida(reporte);
    }catch (const ErrorArgumentoInvalido& e) {
        cout << "Error: " << e.what() << endl;
    }

}

void Menu::reporteEquipos(Simulador* simulador) {
    IReporte* reporteBase = new ReporteEquipos();
    IReporte* reporteDecorado;
    cout<< simulador->getListaEquipos()<<endl;

    int id = 0;
    while (id != -1) {

        cout<< "Ingrese el ID del equipo que desea agregar al reporte (o -1 para salir): ";
        cin >> id;
        try {
            reporteDecorado = new DecoradorRE(simulador->getReporteEquipo(id), reporteBase);
            reporteBase = reporteDecorado; // El nuevo reporte decorado se convierte en la base para el siguiente
        } catch (const ErrorNoEncontrado& e) {
            cout << "Error: " << e.what() << endl;
        }
    }

        generarSalida(reporteBase->generarReporte());
        delete reporteBase; // Esto eliminará todos los decoradores encadenados


}

void Menu::generarSalida(string contenido) {
    Archivos gestorArchivos;
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
    gestorArchivos.agregarGuardador(guardador);
    gestorArchivos.guardarArchivo(contenido);
}
