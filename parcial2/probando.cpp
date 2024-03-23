#include <iostream>
#include <cstring>

using namespace std;

struct nodo
{
    int info;
    nodo* sgte;
};

nodo* InsertarOrdenado(nodo*&, int);

int main(){
    nodo* Lista = NULL;
  
    int val;

    cout << "Ingrese un numero: ";
    cin >>val;

    while(val > 0){
        InsertarOrdenado(Lista, val);
        cout << "Ingrese un numero: ";
        cin >>val;


    }
    nodo* aux = Lista; // tengo que actualizarlo despues de cargar

    while(aux != NULL){
        cout << aux->info << endl;
        aux= aux->sgte;
    }
}


nodo* InsertarOrdenado(nodo* &lista, int val)
{
    nodo* n = new nodo();
    n->info = val;
    if(lista == NULL || lista->info > val)
    {
        n->sgte = lista;
        lista = n;
    }
    else
    {
        nodo* aux = lista;
        while(aux->sgte != NULL && aux->sgte->info < val)
            aux = aux->sgte;
        n->sgte = aux->sgte;
        aux->sgte = n;
    }
    return n;
} // devuelve el nodo ya cargado



