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

