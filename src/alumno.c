/*********************************************************************************************************************
Copyright (c) 2025, Martin Nicolas Soria <soria.m.nicolas@gmail.com>

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated
documentation files (the "Software"), to deal in the Software without restriction, including without limitation the
rights to use, copy, modify, merge, publish, disponiblestribute, sublicense, and/or sell copies of the Software, and to permit
persons to whom the Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial portions of the
Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE
WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR
OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

SPDX-License-Identifier: MIT
*********************************************************************************************************************/

/** @file alumno.c
 ** @brief Codigo fuente del modulo de alumno
 **/

/* === Headers files inclusions ==================================================================================== */

#include "alumno.h"
#include <stdio.h>
#include <stdint.h>
#include <string.h>

/* === Macros definitions ========================================================================================== */

/* === Private data type declarations ============================================================================== */

/* === Private function declarations =============================================================================== */

static int SerializarCadena(const char *campo, const char *valor, char *buffer, uint32_t disponibles);
static int SerializarDocumento(const char *campo, uint32_t valor, char *buffer, uint32_t disponibles);

/* === Private variable definitions ================================================================================ */

/* === Public variable definitions ================================================================================= */

/* === Private function definitions ================================================================================ */

/**
 * @brief Funcion para serializar un campo y su valor
 * 
 * @param campo 
 * @param valor 
 * @param buffer 
 * @param disponibles 
 * @return int
 */
static int SerializarCadena(const char *campo, const char *valor, char *buffer, uint32_t disponibles){
    return snprintf(buffer, disponibles, "\"%s\":\"%s\"," , campo, valor);
}

/**
 * @brief Funcion para serializar el documento y su valor
 * 
 * @param campo 
 * @param valor 
 * @param buffer 
 * @param disponibles 
 * @return int
 */
static int SerializarDocumento(const char *campo, uint32_t valor, char *buffer, uint32_t disponibles){
    return snprintf(buffer, disponibles, "\"%s\":%u," , campo, valor);
}

/* === Public function definitions ============================================================================== */

int Serializar(const alumno_t *alumno, char *buffer, uint32_t size){
    int escritos = 0;
    int resultado;

    if (size < 2) {
        return -1; // No hay espacio para serializar
    }   
    buffer[escritos++] = '{';

    resultado = SerializarCadena("nombre", alumno->nombre, buffer + escritos, size - escritos);
    if (resultado < 0) {
        return -1; // Error al serializar
    }
    escritos += resultado;

    resultado = SerializarCadena("apellido", alumno->apellido, buffer + escritos, size - escritos);
    if (resultado < 0) {
        return -1; // Error al serializar
    }
    escritos += resultado;

    resultado = SerializarDocumento("documento", alumno->documento, buffer + escritos, size - escritos);
    if (resultado < 0) {
        return -1; // Error al serializar
    }
    escritos += resultado;

    if (escritos >= size - 1) {
        return -1; // No hay espacio para el cierre
    }

    buffer[escritos++] = '}';
    buffer[escritos] = '\0'; // Cerrar la cadena

    return escritos; // Retornar la cantidad de caracteres escritos
}


/* === End of documentation ======================================================================================== */
