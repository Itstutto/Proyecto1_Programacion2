cmake_minimum_required(VERSION 4.1)
project(Proyecto1)

set(CMAKE_CXX_STANDARD 20)

add_executable(Proyecto1 main.cpp
        Equipo.cpp
        Equipo.h
        Servidores.cpp
        Servidores.h
        ContenedorEquipos.cpp
        ContenedorEquipos.h
        ErrorEspacio.cpp
        ErrorEspacio.h
        Error.cpp
        Error.h
        ErrorNoEncontrado.h
        ErrorRepetido.cpp
        ErrorRepetido.h
        ComputadorasEscritorio.cpp
        ComputadorasEscritorio.h
        Laptops.cpp
        Laptops.h
        AireAcondicionado.cpp
        AireAcondicionado.h)
