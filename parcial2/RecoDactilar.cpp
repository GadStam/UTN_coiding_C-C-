#include <iostream>
#include <cstring>

using namespace std; 

struct RegistroBiometrico {
    int DNI;
    char ApeNom[30];
    int Dedo;
    int Tipo;
    char Subtipo;
};

struct infoTipos{ //info sublista
     int DNI;
    char ApeNom[30];
};

struct nodoSospechoso{  //sublista
infoTipos info;
nodoSospechoso *sgte;
};

struct infoSospechoso{ //info de la principal
    int Dedo;
    nodoSospechoso *sublista;

};

struct nodoDedos{ //principal
    infoSospechoso info;
    nodoDedos* sgte;
};

struct matrisSospechosos{
    nodoDedos* listaDedos;
};


//prototipos
nodoSospechoso* insertarOrdenado(nodoSospechoso*& ,infoSospechoso);
infoSospechoso Pop(nodoSospechoso*&);
nodoSospechoso* cargarMatrizSospechosos(FILE*, nodoSospechoso*&);
nodoDedos* insertarSinRepetir(nodoSospechoso*& ,infoSospechoso);

void mostrarLista(nodoSospechoso*);


int main(){
    FILE *archivo = fopen("datos.txt", "r");
    matrisSospechosos vecDedos[4][9];
    cargarMatrizSospechosos(archivo, vecDedos);
}



nodoSospechoso* cargarMatrizSospechosos(FILE* f, matrisSospechosos vecDedos[][9]){

RegistroBiometrico reg;
int Fila,Columna;

nodoDedos* auxDedos;
infoTipos auxSublist;

while(fread(&reg,sizeof(RegistroBiometrico), 1, f)){
    Fila=reg.Tipo-1;//1
    Columna=reg.Subtipo;//G
    auxDedos = insertarSinRepetir(vecDedos[Fila][Columna].listaDedos,reg.Dedo);
    strcpy(auxSublist.ApeNom,reg.ApeNom);
    auxSublist.DNI=reg.DNI;

    insertarOrdenado(auxDedos->info.sublista,auxSublist);


}


}


void mostrarLista(matrisSospechosos vecDedos[][9], int Fila, int Columna){
    nodoDedos* auxDedos = vecDedos[Fila][Columna].listaDedos;
    nodoSospechoso* auxSos;

    while(auxDedos != NULL){
        if(auxDedos->info.Dedo == 1){
            cout<<"Nomre de Dedos: "<<"Pulgar"<<endl;
        }else if(auxDedos->info.Dedo == 2){
            cout<<"Nomre de Dedos: "<<"Indice"<<endl;
        }
        
        auxSos = auxDedos->info.sublista;

        while(auxSos != NULL){
            cout<<"Apellido y Nombre: "<<auxSos->info.ApeNom<<endl;
            cout<<"Dni: "<<auxSos->info.DNI<<endl;

            auxSos=auxSos->sgte;

        }

        auxDedos=auxDedos->sgte;

    }
}