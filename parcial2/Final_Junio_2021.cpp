#include <iostream>
#include <cstring>
using namespace std;

struct infoSub{
    float Campo3;
    int Campo4;
};

struct subList{
infoSub info;
subList* sgte;
};

struct infoR{
    int Campo1;
    char Campo2 [20];
    subList* ptrSub;
};

struct ListaResultado{
infoR info;
ListaResultado *sgte;
} ;



struct infoLD{
        int Campo1;
        char Campo2 [20];
        float Campo3;
        int Campo4;
};


struct ListaDato{
infoLD info;
ListaDato* sgte;
};




ListaResultado* InsertarOrdenado(ListaResultado*&, infoR, infoR);



ListaResultado* cargarListaDeListas(ListaDato* ListaLD){
    ListaResultado* ListaRes = NULL;
    ListaResultado* NodoAux = ListaRes;
    infoR infoAuxiliar;

    while(ListaLD != NULL){
        
        NodoAux = insertarSinRepetir(ListaRes, ListaLD->info.Campo1, ListaLD->info.Campo2);
        insertarOrdenado(ListaRes->info.ptrSub, ListaLD->info.Campo3, ListaLD->info.Campo4);

        ListaLD = ListaLD->sgte;


    }
    return NodoAux;

}



mian:

nodoLr ListaResultado = cargarListaDeListas(ListaDato);
 nodoLR* cargarListaDeListas(nodoLD* listaDato)
{
    nodoLR* listaR = NULL;
    nodoLR* nodoAux = NULL;

    infoLD auxLD;
    infoLS auxLS;
    infoLR auxLR;

    while(listaDato!=NULL)
    {
        auxLD = pop(listaDato);

        auxLR.campo1 = auxLD.campo1;
        strcpy(auxLR.campo2, auxLD.campo2);

        auxLS.campo3 = auxLD.campo3;
        auxLS.campo4 = auxLD.campo4; 
        nodoAux = insertarSinRepetir(listaR,auxLR);

        insertarOrdenado(nodoAux->info.ptrSubLista, auxLS);
    }
    return listaR;
}


















struct NodoSubLista{
    int info;
    NodoSubLista* sgte;
};



struct infoLD{
        int Campo1;
        int Campo2;

};

struct ListaResultado{
infoR info;
ListaResultado *sgte;
} ;

