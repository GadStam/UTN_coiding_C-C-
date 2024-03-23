#include <iostream>
using namespace std;

int busquedaBinaria(int arr[], int size, int objetivo) {
    int izquierda = 0;
    int derecha = size - 1;

    while (izquierda <= derecha) {
        int medio = izquierda + (derecha - izquierda) / 2;

        if (arr[medio] == objetivo) {
            return medio; // El elemento se encuentra en la posición 'medio'
        } else if (arr[medio] < objetivo) {
            izquierda = medio + 1; // Buscar en la mitad derecha de la lista
        } else {
            derecha = medio - 1; // Buscar en la mitad izquierda de la lista
        }
    }

    return -1; // El elemento no se encuentra en la lista
}

int main() {
		int sizeArr = 7;
    int arreglo[] = {1, 3, 5, 7, 9, 11, 13};
    int objetivo = 9;

    int resultado = busquedaBinaria(arreglo, sizeArr, objetivo);
    if (resultado != -1) {
        cout << "El elemento " << objetivo << " se encuentra en la posición " << resultado << "." << endl;
    } else {
        cout << "El elemento " << objetivo << " no se encuentra en la lista." << endl;
    }

    return 0;
}