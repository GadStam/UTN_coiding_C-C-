#include <iostream>
#include <cstring>
#include <fstream>
using namespace std;

struct Viajes {
    int Patente;
    int Ndestino;
    int Nchofer;
};

int main() {
    FILE* f = fopen("VIAJES.DAT", "wb+");
    // wb wb+ rb rb+
    Viajes via;

    cout << "Ingrese patente (x para terminar): ";
    cin >> via.Patente;

    while (via.Patente != 0) {
        cout << "Ingrese numero chofer: ";
        cin >> via.Nchofer;
        cout << "Ingrese numero destino: ";
        cin >> via.Ndestino;

        fwrite(&via, sizeof(Viajes), 1, f);

        cout << "Ingrese patente (x para terminar): ";
        cin >> via.Patente;
    }

    fclose(f);

     
    return 0;
}
