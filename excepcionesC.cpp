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


void manejarExcepcion(Excepcion excepcion) {
    switch (excepcion) {
        case FORMATO_FECHA_INCORRECTO:
            printf("Error: Formato de fecha incorrecto\n");
            break;
        case MATERIA_NO_REGISTRADA:
            printf("Error: Materia no registrada\n");
            break;
        default:
            printf("Error desconocido\n");
            break;
    }
}


struct Asistencia {
    char fecha[MAX_FECHA];
    char materia[MAX_MATERIA];
    char estado[MAX_NOMBRE]; // asistió, falta, tardanza
};


struct Estudiante {
    char nombre[MAX_NOMBRE];
    int edad;
    float promedio;
    struct Asistencia asistencias[MAX_ASISTENCIAS]; // Array de asistencias
    int cantidadAsistencias;
};


void mostrarAsistencia(const struct Estudiante estudiante) {
    printf("Asistencias de %s:\n", estudiante.nombre);
    for (int i = 0; i < estudiante.cantidadAsistencias; ++i) {
        printf("Fecha: %s | Materia: %s | Estado: %s\n", estudiante.asistencias[i].fecha,
               estudiante.asistencias[i].materia, estudiante.asistencias[i].estado);
    }
    printf("\n");
}


void registrarAsistencia(struct Estudiante *estudiante, const char *fecha, const char *materia, const char *estado) {
    // Verificar formato de fecha
    if (strlen(fecha) != 10 || fecha[4] != '-' || fecha[7] != '-') {
        manejarExcepcion(FORMATO_FECHA_INCORRECTO);
        return;
    }


    char materiasRegistradas[][MAX_MATERIA] = {"Matemáticas", "Física", "Programación"};
    int numMateriasRegistradas = sizeof(materiasRegistradas) / sizeof(materiasRegistradas[0]);
    int materiaRegistrada = 0;
    for (int i = 0; i < numMateriasRegistradas; ++i) {
        if (strcmp(materiasRegistradas[i], materia) == 0) {
            materiaRegistrada = 1;
            break;
        }
    }
    if (!materiaRegistrada) {
        manejarExcepcion(MATERIA_NO_REGISTRADA);
        return;
    }

    if (estudiante->cantidadAsistencias < MAX_ASISTENCIAS) {
        strcpy(estudiante->asistencias[estudiante->cantidadAsistencias].fecha, fecha);
        strcpy(estudiante->asistencias[estudiante->cantidadAsistencias].materia, materia);
        strcpy(estudiante->asistencias[estudiante->cantidadAsistencias].estado, estado);
        estudiante->cantidadAsistencias++;
    } else {
        printf("No se pueden registrar más asistencias\n");
    }
}

int main() {

    struct Estudiante estudiante1;


    strcpy(estudiante1.nombre, "Alberto");
    estudiante1.edad = 18;
    estudiante1.promedio = 8;
    estudiante1.cantidadAsistencias = 0;
