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

void OrdenarVendedores(VENDEDORES [], int);

void OrdenarVentas(VENTAS [], int);

void EmitirListado(VENDEDORES [], VENTAS [], MODELOS [], int);



int main(){
    int numVendes;
    cout << "Ingrese la cantidad de vendedores: ";
    cin >> numVendes;

    VENDEDORES vecVendedores[numVendes];
    cout << "Ingrese el id del vendedor: ";
    cin >> vecVendedores[0].idVendedor;

    int i = 0;
    while (i < numVendes) {
        cout << "Ingrese el id del vendedor (o ingrese '0' para terminar): ";
        cin >> vecVendedores[i].idVendedor;

        if (strcmp(vecVendedores[i].idVendedor, "0") == 0) {
            break; // Si el id es "0", salimos del bucle
        }

        cout << "Ingrese apellido: ";
        cin >> vecVendedores[i].apeYNom;
        i++;
    }

    OrdenarVendedores(vecVendedores, numVendes);

    // Mostramos los vendedores ingresados
    cout << "Vendedores ingresados:" << endl;
    for (int j = 0; j < i; j++) {
        cout << "ID: " << vecVendedores[j].idVendedor << ", Nombre: " << vecVendedores[j].apeYNom << endl;
    }

    




    int numVentas;
    cout << "Ingrese la cantidad de ventas: ";
    cin >> numVentas;

    VENTAS vecVentas[numVentas];
    cout << "Ingrese el id del vendedor: ";
    cin >> vecVentas[0].idModelo;

    int m = 0;
    while (strcmp(vecVentas[m].idModelo, "0") != 0 && m < numVentas) {
        
        cout << "Ingrese fecha: ";
        cin >> vecVentas[m].fecha;
        cout << "Ingrese cliente: ";
        cin >> vecVentas[m].cliente;
        
        m++;
        if (m < numVentas) {
            cout << "Ingrese el id idModelo (o ingrese '0' para terminar): ";
            cin >> vecVentas[m].idModelo;
        }
    }

    // Mostramos los vendedores ingresados
    cout << "Vendedores ingresados:" << endl;
    for (int j = 0; j < i; j++) {
        cout << "ID: " << vecVentas[j].idModelo << ", ID VENDEDOR: " << vecVentas[j].idVendedor << endl;
        cout << "FECHA: " << vecVentas[j].fecha << ", cliente: " << vecVentas[j].cliente << endl;
    }
















    return 0;
}

void OrdenarVendedores(VENDEDORES vecVendedores[], int numVendes) {
    for (int i = 0; i < numVendes - 1; i++) {
        for (int j = 0; j < numVendes - i - 1; j++) {
            if (strcmp(vecVendedores[j].idVendedor, vecVendedores[j + 1].idVendedor) > 0) {
                VENDEDORES temp = vecVendedores[j];
                vecVendedores[j] = vecVendedores[j + 1];
                vecVendedores[j + 1] = temp;
            }
        }
    }
}






