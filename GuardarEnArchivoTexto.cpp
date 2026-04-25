//
// Created by cesar on 24/4/2026.
//

#include "GuardarEnArchivoTexto.h"

GuardarEnArchivoTexto::GuardarEnArchivoTexto(const string &nombreArchivo) {
        this->nombreArchivo = nombreArchivo;
}

void GuardarEnArchivoTexto::guardarReporte(const string &reporte) {
        ofstream archivo(nombreArchivo);
        if (!archivo.is_open()) {
                archivo.close();
                throw runtime_error("No se pudo abrir el archivo para escribir");
        }
        archivo << reporte;
        archivo.close();
}
