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
