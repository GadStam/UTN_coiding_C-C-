#include <iostream>
using namespace std;

struct curso {
    int numlegajo;
    int notas;
};

void cargarDatos(curso[], int);

int main() {
    int cantAlumnos;
    cout << "INGRESE LA CANTIDAD DE ALUMNOS: ";
    cin >> cantAlumnos;

    while (cantAlumnos > 21) {
        cout << "INGRESE DE NUEVO LA CANTIDAD DE ALUMNOS: ";
        cin >> cantAlumnos;
    }

    curso vecAlumnos[cantAlumnos];

    cargarDatos(vecAlumnos, cantAlumnos);

    return 0;
}

void cargarDatos(curso vecAlumnos[], int cantAlumnos) {
    int cantidadNotas[11] = {0}; 
    for (int i = 0; i < cantAlumnos; i++) {
        cout << "Ingrese el número de legajo del alumno " << i + 1 << ": ";
        cin >> vecAlumnos[i].numlegajo;

        cout << "Ingrese la nota del alumno " << i + 1 << ": ";
        cin >> vecAlumnos[i].notas;

        cantidadNotas[vecAlumnos[i].notas]++;
    }

    
    for (int i = 0; i <= 10; i++) {
        cout << "Cantidad de alumnos con nota " << i << ": " << cantidadNotas[i] << endl;
    }
}
