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
