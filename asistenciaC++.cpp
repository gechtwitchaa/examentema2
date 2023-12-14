#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;


struct Asistencia {
    string fecha;
    string materia;
    string estado;
};


struct Estudiante {
    string nombre;
    int edad;
    float promedio;
    vector<Asistencia> asistencias;
};

void mostrarAsistencia(const Estudiante& estudiante) {
    cout << "Asistencias de " << estudiante.nombre << ":" << endl;
    for (const auto& asistencia : estudiante.asistencias) {
        cout << "Fecha: " << asistencia.fecha << " | Materia: " << asistencia.materia << " | Estado: " << asistencia.estado << endl;
    }
    cout << endl;
}


void registrarAsistencia(Estudiante& estudiante, const string& fecha, const string& materia, const string& estado) {
    Asistencia nuevaAsistencia = {fecha, materia, estado};
    estudiante.asistencias.push_back(nuevaAsistencia);
}

int main() {

    Estudiante estudiante1;


    estudiante1.nombre = "Alberto";
    estudiante1.edad = 18;
    estudiante1.promedio = 8;


    registrarAsistencia(estudiante1, "2023-12-01", "Matemáticas", "asistió");
    registrarAsistencia(estudiante1, "2023-12-02", "Física", "falta");
    registrarAsistencia(estudiante1, "2023-12-03", "Programación", "tardanza");

    
    mostrarAsistencia(estudiante1);

    return 0;
}

