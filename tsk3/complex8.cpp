#include <iostream>
#include <cstring>
#include <fstream>
using namespace std;


struct Vuelo{
    char codigo[7];
    int cantidad_libres;
};

int main() {
    FILE* f = fopen("ARCHIVOVUELO.DAT", "wb+");
    // wb wb+ rb rb+
    Vuelo vue;

    cout << "Ingrese pasajes disponibles (x para terminar): ";
    cin >> vue.cantidad_libres;

    while (vue.cantidad_libres != 0) {
       cout << "Ingrese Codigo : ";
            cin >> vue.codigo;

        fwrite(&vue, sizeof(Vuelo), 1, f);

         cout << "Ingrese pasajes disponibles (x para terminar): ";
    cin >> vue.cantidad_libres;
    }

    fclose(f);

     
    return 0;
}
