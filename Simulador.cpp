//
// Created by cesar on 21/4/2026.
//

#include "Simulador.h"

#include "ErrorArgumentoInvalido.h"
#include "ErrorRepetido.h"

Simulador::Simulador(int diasSimulacion, int totalIncidencias, double sensibilidad) {
    this->reporte = new string * [diasSimulacion+2];// +2 para incluir el dia 0 y el reporte final despues de la simulacion
    for (int i=0; i<=diasSimulacion+1; i++) {
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
    //craeadores de gesto


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

bool Simulador::getSimulacionEjecutada() {
    return simulacionEjecutada;
}

string Simulador::getListaEquipos() {
    return contenedor->mostrarEquiposLista();
}

string Simulador::getEquiposSerializados() {
    return contenedor->serializar();
}

void Simulador::agregarEquipos(ContenedorEquipos *nuevoContenedor) {
    if (simulacionEjecutada) {
        delete nuevoContenedor;
        throw ErrorArgumentoInvalido("No se pueden cambiar los equipos despues de ejecutar la simulacion");
    }

    contenedor->agregarEquipos(nuevoContenedor);
}

string Simulador::getListaPersonas() {
    return contenedorPersonas->mostarListaPersonas();
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
    if (contenedor->getCant() == 0) {
        throw ErrorNoEncontrado("No se puede ejecutar la simulacion sin al menos un equipo");
    }
    stringstream s; //para generar los reportes diarios
    for (int i=0; i<=diasSimulacion; i++) {

        contenedor->nuevoDiaEquipos();
        contenedorPersonas->nuevoDiaPersonas();
        s.clear();
        s.str("");

        s<<"Dia "<<i<<":"<<endl;
        incidencias->asignarIncidencias(contenedor);
        s<<incidencias->generarReporte()<<endl;

        reporte[i][0] = s.str();
        if (i == 0) {
            reporte[i][1] = "DIA INICIAL, NO SE REPARAN EQUIPOS\n";
            reporte[i][1] += "Cantidad de dispositivos con incidencias: "+to_string(contenedor->pendientesDeReparar());
            reporte[i][2] = contenedor->mostrarEquipos();
            continue;
        }

        s.clear();
        s.str("");


        s<<"Tres equipos mas criticos:"<<endl;
        s<<contenedor->tresEquiposMasPrioritarios()<<endl;


        for (int j=0, k = 0; k<3 && j<contenedor->getCant(); j++) {
            if (contenedor->getTotalIncidencias() == 0) {
                s<<"No hay mas incidencias para reparar hoy"<<endl;
                break;
            }
            if (reparacion->repararEquipo(contenedor->buscarEquipoIndice(j),contenedorPersonas->getPersona(k))) {
                k++;
                s<<reparacion->generarReporte()<<endl;
            }else {
                s<<reparacion->generarReporte()<<endl;
                if (contenedor->buscarEquipoIndice(j+1)) {
                    s<<"El siguiente equipo a revisar es: "<<contenedor->buscarEquipoIndice(j+1)->infoBasica()<<endl;
                }
                else {
                    s<<"No hay mas equipos para revisar hoy"<<endl;
                }
            }
            //se escogen los 3 equipos mas prioritarios, se intenta reparar cada uno, si se repara se pasa al
            //siguiente tecnico, si no se repara el mismo tecnico revisa el siguiente equipo mas prioritario,
            //y asi sucesivamente hasta que se hayan intentado reparar 3 equipos o no haya mas equipos para
            //revisar
        }
        s<<"Dispositivos pendientes de reparar: "<<contenedor->pendientesDeReparar()<<endl;
        s<<"Riesgo global al final del dia:"<< contenedor->riesgoGlobal()<<endl;

        contenedor->aumentarInactividad();
        reporte[i][1]= s.str();
        reporte[i][2] = contenedor->mostrarEquipos();

    }
    contenedor->ordernarPorId();
    s.clear();
    reporte[diasSimulacion+1][2] = contenedor->reporteFinal(); //reporte final despues de la simulacion, se muestra el estado final de los equipos
    simulacionEjecutada = true;

}


string Simulador::getReporteDia(int dia, bool incluirIncidencias, bool incluirReparaciones, bool incluirEstadoEquipos) {

    if (dia < 0 || dia > diasSimulacion) {
        throw ErrorArgumentoInvalido("Dia fuera de rango");
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

string Simulador::getReporteRangoDias(int diaInicio, int diaFin, bool incluirIncidencias, bool incluirReparaciones,
    bool incluirEstadoEquipos) {
    stringstream s;
    if (diaInicio < 0 || diaFin > diasSimulacion || diaInicio > diaFin) {
        throw ErrorArgumentoInvalido("Rango de dias invalido");
    }

    for (int i=diaInicio; i<=diaFin; i++) {
        s<<getReporteDia(i, incluirIncidencias, incluirReparaciones, incluirEstadoEquipos)<<endl;
    }
    return s.str();
}

string Simulador::getReporteTipoEquipo(string tipo) {
    return contenedor->reporteTipoEquipo(tipo);
}

IReporteDelDia * Simulador::getReporteEquipo(int idEquipo) {
    Equipo* equipo = contenedor->buscarEquipo(idEquipo);
    if (!equipo) {
        throw ErrorNoEncontrado("No se encontro un equipo con el ID proporcionado");
    }
    return equipo;
}

void Simulador::setSensibilidadIncidencias(double nuevaSensibilidad) {
    if (nuevaSensibilidad < 0 || (nuevaSensibilidad > 1 && nuevaSensibilidad != 2)) {
        throw ErrorArgumentoInvalido("La sensibilidad debe ser un numero entre 0 y 1");
    }
    incidencias->setSensibilidad(nuevaSensibilidad);
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
    s<<"------------------------REPORTE FINAL------------------------"<<endl;
     s<<reporte[diasSimulacion+1][2]<<endl;
    return s.str();
}




