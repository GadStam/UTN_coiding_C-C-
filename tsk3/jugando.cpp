#include <iostream>
#include <cstring>
using namespace std;

struct Jugador{
    char nombre[30];
    int edad;
};

int main(){
    FILE* archivo = fopen("JOGA.DAT", "wb+");
    Jugador jug;
    int cant;
    cout << "ingrese cant" << endl;
    cin >> cant;
    Jugador vecJugadores[cant];
    int i =0;
    cout << "ingrse nombre" << endl;
    cin >> jug.nombre;
    strcpy(vecJugadores[i].nombre, jug.nombre);
    while(strcmp(jug.nombre, "x") != 0){
        cout << "ingrese edad" << endl;
        cin >> jug.edad;
        vecJugadores[i].edad = jug.edad;
        fwrite(&vecJugadores[i], sizeof(Jugador), 1, archivo);
        i++;
         cout << "ingrse nombre(x para terminar)" << endl;
            cin >> jug.nombre;
            strcpy(vecJugadores[i].nombre, jug.nombre);
    }

     

    fclose(archivo);





    return 0;
}



