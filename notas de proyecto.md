Servidores 8-10
Computadoras de escritorio (En uso, no en uso) 7-9
Laptops (En uso, no en uso) 7-9
Aire Acondicionado 5-8
Grabadoras 4-7
Camaras 3-6

Si un objeto no esta en uso, su criticidad se baja 5 puntos (ya que pues... no se esta usando)


ERRORES**
Los errores se manejan de la siguiente manera:
1. Entradas invalidas con invalid_argument
2. Se creo la clase principal ERRO
3. De esta clase todos los tipos de errores heredan, por ejemplo
 - Objeto no encontrado
 - Arreglo lleno
 - Etc


Nota: Agregar en simulacion un menu para que al final de la simulacion se puedan generar reportes de los objetos, por ejemplo, cuantos objetos se usaron, cuantos no se usaron, etc. Esto es para que el usuario pueda ver un resumen de la simulacion y entender mejor los resultados.

-Reporte total  
-Reporte de cada equipo
 

Hay que revisar bien el calculo de la criticidad, ya que no se esta reparando equipos que no esten en uso, eso no es realista, ya que en la vida real, aunque un equipo no este en uso, si se le da mantenimiento para que este listo para cuando se necesite. Por lo tanto, se debe revisar el calculo de la criticidad para que sea mas realista.

Menu:  
1.Generar Reporte  
a. Reporte total  
b. Reporte de rango de dias
c. Reporte de equipo especifico
d. Reporte de un tipo de equipo especifico (ejemplo: solo computadoras de escritorio)  
d. Volver  
(en cada menu de reporte)  

Ingrese el rango de dias (ejemplo: 1-30)  
Desea incluir incidencias?  
Desea incluir reparaciones?  
Desea incluir estado de los equipos (cada dia)?  
1. Consola
2. Archivo de texto  
   (si  se elige archivo de texto)
Ingrese el nombre del archivo (ejemplo: reporte.txt)  
// se ha creado exitosamente  
Menu inicial: 
1. Cargar equipos desde archivo de texto
2. Ingresar equipos manualmente
3. Iniciar simulacion
4. Cambiar nombre de tecnicos

buscar error del id repetido, en contenedor de equipos. 