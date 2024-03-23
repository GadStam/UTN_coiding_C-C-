#include <iostream>
#include <cstring>
using namespace std;



struct Info{
    int numeroDePiso;
    int personasQueSuben;
    int personasQueBajan;
};

struct Nodo {
    Info info;
    Nodo* pisoAnterior;
    Nodo* pisoSiguiente;
};

struct Escritura{
    int numeroDePiso;
    int difSubenBajan;
};

void EliminarLosPisosPrimosArribaDe(FILE*, Nodo*&);
void EliminarPiso(Nodo*&);
bool Esprimo(int);



void EliminarPiso(Nodo* & unPiso) {
if (unPiso->pisoSiguiente != NULL) {
unPiso->pisoSiguiente->pisoAnterior = unPiso->pisoAnterior;
}
if (unPiso->abajo != NULL) {
unPiso->abajo->pisoSiguiente = unPiso->pisoSiguiente;
}
delete(unPiso);
}





    
