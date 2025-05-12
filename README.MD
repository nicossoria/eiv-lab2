# Electronica IV - Laboratorio 2

Alumno: Martin Nicolas Soria

##Ejercicio a Desarrollar

Se deberá crear un repositorio git con acceso público que tenga el código fuente de un proyecto en C que cumpla con los siguientes requisitos:

• Se definirá un archivo makefile para poder compilar el proyecto con el comando make all.

• Todo el código fuente (archivos .c) deberá ubicarse en la carpeta src mientras que los archivos de cabeceras y (archivos.h) se deberán ubicar en la carpeta inc.

• El ejecutable deberá ubicarse en la carpeta build/bin y los archivos objeto intermedios en la carpeta build/obj.

• El programa principal estará compuesto solo por la función main, que se ubicará en el archivo main.c.

• El programa principal mostrará por pantalla los datos del alumno en formato JSON utilizando la función Serializar del módulo alumno.

• En el módulo alumno se definirá un tipo de datos correspondiente una estructura con la información personal de un alumno: nombre, apellido y documento.

• En el módulo alumno se definirá tambien una función Serializar que recibirá como parámetros un puntero a una estructura constante con los datos del alumno, una cadena de caracteres para generar el resultado y la cantidad de bytes disponibles en la cadena de resultado. La función deberá retornar la longitud de la cadena generada, o -1 si el espacio no es suficiente.

• El módulo alumno tendrá además dos funciones internas para serializar los campos de texto y numéricos. La función pública Serializar utilizará estas funciones interna.

• Se documentará todo el código utilizando doxygen. El comando make doc deberá generar la documentación en HTML en la carpeta build/doc.

• Se deberá mantener un formato consistente en todo el código desarrollado (posición de llaves, formatos de identificadores y niveles de identado).

• Se deberá evitar la repetición de código utilizando, adecuadamente, macros y archivos de cabecera.
