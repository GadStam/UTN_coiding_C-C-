#include <iostream>
#include <cstring>

using namespace std;

struct VENDEDORES{
    char idVendedor[10];
    char apeYNom[20];
};

struct MODELOS{
    char idModelo[4];
    char descripcion[20];
};

struct VENTAS{
    char idModelo[4];
    char idVendedor[10];
    int fecha;
    char cliente[20];
};

//void OrdenarVendedores(VENDEDORES [], int);

//void OrdenarModelos(MODELOS [], int);

void EmitirListado(VENDEDORES [], VENTAS [], MODELOS [], int, int, int);
int busquedaVendedor(char[], VENDEDORES[], int);
void contarVentasDiarias(VENTAS[], int);

int main(){

    int cant_vendedores = 2;
    int cant_modelos = 2;
    int cant_ventas = 4
    ;

    VENDEDORES vecVendedores[cant_vendedores];
    MODELOS vecModelos[cant_modelos];
    VENTAS vecVentas[cant_ventas];

    for(int i = 0; i < cant_vendedores; i++){
        cout << "Ingrese el id del vendedor: " << endl;
        cin >> vecVendedores[i].idVendedor;
         cout << "Ingrese apellido: " << endl;
        cin >> vecVendedores[i].apeYNom;

    }

    for(int i = 0; i < cant_modelos; i++){
         cout << "Ingrese el id del modelo: " << endl;
        cin >> vecModelos[i].idModelo;
         cout << "Ingrese descrpcion: " << endl;
        cin >> vecModelos[i].descripcion;
    }

cout << "carga el general" << endl;
    for(int i = 0; i < cant_ventas; i++){
        cout << "Ingrese el id del modelo: " << endl;
        cin >> vecVentas[i].idModelo;
         cout << "Ingrese el id del vendedor: " << endl;
        cin >> vecVentas[i].idVendedor;
        cout << "Ingrese fecha: " << endl;
        cin >> vecVentas[i].fecha;
        cout << "Ingrese descripcion: " << endl;
        cin >> vecVentas[i].cliente;

    }

    EmitirListado(vecVendedores, vecVentas, vecModelos, cant_ventas, cant_vendedores, cant_modelos);









    return 0;
}


void EmitirListado(VENDEDORES vecVendedores[], VENTAS vecVentas[], MODELOS vecModelos[], int cant_ventas, int cant_vendedores, int cant_modelos){
    for(int i = 0; i < cant_ventas; i++){
        cout << "cliente: " << vecVentas[i].cliente << endl;
        char buscar_vendedor[10];
        strcpy(buscar_vendedor, vecVentas[i].idVendedor);
        int vendedor_encontrado;
        vendedor_encontrado = busquedaVendedor(buscar_vendedor, vecVendedores, cant_vendedores);
        cout << "apellido y nombre del vendedor: " << vecVendedores[vendedor_encontrado].apeYNom << endl;


        contarVentasDiarias(vecVentas, cant_ventas);




    }
}

int busquedaVendedor(char buscar[], VENDEDORES vecVendedores[], int size){
    int i = 0;
    int encontrado;
    while(i < size && strcmp(vecVendedores[i].idVendedor, buscar) != 0){
        i++;

    }
    encontrado = i;
    return encontrado;

}

void contarVentasDiarias(VENTAS vecVentas[], int size){
    int dia;
    int contador = 0;
    int i = 0;
    while(i < size){
        dia = vecVentas[i].fecha;
        contador = 0;
        cout << "dia: " << vecVentas[i].fecha;
        while(i < size && dia == vecVentas[i].fecha){
            contador++;
            i++;
        }
        if(contador>0){
                cout<<"\nTotal de ventas: "<< contador;
            }

    }
}