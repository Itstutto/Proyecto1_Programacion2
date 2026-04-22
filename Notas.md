# Revisión SOLID - Proyecto1

Fecha: 2026-04-22

## Hallazgos (por severidad)

### 1) Alta - Dependencia de concretos (DIP)
`Simulador` crea sus dependencias internas con `new`, acoplándose a implementaciones concretas en vez de abstracciones.

- Referencias:
    - `Simulador.h` (atributos concretos): `ContenedorEquipos*` y `Incidencias*` (`Simulador.h:16-17`)
    - `Simulador.cpp` (instanciación concreta): `new ContenedorEquipos()` y `new Incidencias(...)` (`Simulador.cpp:10-11`)

**Impacto:** dificulta pruebas unitarias, reemplazo de estrategias y extensión del simulador sin tocar su código.

---

### 2) Media - Responsabilidades mezcladas (SRP)
Hay clases con más de una razón de cambio.

- `Equipo` mezcla:
    - estado/reglas de negocio (uso, daño, criticidad, prioridad),
    - formateo/salida (`toString`),
    - persistencia (`serializar`).
    - Referencia: interfaz en `Equipo.h:30-53` y lógica en `Equipo.cpp`.
- `ContenedorEquipos` mezcla:
    - almacenamiento,
    - búsqueda/eliminación,
    - ordenamiento,
    - serialización,
    - presentación (`mostrarEquipos`).
    - Referencia: `ContenedorEquipos.h:24-32`, `ContenedorEquipos.cpp`.

**Impacto:** cada cambio de formato de reporte, persistencia o estructura interna obliga a tocar las mismas clases.

---

### 3) Media - Extensión limitada por decisiones concretas (OCP)
Aunque hay polimorfismo con `Equipo`, el sistema sigue teniendo puntos cerrados a extensión limpia:

- Alta dependencia de tipos concretos en el flujo de arranque (`main.cpp`) para crear equipos específicos (`main.cpp:21-29`).
- Cada subclase define su propio texto de serialización, lo cual escala con cambios repetidos por tipo (`AireAcondicionado.cpp:36-39`, `Camaras.cpp:36-39`, `Servidores.cpp:38-42`, etc.).

**Impacto:** agregar nuevos tipos o cambiar formato de salida puede requerir cambios en varios archivos existentes.

---

### 4) Baja - Riesgo de romper invariantes por herencia (LSP, potencial)
Las subclases modifican estado protegido directamente (`criticidad`, `tiempoInactivo`) en sus constructores.

- Ejemplo:
    - `AireAcondicionado.cpp:13-22`
    - `Laptops.cpp:12-21`
    - `Servidores.cpp:14-24`

No es una violación LSP confirmada en todos los casos, pero sí **riesgo**: al evitar setters/validaciones centralizadas, una subclase puede dejar estados inesperados para clientes de `Equipo`.

---

## Lo que sí va bien

- **ISP (bien encaminado):** `IReporteDelDia` es pequeña y específica (`IReporteDelDia.h:10-14`), no obliga a implementar métodos innecesarios.
- **Uso de polimorfismo base:** `ContenedorEquipos` trabaja con `Equipo*` (`ContenedorEquipos.h:15`, `ContenedorEquipos.h:24-27`), lo cual ayuda a desacoplar operaciones del tipo concreto.

---

## Recomendaciones concretas (priorizadas)

1. **Aplicar inyección de dependencias en `Simulador`**  
   Recibir `ContenedorEquipos` e `Incidencias` (o interfaces) por constructor en vez de crearlos dentro.

2. **Separar responsabilidades de reporte/serialización**  
   Sacar `toString/serializar` a componentes dedicados (formatter/serializer) o estrategias.

3. **Encapsular invariantes de `Equipo`**  
   Reducir acceso directo a `protected` crítico y usar métodos controlados para cambios de estado.

4. **Reducir acoplamiento de creación en `main`**  
   Introducir una fábrica/registro de tipos para crear equipos sin condicionar el flujo a clases concretas.

---

## Nota adicional (no SOLID, pero importante)

- `Simulador` reserva `reporte` con `new[]` y no se libera en el destructor.
    - Reserva: `Simulador.cpp:8`
    - Destructor actual: `Simulador.cpp:14-19`
- Esto es una fuga de memoria; conviene migrar a `std::vector<string>` o liberar con `delete[]`.
