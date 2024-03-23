#include <iostream>
#include <cstring>
using namespace std;

#include <iostream>
#include <cstring>

using namespace std;

//1.
struct infoLD
{
    int campo1;
    char campo2[20+1];
    float campo3;
    int campo4;
};

struct nodoLD
{
    infoLD info;
    nodoLD* sgte;
};

struct infoLS{
    float campo3;
    int campo4;
};

struct nodoLS{
    infoLS info;
    nodoLS* sgte;
};

struct infoLR
{
    float campo1;
    char campo2[20+1];
    nodoLS* ptrSubLista;
};

struct nodoLR
{
    infoLR info;
    nodoLR* sgte;
};


nodoLR* cargarListaDeListas(nodoLD* listaDato)
{
    nodoLR* listaR = NULL;
    nodoLR* nodoAux = NULL;
    infoLR aux1;
    infoLS aux2;
    while(listaDato != NULL){
        aux1 = pop(listaDato);
        aux1.campo1 = 
    }

    while(fread..){
        
    }




   
}