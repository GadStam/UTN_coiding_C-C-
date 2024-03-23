/*8.	Una empresa de aviación realiza 500 vuelos semanales a distintos puntos del pais y requiere un programa 
para el otorgamiento de pasajes. Para ello dispone de un archivo de registros, en el que cada registro contiene 
información de los vuelos que realiza y la cantidad de pasajes disponibles en cada uno de ellos según se indica:
a. Código del vuelo (6 dígitos)
b. Cantidad de pasajes disponibles (3 dígitos)
Se dispone además de otro archivo con los datos de los potenciales compradores, en el que cada registro tiene:
a) Codigo de vuelo solicitado b) Cantidad de pasajes solicitados (3 digitos)
a) DNI del solicitante (8 digitos) d) Apellido y nombres del solicitante (30 caracteres)
Desarrollar estrategia, algoritmo y codificacion del programa que determine e imprima:
1) Para los solicitantes a los cuales se les venden pasajes,

DNI - APELLIDO Y NOMBRES – CANTIDAD DE PASAJES - CODIGO VUELO
99999		XXXXXX		999			999

2) Al final del proceso el siguiente listado:
CODIGO DE VUELO - PASAJES LIBRES  - PASAJES NO VENDIDOS
999999 			999 			999
Se le vende al solicitante si la cantidad de pasajes que solicita esta disponible, en caso contrario se computa como pasajes no vendidos.
*/

#include <iostream>
#include <cstring>
using namespace std;

struct Vuelo{
    char codigo[7];
    int cantidad_libres;
};

struct Compradores{
    char codigo_solicitado[7];
    int pasajes_solicitado;
    int DNI;
    char nombre_apellido[30];
};

void leerComprador(FILE*, Compradores[], int);
void leerVuelo(FILE*, Vuelo[], int);
void listadoFinal(Compradores[], Vuelo[], int);


int main(){

    FILE* c = fopen("ARCHIVOCOMPRADOR.DAT", "rb");
    FILE* v = fopen("ARCHIVOVUELO.DAT", "rb");

    fseek(c, 0, SEEK_END);
    int D = ftell(c);
    int cantreg;
    cantreg = D / sizeof(Compradores);

    fseek(c, 0, SEEK_SET);

    Compradores vecComprador[cantreg];


    fseek(v, 0, SEEK_END);
    int R = ftell(v);
    int cantreg2;
    cantreg2 = R / sizeof(Vuelo);

    fseek(v, 0, SEEK_SET);

    Vuelo vecVuelos[cantreg2];




    leerComprador(c, vecComprador, cantreg);
    leerVuelo(v, vecVuelos, cantreg2);

    listadoFinal(vecComprador, vecVuelos, cantreg);


    fclose(v);
    fclose(c);



    












return 0;
}


void leerComprador(FILE* c, Compradores vecComprador[], int cantreg){

    
    Compradores com;

    int i = 0;

    while(fread(&com, sizeof(Compradores), 1, c)){

        vecComprador[i] = com;
        i++;

    }

    cout << "PASAJEROS" << endl;

    for(int j = 0; j<cantreg; j++){
        cout << "DNI: "<< vecComprador[j].DNI << endl;
        cout << "NOMBRE Y APELLIDO: "<< vecComprador[j].nombre_apellido << endl;
        cout << "CANTIDAD DE PASAJES: "<< vecComprador[j].pasajes_solicitado << endl;
        cout << "CODIGO DE VUELO: "<< vecComprador[j].codigo_solicitado << endl;


    }



}


void leerVuelo(FILE* v, Vuelo vecVuelos[], int cantreg){


    
    Vuelo vuel;

    int i = 0;

    while(fread(&vuel, sizeof(Vuelo), 1, v)){

        vecVuelos[i] = vuel;
        i++;

    }

    cout << "VUELOS:------------" << endl;

    for(int j = 0; j<cantreg; j++){
        cout << "CANT LIBRES: "<< vecVuelos[j].cantidad_libres<< endl;
        cout << "COD VUELO: "<< vecVuelos[j].codigo << endl;
        

    }
}


void listadoFinal(Compradores vecComprador[], Vuelo vecVuelos[], int cantreg){
    for(int i = 0; i < cantreg; i++){

        int vueloEncontrado = 0;
        for(int j = 0; j < cantreg; j++){

        if (strcmp(vecComprador[i].codigo_solicitado, vecVuelos[j].codigo) == 0){
            int vueloEncontrado = j;
        }
        }
        int pasajesSolicitados = vecComprador[i].pasajes_solicitado;
         vecVuelos[vueloEncontrado].cantidad_libres -= pasajesSolicitados;

    }

    cout << "-------------------------" << endl;
    cout << "CODIGO DE VUELO - PASAJES LIBRES - PASAJES NO VENDIDOS" << endl;
    for (int i = 0; i < cantreg; i++) {
        cout << vecVuelos[i].codigo << "\t\t" << vecVuelos[i].cantidad_libres << "\t\t" << 500 - vecVuelos[i].cantidad_libres << endl;
    }

    
}

