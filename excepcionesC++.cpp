#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;


class FormatoFechaIncorrecto : public std::exception {
public:
    const char* what() const throw() {
        return "Error: Formato de fecha incorrecto";
    }
};


class MateriaNoRegistrada : public std::exception {
public:
    const char* what() const throw() {
        return "Error: Materia no registrada";
    }
};


struct Asistencia {
    string fecha;
    string materia;
    string estado; // asistió, falta, tardanza
};


struct Estudiante {
    string nombre;
    int edad;
    float promedio;
    vector<Asistencia> asistencias; // Vector de asistencias
};


void mostrarAsistencia(const Estudiante& estudiante) {
    cout << "Asistencias de " << estudiante.nombre << ":" << endl;
    for (const auto& asistencia : estudiante.asistencias) {
        cout << "Fecha: " << asistencia.fecha << " | Materia: " << asistencia.materia << " | Estado: " << asistencia.estado << endl;
    }
    cout << endl;
}


void registrarAsistencia(Estudiante& estudiante, const string& fecha, const string& materia, const string& estado) {

    if (fecha.size() != 10 || fecha[4] != '-' || fecha[7] != '-') {
        throw FormatoFechaIncorrecto();
    }


    vector<string> materiasRegistradas = {"Matemáticas", "Física", "Programación"};
    if (find(materiasRegistradas.begin(), materiasRegistradas.end(), materia) == materiasRegistradas.end()) {
        throw MateriaNoRegistrada();
    }

    Asistencia nuevaAsistencia = {fecha, materia, estado};
    estudiante.asistencias.push_back(nuevaAsistencia);
}
