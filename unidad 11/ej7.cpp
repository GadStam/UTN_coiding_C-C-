/*7)Dada una pila desarrollar un procedimiento que ordene la misma de acuerdo al valor de
sus nodos y la retorne. Solo se deben usar pilas. (Definir parámetros y codificar).
*/

#include <iostream>

using namespace std;

struct nodo
{
    int info;
    nodo* sgte;
}; //definimos estructura basica 

void Push(nodo* &, int);
int Pop(nodo* &); // funcioones POP y PUSH

void CargarPila(nodo* &);
void Ordenar(nodo* &);
void MostrarPila(nodo* &);

int main()
{
    nodo* pila = NULL; // Primer Pila se declara con NULL

    CargarPila(pila);


    Ordenar(pila);

    MostrarPila(pila);

    return 0;
}

void Push(nodo* &pila, int val)
{
    nodo* p = new nodo();

    p->info = val;
    p->sgte = pila;

    pila = p;

    return; 
}

int Pop(nodo* &pila)
{
    int val;
    nodo* p = pila;
    val = p->info;
    pila = p->sgte;

    delete p;

    return val;  
}

void CargarPila(nodo* &p)
{
    int input;
    cout << "Ingrese el valor a cargar: ";
    cin >> input;
    while(input > -1)
    {
        Push(p, input);

        cout << "Ingrese el valor a cargar(-1 para terminar): ";
        cin >> input;
    }
    cout << endl;
    return;
}

void Ordenar(nodo* &p)
{
    nodo* aux = NULL;
    int valActual;

    while(p != NULL)
    {
        valActual = Pop(p);
        while (aux != NULL && valActual > aux->info)
        {
            Push(p, aux->info);
            aux = aux->sgte;
        }
        Push(aux, valActual);
    }

    while (aux != NULL)
    {
        valActual = Pop(aux);
        Push(p, valActual);
    }
}


void MostrarPila(nodo* &p)
{
    nodo* aux = NULL;
    int i = 0;
    int vActual;

    while(p != NULL)
    {
        vActual = Pop(p);
        cout << "Pos " << i << ": " << vActual << endl;
        i++;
    }

}