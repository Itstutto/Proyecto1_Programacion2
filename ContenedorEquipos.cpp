//
// Created by cesar on 12/4/2026.
//

#include "ContenedorEquipos.h"

#include "ErrorNoEncontrado.h"
#include "ErrorPunteroNulo.h"
#include "ErrorRepetido.h"

ContenedorEquipos:: ContenedorEquipos() {
    tam=100;
    cant = 0;
    equipos = new Equipo*[tam];
    ordenadoPorId = false;
    for (int i = 0; i < tam; i++) {
        equipos[i] = nullptr;
    }
}

ContenedorEquipos::~ContenedorEquipos() {

    for (int i = 0; i < cant; i++) {

        if (equipos[i]) {
            delete equipos[i];
        }
        equipos[i] = nullptr;
    }
    delete[] equipos;
    equipos = nullptr;
}

void ContenedorEquipos::liberarContenedor() {
    for (int i = 0; i < cant; i++) {
        if (equipos[i]) {
            equipos[i] = nullptr;
        }
    } // no los elimina porque se va a cambiar el dueño de los equipos
     cant = 0;
}

int ContenedorEquipos::getCant() {
    return cant;
}

void ContenedorEquipos::agregarEquipo(Equipo *equipo) {
        if (cant >= tam) {
            throw ErrorEspacio("El contenedor de equipos está lleno");
        }
        try {
            buscarEquipo(equipo->getId());
            throw ErrorRepetido("Ya existe un equipo con el ID proporcionado");
        } catch (const ErrorNoEncontrado& e) {
            //Si no se encuentra el equipo, se puede agregar
        }
        equipos[cant++] = equipo;

}

void ContenedorEquipos::eliminarEquipo(int id) {
    for (int i = 0; i < cant; i++) {
        if (equipos[i]->getId() == id) {
            delete equipos[i];
            equipos[i] = nullptr;
            //Mover los equipos restantes para llenar el espacio vacío
            for (int j = i; j < cant - 1; j++) {
                equipos[j] = equipos[j + 1];
            }
            equipos[--cant] = nullptr;
            return;
        }
    }
     throw ErrorNoEncontrado("No se encontró un equipo con el ID proporcionado");

}

Equipo * ContenedorEquipos::buscarEquipo(int id) {
    if (!ordenadoPorId) {
        ordernarPorId();
    }

    //busqueda binaria por id
    int izquierda = 0;
    int derecha = cant - 1;

    while (izquierda <= derecha) {
        int medio = izquierda + (derecha - izquierda) / 2;
        Equipo* equipo = equipos[medio];
        if (equipo->getId() == id) {
            return equipo;
        }
        else if (equipo->getId() < id) {
            izquierda = medio + 1;
        }
        else {
            derecha = medio - 1;
        }
    }
     throw ErrorNoEncontrado("No se encontró un equipo con el ID proporcionado");
}

Equipo * ContenedorEquipos::buscarEquipoIndice(int indice) {
    if (indice < 0 || indice >= cant) {
        throw ErrorNoEncontrado("Índice fuera de rango");
    }
    if (!equipos[indice]) {
        throw ErrorPunteroNulo("No se encontró un equipo en el índice proporcionado");
    }
    return equipos[indice];
}

string ContenedorEquipos::mostrarEquipos() {
    stringstream ss;
    for (int i = 0; i < cant; i++) {
        ss<<"Equipo #"<<i+1<<endl;
        ss << equipos[i]->toString() << endl;
        ss<<"----------------------------------------------"<<endl;
    }
    return ss.str();

}

string ContenedorEquipos::mostrarEquiposLista() {
    //mostrar solo id y nombre
    stringstream ss;
    for (int i = 0; i < cant; i++) {
        ss<<"--------------------------------"<<endl;
        ss<<i+1<<". "<<"ID: "<<equipos[i]->getId()<<" - "<<equipos[i]->getNombre()<<endl;
    }
    return ss.str();
}

string ContenedorEquipos::serializar() {
    stringstream ss;
    for (int i = 0; i < cant; i++) {
        ss << equipos[i]->serializar();
    }
    return ss.str();
}

void ContenedorEquipos::agregarEquipos(ContenedorEquipos *nuevoContenedor) {
    if (nuevoContenedor == nullptr) {
        throw ErrorPunteroNulo("El nuevo contenedor no puede ser nulo");
    }
    //agregar equipos a contenedor ya existente
    for (int i=0; i<nuevoContenedor->getCant(); i++) {

        try {
            agregarEquipo(nuevoContenedor->buscarEquipoIndice(i));
        }catch (const ErrorRepetido& e) {//si esta repetido solo no se agrega
        }catch (const ErrorEspacio& e) {
            throw ErrorEspacio("No se pueden agregar más equipos, el contenedor está lleno, se han agredado "+to_string(i)+" equipos");
        }
    }

    nuevoContenedor->liberarContenedor();

    //reiniciar el nuevo contenedor para evitar problemas de doble eliminación
    delete nuevoContenedor;

    nuevoContenedor = nullptr;
}



void ContenedorEquipos::agregarDiaReporte() {
    for (int i = 0; i < cant; i++) {
        equipos[i]->agregarDiaReporte();
    }
}

void ContenedorEquipos::ordenarPorPrioridad() {
    // sin swap
    Equipo* temp = nullptr;
    for (int i = 0; i < cant - 1; i++) {
        for (int j = 0; j < cant - i - 1; j++) {
            if (equipos[j]->prioridad() < equipos[j + 1]->prioridad()) {
                temp = equipos[j];
                equipos[j] = equipos[j + 1];
                equipos[j + 1] = temp;
            }
        }
    }
    ordenadoPorId = false;
}

void ContenedorEquipos::aumentarInactividad() {
    for (int i = 0; i < cant; i++) {
        if (equipos[i]->getDanado()) {
            equipos[i]->agregarTiempoInactivo();
        }
    }
}

void ContenedorEquipos::ordernarPorId()  {
    // sin swap
    Equipo* temp = nullptr;
    for (int i = 0; i < cant - 1; i++) {
        for (int j = 0; j < cant - i - 1; j++) {
            if (equipos[j]->getId() > equipos[j + 1]->getId()) {
                temp = equipos[j];
                equipos[j] = equipos[j + 1];
                equipos[j + 1] = temp;
            }
        }
    }
    ordenadoPorId = true;
}
