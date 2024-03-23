#include <iostream>
#include <cstring>
using namespace std;

struct DESTINOS {
    int Ndestino;
    float distancia;
};

struct Viajes {
    int Patente;
    int Ndestino;
    int Nchofer;
};

void leerViajes(FILE*);


int main() {
    FILE* V = fopen("VIAJES.DAT", "rb");
    //FILE* D = fopen("DESTINOS.DAT", "rb");
    if (!V) {
        cout << "Error al abrir el archivo VIAJES.DAT\n";
        return 1;
    }

    leerViajes(V);

    fclose(V);
    return 0;
}

void leerViajes(FILE* V) {
    Viajes via;
    int i = 0;
    fseek(V, 0, SEEK_END);
    int cantReg = ftell(V) / sizeof(Viajes);
    fseek(V, 0, SEEK_SET);
    Viajes vecViajes[cantReg];
    int Viajes_hechos[1000] = {0};
    int vecKM[cantReg] = {0};

    int vecPatentes[cantReg]; // Se declara el arreglo vecPatentes
    
    // Inicializar vecPatentes con un valor que indique que aún no se ha asignado ninguna patente
    for (int i = 0; i < cantReg; i++) {
        vecPatentes[i] = -1; // Por ejemplo, -1 podría usarse como valor inicial
    }
    
    while (fread(&via, sizeof(Viajes), 1, V)) {
        vecViajes[i] = via;
        i++;
    }

   for (int j = 0; j < cantReg; j++) {
    Viajes_hechos[vecViajes[j].Ndestino]++;
}

for (int i = 0; i < 1000; i++) {
    if (Viajes_hechos[i] > 0) {
        cout << "El destino " << i << " se viajó " << Viajes_hechos[i] << " viaje(s)\n";
    }
}



int destinoactual, contador = 0;
i = 0;
    while (i < cantReg) {
        destinoactual = vecViajes[i].Ndestino;
        cout << "\n\nDestino " << destinoactual;
        contador = 0;
        while (i < cantReg && destinoactual == vecViajes[i].Ndestino) {
            contador++;
            i++;
        }
        if (contador > 0) {
            cout << "\nTotal de viajes con este destino: " << contador;
        }
    }



















    for (int j = 0; j < cantReg; j++) {
        if (vecViajes[j].Ndestino == 116) {
            vecPatentes[j] = vecViajes[j].Patente;
        }
    }

    for (i = 0; i < cantReg; i++) {
        if (vecPatentes[i] > 0) { // Mostrar solo las patentes asignadas
            cout << "La patente del viaje con destino 116 es " << vecPatentes[i] << endl;
        }
    }
}


