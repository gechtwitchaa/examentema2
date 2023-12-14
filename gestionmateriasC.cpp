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

// Función para agregar una materia al estudiante
void agregarMateria(struct Estudiante *estudiante, const char *nuevaMateria) {
    if (estudiante->cantidadMaterias < MAX_MATERIAS) {
        strcpy(estudiante->materias[estudiante->cantidadMaterias], nuevaMateria);
        estudiante->cantidadMaterias++;
    } else {
        printf("No se pueden agregar más materias\n");
    }
}

// Función para eliminar una materia del estudiante
void eliminarMateria(struct Estudiante *estudiante, const char *materiaAEliminar) {
    for (int i = 0; i < estudiante->cantidadMaterias; ++i) {
        if (strcmp(estudiante->materias[i], materiaAEliminar) == 0) {
            for (int j = i; j < estudiante->cantidadMaterias - 1; ++j) {
                strcpy(estudiante->materias[j], estudiante->materias[j + 1]);
            }
            estudiante->cantidadMaterias--;
            break;
        }
    }
}
