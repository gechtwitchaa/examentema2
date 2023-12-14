#include <stdio.h>
#include <string.h>

#define MAX_ASISTENCIAS 50
#define MAX_FECHA 20
#define MAX_MATERIA 50
#define MAX_NOMBRE 50
#define MAX_ESTUDIANTES 10


struct Asistencia {
    char fecha[MAX_FECHA];
    char materia[MAX_MATERIA];
    char estado[MAX_NOMBRE];
};


struct Estudiante {
    char nombre[MAX_NOMBRE];
    int edad;
    float promedio;
    struct Asistencia asistencias[MAX_ASISTENCIAS];
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


    registrarAsistencia(&estudiante1, "2023-12-01", "Matemáticas", "asistió");
    registrarAsistencia(&estudiante1, "2023-12-02", "Física", "falta");
    registrarAsistencia(&estudiante1, "2023-12-03", "Programación", "tardanza");


    mostrarAsistencia(estudiante1);

    return 0;
}
