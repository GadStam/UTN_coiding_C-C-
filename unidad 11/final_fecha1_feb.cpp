#include <iostream>
#include <cstring>
using namespace std;

struct InfoArch{
 int DNI;
char apeYnom[30];
int Fecha;
char Domicilio[30];
char Centro_de_testeo[30];
char Obra_social[30];
int dosis;
int Fecha_contacto_estrecho;
bool Resultado_test;
};

struct regR{
    Nodo2* postitivos;
    Nodo2 *negativos;
};

struct Info {
    char Obra_social[30];
    regR Resultado_test;
};



struct Nodo1 {
    Info info;
    Nodo1* sgte;
};

struct Pacientes {
    int DNI;
    char apeYnom[30];
    int Fecha;
    char Domicilio[30];
};

struct Nodo2 {
    Pacientes info;
    Nodo2* sgte;
};

int main() {
   FILE* f = fopen("hisopados.DAT", "rb");
   
    
    return 0;
}


void cargarEstructura(FILE* f, Nodo1 ListaP, int contador_resultado){
    InfoArch lec;
    
    while(fread(&lec, sizeof(lec), 1, f)){
        insertarOrdenado(TipoDeDatoElemento arr[], int& len, TipoDeDatoElemento v)

    }
}