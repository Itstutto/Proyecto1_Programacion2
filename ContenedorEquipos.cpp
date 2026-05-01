//
// Created by cesar on 12/4/2026.
//

#include "ContenedorEquipos.h"
#include <iomanip>
#include "Convertidor.h"
#include "Convertidores.h"
#include "ErrorNoEncontrado.h"
#include "ErrorPunteroNulo.h"
#include "ErrorRepetido.h"
#include "FabricaConvertidores.h"

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
    } // no los elimina porque se va a cambiar el dueno de los equipos
     cant = 0;
}

int ContenedorEquipos::getCant() {
    return cant;
}

int ContenedorEquipos::getTotalIncidencias() {
    int total = 0;
    for (int i = 0; i < cant; i++) {
        total += equipos[i]->getIncidenciasActivas();
    }
    return total;
}

int ContenedorEquipos::pendientesDeReparar() {
    int total = 0;
    for (int i = 0; i < cant; i++) {
        if (equipos[i]->getIncidenciasActivas() > 0) {
            total++;
        }
    }
    return total;
}

void ContenedorEquipos::agregarEquipo(Equipo *equipo) {
        if (cant >= tam) {
            throw ErrorEspacio("El contenedor de equipos esta lleno");
        }

        if (buscarEquipo(equipo->getId())) {
            throw ErrorRepetido("Ya existe un equipo con el ID proporcionado");
        }

        //Si no se encuentra el equipo, se puede agregar
        equipos[cant++] = equipo;


}

void ContenedorEquipos::eliminarEquipo(int id) {
    for (int i = 0; i < cant; i++) {
        if (equipos[i]->getId() == id) {
            delete equipos[i];
            equipos[i] = nullptr;
            //Mover los equipos restantes para llenar el espacio vacio
            for (int j = i; j < cant - 1; j++) {
                equipos[j] = equipos[j + 1];
            }
            equipos[--cant] = nullptr;
            return;
        }
    }
     throw ErrorNoEncontrado("No se encontro un equipo con el ID proporcionado");

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
     return nullptr; // No se encontro el equipo, se devuelve nullptr para que el llamador pueda manejarlo
}

Equipo * ContenedorEquipos::buscarEquipoIndice(int indice) {
    if (indice < 0 || indice >= cant) {
        return nullptr;
    }
    if (!equipos[indice]) {
        throw ErrorPunteroNulo("No se encontro un equipo en el indice proporcionado");
    }
    return equipos[indice];
}

string ContenedorEquipos::riesgoGlobal() {
    double estadoTotal = 0;
    string riesgoTotal;
    for (int i = 0; i < cant; i++) {
        estadoTotal += equipos[i]->getEstado();
    }
    double riesgo = 100 - (estadoTotal / cant);

    riesgoTotal = (riesgo < 25) ? "Bajo" : (riesgo < 50) ? "Medio" : (riesgo < 75) ? "Alto" : "Critico";
    stringstream ss;
    ss<<"Estado global de los equipos: "<<setprecision(4)<<estadoTotal/cant<<"% - Riesgo global: "<<riesgoTotal<<endl;
    return ss.str();
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

string ContenedorEquipos::tresEquiposMasPrioritarios() {
    //ordenar por prioridad y mostrar los 3 primeros
    ordenarPorPrioridad();
    stringstream ss;
    ss<<"Los 3 equipos con mayor prioridad de atencion son:"<<endl;
    for (int i = 0; i < 3 && i < cant; i++) {
        ss<<"Equipo #"<<i+1<<endl;
        ss << equipos[i]->infoBasica() << endl;
        ss<<"----------------------------------------------"<<endl;
    }
    return ss.str();
}

string ContenedorEquipos::reporteTipoEquipo(string tipo) {
    Convertidores convertidores;
    FabricaConvertidores::cargarConvertidores(&convertidores);
    Convertidor* convertidor = convertidores.getConvertidor(tipo);
    if (!convertidor) {
        throw ErrorNoEncontrado("No se encontro un convertidor para el tipo de equipo proporcionado");
    }
    stringstream ss;
    Equipo* equipoConvertido;
    ss<<"Reporte de equipos del tipo "<<tipo<<":"<<endl;
    for (int i = 0; i < cant; i++) {
        equipoConvertido = convertidor->convertirEquipo(equipos[i]);
        if (equipoConvertido) {
            ss<<"Equipo #"<<i+1<<endl;
            ss << equipoConvertido->generarReporte() << endl;
            ss<<"----------------------------------------------"<<endl;
        }
    }
    return ss.str();
}

string ContenedorEquipos::reporteFinal() {
    stringstream ss;
    ss<<"Reporte final de los equipos:"<<endl;
    for (int i = 0; i < cant; i++) {
        ss<<"Equipo #"<<i+1<<endl;
        ss << equipos[i]->toString() << endl;
        ss<<"----------------------------------------------"<<endl;
    }
    ss<<"Estado final: "<<endl
    <<riesgoGlobal()<<endl;
    ss<<"Cantidad de equipos sin atender: "<<endl
    <<pendientesDeReparar()<<endl;

    return ss.str();
}

void ContenedorEquipos::agregarEquipos(ContenedorEquipos *nuevoContenedor) {
    if (nuevoContenedor == nullptr) {
        throw ErrorPunteroNulo("El nuevo contenedor no puede ser nulo");
    }
    int agregados = 0;
    int cantOriginal = nuevoContenedor->cant;

    try {
        // Mueve ownership equipo por equipo; en duplicados se libera el objeto descartado.
        for (int i = 0; i < cantOriginal; i++) {
            Equipo* equipo = nuevoContenedor->equipos[i];
            if (!equipo) {
                continue;
            }

            try {
                agregarEquipo(equipo);
                nuevoContenedor->equipos[i] = nullptr;
                agregados++;
            } catch (const ErrorRepetido&) {
                cout << "El equipo " << equipo->getNombre() << " posee un ID ya utilizado, no se agrega" << endl;
                delete equipo;
                nuevoContenedor->equipos[i] = nullptr;
            }
        }

        nuevoContenedor->cant = 0;
        delete nuevoContenedor;
    } catch (const ErrorEspacio&) {
        delete nuevoContenedor;
        throw ErrorEspacio("No se pueden agregar mas equipos, el contenedor esta lleno, se han agregado " + to_string(agregados) + " equipos");
    } catch (...) {
        delete nuevoContenedor;
        throw;
    }
}





void ContenedorEquipos::nuevoDiaEquipos() {
    for (int i = 0; i < cant; i++) {
        equipos[i]->nuevoDia();
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
