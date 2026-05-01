DOCUMENTO TÉCNICO I PROYECTO\
PROGRAMACION II

Este proyecto es un sistema que se enfoca en la modelación del
comportamiento dinámico del sistema, la toma de decisiones algorítmica y
la simulación de escenarios operativos bajo restricciones reales. El
sistema deberá simular un periodo de 30 días de operación. Durante ese
tiempo deberá evaluar continuamente el estado de los equipos, la
aparición o acumulación de incidencias, el riesgo asociado a cada equipo
y la disponibilidad limitada de recursos técnicos que desarrollen una
solución que decida qué hacer, cuando hacerlo y por qué hacerlo.

Por lo tanto, El sistema fue desarrollado utilizando los principios de
la programación orientada a objetos, organizando la lógica en múltiples
clases con responsabilidades específicas.

En el proyecto se implementa una clase base denominada Equipo, la cual
representa una clase abstracta general de los dispositivos manejados en
el sistema. A partir de esta clase, se derivan varias clases específicas
como Servidores, Computadoras de Escritorio, Laptops, Grabadoras y
Cámaras. Estas clases heredan atributos y métodos comunes de la clase
padre.

Adicionalmente el sistema incluye:\
- Clases Contenedoras: Para gestionar colecciones de objetos.\
- Clases Convertidoras: Encargadas de transformar datos de entrada en
objetos del sistema.\
- Clases creadoras: Responsables de encapsular la lógica de
instanciación de objetos.\
- Clase Error para el manejo de excepciones y sus clases hijas, que
especifican los tipos de errores que se pueden encontrar en la
simulación.

También se utilizaron varios tipos de relaciones entre clases como:

1.  Herencia: Las clases específicas de equipos heredan de la clase base
    Equipo, lo que permite reutilizar atributos y métodos, además de
    aplicar polimorfismo.\
2.  Composición: Los contenedores, como ContenedorEquipos, almacenan
    múltiples objetos de tipo Equipo, representando una relación de
    pertenencia.\
3.  Asociación: Las clases Convertidor y Creador interactúan con las
    clases de tipo Equipo para procesar datos y generar instancias.\
4.  Dependencia: Algunas clases dependen de otras para funcionar, por
    ejemplo:
    -   Los convertidores dependen de los creadores.\
    -   El manejo de archivos depende de los convertidores para
        interpretar la información.

El sistema sigue un flujo basado en procesamiento de datos:\
1. Lectura de datos desde archivos\
2. Procesamiento de cada línea de entrada\
3. Conversión de datos mediante clases convertidoras\
4. Creación de objetos usando clases creadoras\
5. Almacenamiento en contenedores\
6. Iteración y manipulación de los objetos

Se emplearon estructuras iterativas para recorrer colecciones, así como
validaciones para asegurar la integridad de los datos. Además de eso
también se utilizaron patrones de diseño como el decorator, como por
ejemplo la clase DecoradorRE que permite añadir funcionalidades
adicionales a objetos existentes sin modificar su estructura original e
investigando una solución para el bajo acompañamiento de las clases se
encontró el Factory que se implementa mediante las clases CreadorX, las
cuales encapsulan la creación de objetos específicos sin necesidad de
instanciar directamente las clases concretas.

El algoritmo utilizado aprobado por el profesor fue el método de
ordenamiento Bubble Sort, que ayudó a ordenar ascendentemente todos los
equipos por su id esto para, al final de la simulación poder buscar los
reportes de cada dispositivo utilizando búsqueda binaria también
solicitado en las instrucciones.

Algunas decisiones téncicas que se debieron de tomar fueron tales como
el uso de herencia para evitar duplicación de código, aplicación del
principio de responsabilidad única (SRP), separación clara entre
lectura, conversión y creación de objetos, uso de patrones de diseño
para mejorar la escalabilidad, organización del código en múltiples
archivos para mayor claridad. Con el objetivo de que el sistema fuera
más flexible, mantenible y fácil de entender.

Los errores se realizaron mediante la clase Error, como se mencionó
anteriormente, se encargó de representar y gestionar situaciones
excepcionales. Manejó validaciones como verificación de datos de
entrada, control de formato incorrecto y prevención de estados inválidos
y además ayudo con un control de fallos que lo que hace es verificar
antes de ejecutar operaciones críticas para evitar errores en tiempo de
ejecución

En conclusión, en este proyecto se logró construir un sistema organizado
y funcional, aplicando conceptos importantes de programación orientada a
objetos de una manera clara y estructurada. A lo largo del desarrollo,
se buscó dividir el problema en partes más pequeñas, asignando a cada
clase una responsabilidad específica, lo que facilita entender cómo
funciona el sistema en general.

Además, el uso de patrones de diseño permitió que el programa sea más
ordenado y fácil de ampliar. Esto significa que, si en el futuro se
desean agregar nuevos tipos de equipos o funcionalidades, se puede hacer
sin necesidad de modificar todo el código. Otro aspecto importante es
que se implementaron mecanismos básicos para manejar errores y validar
la información, lo que ayuda a que el sistema sea más seguro y evite
fallos inesperados.

GUÍA DE USO:

Para una mejor experiencia a la hora de utilizar el simulador, le
recomendamos al usuario seguir estas indicaciones:

1- El proyecto disponde de un archivo de texto llamado "equipos" en
donde se crearon 100 equipos por defecto para la simulación del
programa, los cuales contienen la información necesaria en el orden
correcto que los recibe el proyecto, sin embargo, si se desea crear
equipos nuevos con datos únicos se puede hacer de 2 maneras, las cuáles
son las siguientes:\
1) Desde la interfaz siguiendo las instrucciones que se dan en ella.\
2) Creando un archivo de texto el cual contenga la información de los
dispositivos que desee crear.

-Si se desea crear un archivo de texto debe poseer el siguiente
formato:\
Tipo de quipo, id, nombre, criticidad ,enUso, incidenciasActivas,
tiempoInactivo.

-Cabe recalcar que los rangos de criticidad están dados por el tipo de
dispositivo que se manejan de la siguiente manera:\
Servidores =8-10.\
Laptops= 6-9.\
ComputadorasEscritorio= 7-9.\
AireAcondicionado =5-8.\
Grabadoras= 4-7.\
Camaras = 3-6.

-Si se digita un valor menor o mayor al rango el programa lo ajustará de
manera automática al mínimo o máximo dependiendo del valor digitado.

2- Sensibilidad del simulador: El generador de incidencias posee un
atributo "sensibilidad" el cuál actúa de la siguiente manera:\
-Por defecto el valor está asignado en 2, esto hace que todas las
incidencias sean asignadas el primer día, sin embargo, en la opción
"ajustar sensibilidad de asignación de incidencias" se puede ingresar el
valor que se desee (del 1 al 100), esto hará que las incidencias se
asignen con el pasar de los días en la simulación, si se desea regresar
al valor por defecto, ingrese el valor 200.

3- Reportes: Las opciones disponibles en el simulador para una creación
de reportes son las siguientes:

1)  Reporte total: En el cual se le brindará al usuario el reporte total
    de los 30 días de la simulación, incluyendo los dispositivos, sus
    incidencias, sus reparaciones y estado final. Se da a escoger una
    forma en como quiere ver dicho reporte si se quiere proyectar en
    consola o en archivo de texto.

2)  Reporte rango de días: Se preguntará el día en que desea iniciar y
    finalizar el reporte, si desea incluir incidencias reparaciones,
    estado diario y el formato de salida para lectura de este mismo
    reporte.

3)  Reporte de equipo: En este reporte se podrá hacer un reporte
    seleccionando uno o varios equipos en específico que el usuario
    quiera analizar, preguntando cuál o cuáles equipos está interesado
    ingresando el tipo de equipo que quiere consultar, y su formato de
    salida.
