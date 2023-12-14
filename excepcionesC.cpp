#include <stdio.h>
#include <string.h>

#define MAX_ASISTENCIAS 50
#define MAX_FECHA 20
#define MAX_MATERIA 50
#define MAX_NOMBRE 50


typedef enum {
    FORMATO_FECHA_INCORRECTO,
    MATERIA_NO_REGISTRADA
} Excepcion;
