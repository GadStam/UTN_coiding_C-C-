#include <iostream>
#include <cstring>
using namespace std;

struct Jugador{
    char nombre[30];
    int edad;
};

void burbuja(Jugador [], int);

int main(){
    FILE* archivo = fopen("JOGA.DAT", "rb");
    Jugador jug;
    fseek(archivo, 0, SEEK_END);

    int D = ftell(archivo);
    int cantreg =D / sizeof(Jugador);
    Jugador vecJugadores[cantreg];
    int i =0;
    fseek(archivo, 0, SEEK_SET);

    //
    
    while(fread(&jug, sizeof(Jugador),1,archivo)){
        vecJugadores[i] = jug;
        i++;

    

    }

    burbuja(vecJugadores, cantreg);
    cout << "el archivo dice " << endl;
    int mayor11;

    for(int i = 0; i < cantreg; i++){
        cout<<vecJugadores[i].nombre << endl;
        cout<<vecJugadores[i].edad << endl;
        if(vecJugadores[i].edad > 11){
            mayor11++;
        }
        cout << "mayores de 11 son " << mayor11 << endl;


    }

    fclose(archivo);

    return 0;
    

    }



    void burbuja(Jugador vec[], int size){
        for(int i = 0; i < size-1;i++){
            for(int j = 0; j < size-1-i; j++){
                if(vec[j].edad > vec[j+1].edad){
                    int aux = vec[j].edad;
                    vec[j].edad = vec[j+1].edad;
                    vec[j+1].edad=aux;

                }
            }
        }
    }