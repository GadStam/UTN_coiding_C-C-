#include <iostream>
using namespace std;




struct Notas{
        int Nota1;
        int Nota2;
        int Nota3;
    };


struct Curso{
    int legajo;
    char apellido[20];
    char nombre[20];

    Notas NotasAlumno;

    
};

int CargarDatosyBB(Curso vector[], int N, int Buscado);


int main() {
   int N=3;
   Curso vector [N];

   for (int i = 0; i < N; i++) {
        cout << "Ingrese el número de legajo del alumno " << i + 1 << ": ";
        cin >> vector[i].legajo;

        cout << "Ingrese apellido del alumno " << i + 1 << ": ";
        cin >> vector[i].apellido;

        cout << "Ingrese nombre del alumno " << i + 1 << ": ";
        cin >> vector[i].apellido;

        cout << "Ingrese la Nota 1 del alumno " << i + 1 << ": ";
        cin >> vector[i].NotasAlumno.Nota1;

        cout << "Ingrese la Nota 2 del alumno " << i + 1 << ": ";
        cin >> vector[i].NotasAlumno.Nota2;

        cout << "Ingrese la Nota 3 del alumno " << i + 1 << ": ";
        cin >> vector[i].NotasAlumno.Nota3;
}

    int posicion = CargarDatosyBB(vector, N, 456789);

   if(posicion != -1){
    cout << "El legajo es: " << vector[posicion].legajo << "y esta en la posicion " << posicion + 1  << endl;
    cout << "Las Notas son: " << vector[posicion].NotasAlumno.Nota1 << " "<< vector[posicion].NotasAlumno.Nota2 << " " << vector[posicion].NotasAlumno.Nota1 << endl;

   }else{
    cout << "No se encontro ningun legajo en el vector" << endl;
   }



    return 0;
}



int CargarDatosyBB(Curso vector[], int N, int Buscado){

    
    int primero = 0;
    int ultimo = N - 1;
    int medio;
    while (primero <= ultimo) {
        medio = (primero + ultimo) / 2;
        if (vector[medio].legajo == Buscado) {
            return medio;
        } else if (vector[medio].legajo > Buscado) {
            ultimo = medio - 1;
        } else {
            primero = medio + 1;
        }
    }

    return -1;
}




