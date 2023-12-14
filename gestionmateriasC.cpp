#include <stdio.h>
#include <string.h>

#define MAX_MATERIAS 10
#define MAX_NOMBRE 50


struct Estudiante {
    char nombre[MAX_NOMBRE];
    int edad;
    float promedio;
    char materias[MAX_MATERIAS][MAX_NOMBRE];
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


void agregarMateria(struct Estudiante *estudiante, const char *nuevaMateria) {
    if (estudiante->cantidadMaterias < MAX_MATERIAS) {
        strcpy(estudiante->materias[estudiante->cantidadMaterias], nuevaMateria);
        estudiante->cantidadMaterias++;
    } else {
        printf("No se pueden agregar más materias\n");
    }
}


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

int main() {

    struct Estudiante estudiante1;


    strcpy(estudiante1.nombre, "Alberto");
    estudiante1.edad = 18;
    estudiante1.promedio = 8;
    estudiante1.cantidadMaterias = 0;


    agregarMateria(&estudiante1, "Matemáticas");
    agregarMateria(&estudiante1, "Física");
    agregarMateria(&estudiante1, "Programación");


    mostrarEstudiante(estudiante1);


    eliminarMateria(&estudiante1, "Física");

  
    mostrarEstudiante(estudiante1);

    return 0;
}
