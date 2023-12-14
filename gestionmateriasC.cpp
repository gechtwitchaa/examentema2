#include <stdio.h>
#include <string.h>

#define MAX_MATERIAS 10
#define MAX_NOMBRE 50


struct Estudiante {
    char nombre[MAX_NOMBRE];
    int edad;
    float promedio;
    char materias[MAX_MATERIAS][MAX_NOMBRE]; // Array de cadenas para las materias
    int cantidadMaterias;
};


void mostrarEstudiante(struct Estudiante estudiante) {
    printf("Nombre: %s\n", estudiante.nombre);
    printf("Edad: %d\n", estudiante.edad);
    printf("Promedio: %.2f\n", estudiante.promedio);

    printf("Materias inscritas:\n");
    for (int i = 0; i < estudiante.cantidadMaterias; ++i) {
        printf("- %s\n", estudiante.materias[i]);
    }
    printf("\n");
}
