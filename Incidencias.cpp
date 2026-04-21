//
// Created by cesar on 20/4/2026.
//

#include "Incidencias.h"

#include "ErrorArgumentoInvalido.h"
#include "ErrorPunteroNulo.h"

Incidencias::Incidencias(int incidenciasRestantes, int plazo, double sensibilidad) {
    this ->incidenciasRestantes = incidenciasRestantes;
    this ->plazo = plazo;
    this ->incidencias = 0;
    this ->diasCompletados = 0;
    this ->reporte = "";
    if (sensibilidad < 0 || (sensibilidad > 1 && sensibilidad != 2)) {
        throw ErrorArgumentoInvalido("La sensibilidad debe ser un valor entre 0 y 1");
    }
    if (sensibilidad == 2) {
        this-> sensibilidad = 0;
        //si se pone 2, se crean todas las incidencias el primer dia
    } else {
        this-> sensibilidad = 95-45*sensibilidad;
    }
    //la sensibilidad se traduce en un numero entre 95 y 50, a mayor sensibilidad, mayor posibilidad de
    //que haya una incidencia, se puede usar para simular diferentes escenarios, por ejemplo, si se
    //tiene equipos muy sensibles, se puede aumentar la sensibilidad para simular que son más propenso
    //a tener incidencias
}

int Incidencias::calculoIncidencias() {

    int posibilidad = (diasCompletados*100/plazo);

    // da un numero del 0 al 100, a medida que se acerca al plazo, la posibilidad de que haya una incidencia aumenta
    random_device rd;
    mt19937 gen(rd());
    uniform_real_distribution<> cant(posibilidad ,100);
    cout<<"Posibilidad de incidencia: "<<posibilidad<<"%"<<endl;
    double cantidadAsignada = 0; //cantidad a asignar, no se eliminan de restantes hasta que asignarIncidencias() las asignas

    for (int i=0; i<incidenciasRestantes; i++) {
        double numeroAleatorio = cant(gen);
        if (numeroAleatorio>sensibilidad) { //si se baja el numero a evaluar, se aumenta la posibilidad de incidencia
            cantidadAsignada++;
        }
    }


    return cantidadAsignada;

}
void Incidencias::asignarIncidencias(ContenedorEquipos* contenedor) {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> cant(0, contenedor->getCant()-1);
    stringstream s;
    s<<"Reporte del dia: "<<diasCompletados<<endl;

    int dispositivo;
    int cantidadDeIncidencias = calculoIncidencias();

    for (int i=0 ; i<cantidadDeIncidencias; i++) {
        dispositivo = cant(gen);
        try {
            contenedor->buscarEquipoIndice(dispositivo)->agregarIncidencia();
            s<<"Incidencia asignada al dispositivo: "<<contenedor->buscarEquipoIndice(dispositivo)->getNombre()<<endl;
        }catch (const ErrorPunteroNulo& e) {
            cout<<"Error: "<<e.what()<<endl
            <<"Se asignara la incidencia a otro dispositivo"<<endl;
            i--;
            continue;
        }
    }

    s<<"Cantidad de incidencias asignadas: "<<cantidadDeIncidencias<<endl
    <<"Cantidad de incidencias restantes: "<<incidenciasRestantes-cantidadDeIncidencias<<endl
    <<"---------------------------------------------"<<endl;
    incidenciasRestantes -= cantidadDeIncidencias;
    incidencias += cantidadDeIncidencias;
    diasCompletados++;
    reporte += s.str();



}

int Incidencias::getIncidencias() {
    return incidencias;
}

int Incidencias::getIncidenciasRestantes() {
    return incidenciasRestantes;
}

string Incidencias::getReporte() {
    return reporte;
}
