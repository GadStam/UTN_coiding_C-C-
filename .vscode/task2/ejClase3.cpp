#include <iostream>
using namespace std;

struct producto {
    int idProducto;
    int cantidadVendida;
};

void apareo(producto[], producto[], int, int, producto[], int&);

int main() {
    int N = 5;
    int M = 3;
    int h = 0;
    producto ventas[N] = { {1, 4}, {2, 46}, {3, 8}, {4, 10}, {5, 12} };
    producto novedades[M] = { {1, 5}, {2, 7}, {3, 9} };

    producto resultante[N + M];

    apareo(ventas, novedades, N, M, resultante, h);

    for (int i = 0; i < h; i++) {
        cout << "ID del producto: " << resultante[i].idProducto << ", Cantidad vendida: " << resultante[i].cantidadVendida << endl;
    }

    return 0;
}

void apareo(producto ventas[], producto novedades[], int N, int M, producto resultante[], int& h) {
    int i = 0;
    int j = 0;
    int k = 0;

    while ((i < N) && (j < M))
    {
        if (ventas[i].idProducto > novedades[j].idProducto)
        {
            resultante[k] = ventas[i];
            i++;
        }
        else
        {
            if (ventas[i].idProducto == novedades[j].idProducto)
            {
                resultante[k] = {ventas[i].idProducto, ventas[i].cantidadVendida + novedades[j].cantidadVendida};
                i++;
                j++;
            }
            else
            {
                resultante[k] = novedades[j];
                j++;
            }
        }
        k++;
    }

    while (i < N)
    {
        resultante[k] = ventas[i];
        i++;
        k++;
    }

    while (j < M)
    {
        resultante[k] = novedades[j];
        j++;
        k++;
    }

    h = k;

    

    return;
}



