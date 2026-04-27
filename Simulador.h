//
// Created by cesar on 21/4/2026.
//

#ifndef PROYECTO1_SIMULADOR_H
#define PROYECTO1_SIMULADOR_H
#include "ContenedorEquipos.h"
#include "Incidencias.h"
#include "Reparar.h"
//incluir todos los creadores
#include "CreadorServidores.h"
#include "CreadorLaptops.h"
#include "CreadorComputadorasEscritorio.h"
#include "CreadorAireAcondicionado.h"
#include "CreadorGrabadoras.h"
#include "CreadorCamaras.h"


#include <sstream>

#include "Archivos.h"
#include "ContenedorDePersonas.h"
#include "Guardar.h"
using namespace std;

class Simulador : public IReporteDelDia{
private:

    int diasSimulacion;
    bool simulacionEjecutada;
    ContenedorEquipos* contenedor;
    ContenedorDePersonas* contenedorPersonas;
    Incidencias* incidencias;
    string** reporte;
    Reparar* reparacion;

public:
    Simulador(int diasSimulacion = 31, int totalIncidencias = 100, double sensibilidad = 0.7);
    // 31 dias porque existe el dia 0
    ~Simulador();

    string getListaEquipos();
    string getEquiposSerializados();
    void agregarEquipos(ContenedorEquipos* nuevoContenedor);

    void agregarEquipo(Equipo* equipo);
    void agregarPersona(PersonaMantenimiento* persona);

    void cambiarNombreTecnico(int indice, string nuevoNombre);

    void ejecutarSimulacion();


    string getReporteDia(int dia, bool incluirIncidencias = false, bool incluirReparaciones = false, bool incluirEstadoEquipos = false);
    string getReporteRangoDias(int diaInicio, int diaFin, bool incluirIncidencias = true, bool incluirReparaciones = true, bool incluirEstadoEquipos = false);
    string getReporteTipoEquipo(string tipo);

    IReporteDelDia* getReporteEquipo(int idEquipo);

    string generarReporte() override;
};


#endif //PROYECTO1_SIMULADOR_H