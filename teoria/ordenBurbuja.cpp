#include <iostream>
using namespace std;
void ordenamientoBurbuja(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        // En cada iteración, el elemento más grande se desplaza al final del arreglo
        for (int j = 0; j < size - i - 1; j++) {
            // Compara el elemento actual con el siguiente elemento
            if (arr[j] > arr[j + 1]) {
                // Si el elemento actual es mayor que el siguiente, intercambiarlos
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}


int main() {
    int arreglo[] = {64, 34, 25, 12, 22, 11, 90};
    int tamano = 7;

    cout << "Arreglo original: ";
    for (int i = 0; i < tamano; i++) {
        cout << arreglo[i] << " ";
    }

    ordenamientoBurbuja(arreglo, tamano);

    cout << "\nArreglo ordenado: ";
    for (int i = 0; i < tamano; i++) {
        cout << arreglo[i] << " ";
    }

    return 0;
}
