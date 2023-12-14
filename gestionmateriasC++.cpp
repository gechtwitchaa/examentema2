#include <iostream>
#include <vector>
#include <string>

using namespace std;


struct Estudiante {
    string nombre;
    int edad;
    float promedio;
    vector<string> materias; // Vector de materias
};


void mostrarEstudiante(const Estudiante& estudiante) {
    cout << "Nombre: " << estudiante.nombre << endl;
    cout << "Edad: " << estudiante.edad << endl;
    cout << "Promedio: " << estudiante.promedio << endl;

    cout << "Materias inscritas:" << endl;
    for (const auto& materia : estudiante.materias) {
        cout << "- " << materia << endl;
    }
    cout << endl;
}


void agregarMateria(Estudiante& estudiante, const string& nuevaMateria) {
    estudiante.materias.push_back(nuevaMateria);
}


void eliminarMateria(Estudiante& estudiante, const string& materiaAEliminar) {
    for (auto it = estudiante.materias.begin(); it != estudiante.materias.end(); ++it) {
        if (*it == materiaAEliminar) {
            estudiante.materias.erase(it);
            break;
        }
    }
}

int main() {

    Estudiante estudiante1;


    estudiante1.nombre = "Alberto";
    estudiante1.edad = 18;
    estudiante1.promedio = 8;


    agregarMateria(estudiante1, "Matemáticas");
    agregarMateria(estudiante1, "Física");
    agregarMateria(estudiante1, "Programación");


    mostrarEstudiante(estudiante1);


    eliminarMateria(estudiante1, "Física");

  
    mostrarEstudiante(estudiante1);

    return 0;
}

