#include <iostream>
#include <cstring>
using namespace std;

struct Destinos{
int numero_destino;
int distancia;

};

struct Viajes{
    int Patente;
    int Ndestino;
    int Nchofer;

};


void leerDestinos(FILE*);
void leerViajes(FILE*);

int main(){

    FILE* v = fopen("VIAJES.DAT", "rb");

    leerViajes(v);
    fclose(v);

   



    return 0;
}

void leerViajes (FILE *v){
    Viajes via;
    int Viajes_hechos[1000] = {0};
    int Choferes[1000] = {0};
    int Patentes[1000] = {0};
    int PatentesDestino116[1000] = {0};
    fseek(v,0,SEEK_SET);
    while(fread(&via, sizeof(Viajes), 1, v)){
        Viajes_hechos[via.Ndestino]++;
       Choferes[via.Ndestino] = via.Nchofer;
       Patentes[via.Ndestino] = via.Patente;
        
       if (via.Ndestino == 116 && PatentesDestino116[via.Patente] == 0) {
            PatentesDestino116[via.Patente] = 1; // Marcar la patente como registrada
        }



    }
    



    cout << "\nCantidad de viajes realizados a cada destino:" << endl;
    for (int i = 0; i < 1000; i++) {
        if (Viajes_hechos[i] > 0) {
            cout << "Destino " << i << ": " << Viajes_hechos[i] << " viajes" << endl;
        }
        if(Choferes[i] > 0){
            cout << "el chofer numero " << Choferes[i] << "viajo a " << i <<  endl;

        }
        
    }

     for (int i = 0; i < 1000; i++) {
        if (PatentesDestino116[i] == 1) {
            cout << i << endl;
        }
    }
    
}




