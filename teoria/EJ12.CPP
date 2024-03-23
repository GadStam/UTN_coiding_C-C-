
#include <iostream>
#include <cstring>
using namespace std;


struct Alumnos{
    int Curso;
    char nom_al[30];
    int legajo;
    char turno[1];
};

int calcularCantGrupos();

void leerArchivo(FILE, Alumnos, int);


int main(){
    FILE* f = fopen("MATFINALES.DAT", "rb");

    int cantGrupos = calcularCantGrupos();

    Alumnos Al;

    leerArchivo(f, Al, cantGrupos);






   




    return 0;
}


int calcularCantGrupos(){
    int cantidad;
    cout << "ingrese cantidad de grupos por grupo" << endl;
    cin >> cantidad;
    return cantidad;
}

void leerArchivo(FILE* f, Alumnos Al, int Cant){
while (fread(&Al, sizeof(Alumnos), 1, f)) { 
}
fseek(f, 0, SEEK_END);
int D = ftell(f);
cout<<"El tamaño del archivo es: "<<D<<endl;

// Cerrar el archivo después de la lectura
    fclose(f);

}





void ordenamientoBurbuja(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        // En cada iteración, el elemento más grande se desplaza al final del arreglo
        for (int j = 0; j < size - i - 1; j++) {
            // Compara el elemento actual con el siguiente elemento
            if (arr[j] > arr[j + 1]) {
                // Si el elemento actual es mayor que el siguiente, intercambiarlos
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}





































   

    

    

