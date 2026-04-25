//
// Created by cesar on 21/4/2026.
//

#include "Simulador.h"

#include "ErrorArgumentoInvalido.h"

Simulador::Simulador(int diasSimulacion, int totalIncidencias, double sensibilidad) : guardador(nullptr){
    this->reporte = new string * [diasSimulacion+1];// +1 para incluir el estado final
    for (int i=0; i<=diasSimulacion; i++) {
        reporte[i] = new string[3];
    }
    this->simulacionEjecutada = false;
    this->diasSimulacion = diasSimulacion;
    this->contenedor = new ContenedorEquipos();
    this->incidencias = new Incidencias(totalIncidencias, diasSimulacion, sensibilidad);
    this->reparacion = new Reparar();
    this->contenedorPersonas = new ContenedorDePersonas();
    contenedorPersonas->agregarPersona(new PersonaMantenimiento("Tecnico1","1"));
    contenedorPersonas->agregarPersona(new PersonaMantenimiento("Tecnico2","2"));
    contenedorPersonas->agregarPersona(new PersonaMantenimiento("Tecnico3","3"));
    //craeadores de gestor
    gestorArchivos.agregarCreador(new CreadorServidores());
    gestorArchivos.agregarCreador(new CreadorLaptops());
    gestorArchivos.agregarCreador(new CreadorComputadorasEscritorio());
    gestorArchivos.agregarCreador(new CreadorAireAcondicionado());
    gestorArchivos.agregarCreador(new CreadorGrabadoras());
    gestorArchivos.agregarCreador(new CreadorCamaras());


}

Simulador::~Simulador() {
    delete contenedor;
    delete incidencias;
    delete reparacion;
    for (int i=0; i<=diasSimulacion; i++) {
        delete[] reporte[i];
    }
    delete[] reporte;
    delete contenedorPersonas;

}

string Simulador::getEquiposSerializados() {
    return contenedor->serializar();
}

void Simulador::cargarEquiposDesdeArchivo(const string &nombreArchivo) {
    if (simulacionEjecutada) {
        throw ErrorArgumentoInvalido("No se pueden agregar equipos después de ejecutar la simulación");
    }
    ContenedorEquipos* c;
    try {
        c = gestorArchivos.cargarEquipos("equipos.txt");
    }catch (const exception& e) {
        cerr << "Error al cargar equipos desde archivo: " << e.what() << endl;
        return;
    }
    delete contenedor;
    contenedor = c;
}

void Simulador::agregarEquipo(Equipo *equipo) {
    contenedor->agregarEquipo(equipo);
}

void Simulador::agregarPersona(PersonaMantenimiento *persona) {
    contenedorPersonas->agregarPersona(persona);
}

void Simulador::cambiarNombreTecnico(int indice, string nuevoNombre) {

    contenedorPersonas->getPersona(indice)->setNombre(nuevoNombre);

}

void Simulador::ejecutarSimulacion() {
    stringstream s;
    for (int i=0; i<diasSimulacion; i++) {

        contenedor->agregarDiaReporte();

        s.clear();
        s.str("");

        s<<"Dia "<<i<<":"<<endl;
        incidencias->asignarIncidencias(contenedor);
        s<<incidencias->generarReporte()<<endl;

        reporte[i][0] = s.str();
        if (i == 0) {
            reporte[i][1] = "DIA INICIAL, NO SE REPARAN EQUIPOS";
            reporte[i][2] = contenedor->mostrarEquipos();
            continue;
        }

        s.clear();
        s.str("");

        contenedor->ordenarPorPrioridad();
        s<<"Tres equipos mas criticos:"<<endl;
        for (int j=0, k = 0; k<3 && j<contenedor->getCant(); j++) {
            s<<"PRIORIDAD "<<contenedor->buscarEquipoIndice(j)->prioridad()<<endl;
            s<<contenedor->buscarEquipoIndice(j)->infoBasica()<<endl;
            if (reparacion->repararEquipo(contenedor->buscarEquipoIndice(j),contenedorPersonas->getPersona(k))) {
                k++;
            }
            s<<reparacion->generarReporte()<<endl;
        }

        contenedor->aumentarInactividad();
        reporte[i][1]= s.str();
        reporte[i][2] = contenedor->mostrarEquipos();

    }
    contenedor->ordernarPorId();
    s.clear();
    reporte[diasSimulacion][2] = contenedor->mostrarEquipos();
    simulacionEjecutada = true;

}

void Simulador::guardarReporte(const string &reporte) {
    guardador.guardarReporte(reporte);
}

void Simulador::setGuardador(IGuardarReporte *nuevaEstrategia) {
    guardador.setGuardado(nuevaEstrategia);
}


string Simulador::getReporteDia(int dia, bool incluirIncidencias, bool incluirReparaciones, bool incluirEstadoEquipos) {

    if (dia < 0 || dia > diasSimulacion) {
        throw ErrorArgumentoInvalido("Día fuera de rango");
    }


    stringstream s;
    s<<"Reporte del dia "<<dia<<":"<<endl;
    if (incluirIncidencias) {
        s<<"Incidencias:"<<endl;
        s<<reporte[dia][0]<<endl;
    }
    if (incluirReparaciones) {
        s<<"Reparaciones:"<<endl;
        s<<reporte[dia][1]<<endl;
    }
    if (incluirEstadoEquipos) {
        s<<"Estado de los equipos:"<<endl;
        s<<reporte[dia][2]<<endl;
    }
    return s.str();

}

IReporteDelDia * Simulador::getReporteEquipo(int idEquipo) {
    Equipo* equipo = contenedor->buscarEquipo(idEquipo);
    if (!equipo) {
        throw ErrorNoEncontrado("No se encontró un equipo con el ID proporcionado");
    }
    return equipo;
}


string Simulador::generarReporte() {
    stringstream s;
    for (int i=0; i<=diasSimulacion; i++) {
        s<<"------------------------Dia "<<i<<"------------------------"<<endl;
        for (int j=0; j<2; j++) {
            if (!reporte[i][j].empty()) {

                if (j == 0) {
                    s<<"Incidencias:"<<endl;
                } else if (j == 1) {
                    s<<"Reparaciones:"<<endl;
                }
                s<<reporte[i][j]<<endl;
            }
        }
    }
    return s.str();
}




