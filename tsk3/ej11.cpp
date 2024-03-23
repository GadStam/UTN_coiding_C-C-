#include <iostream>
#include <cstring>
using namespace std;


struct Calzados{
    int modelo;
    char color[1];
    int cant_vendida;
};

void cargarDatos(FILE*, Calzados);
void leerDatos(FILE*);

int main(){

    FILE* f=fopen("INFORME.DAT", "wb+");

    Calzados cal;

    cargarDatos(f,cal);
    fclose(f);



    f = fopen("INFORME.DAT", "rb");
    leerDatos(f);
    fclose(f);
    











    return 0;
}

void cargarDatos(FILE* f, Calzados cal){
    int cantidad;
    cout<<"Ingrese la cantidad de objetos: "; cin>>cantidad;
    for (int i = 0; i<cantidad ;i++){
        cout << "ingrese el modelo " << endl;
        cin >> cal.modelo;
        cout << "ingrese el color " << endl;
        cin >> cal.color;
        cout << "ingrese la cantidad " << endl;
        cin >> cal.cant_vendida;
        fwrite(&cal, sizeof(Calzados), 1, f);
         


        }
}







void leerDatos(FILE* f){
    
    fseek(f, 0, SEEK_SET);

    int contadorPorModelo[7] = {0};
    int contadorPorColor[5] = {0}; // Contador para cada color 'a', 'b', 'c', 'd', 'e'
    int total =0;

    Calzados cal;
    while (fread(&cal, sizeof(Calzados), 1, f)) {
        contadorPorModelo[cal.modelo - 1] += cal.cant_vendida;
        total += cal.cant_vendida;
        }


    
     cout << "Cantidad de cada modelo:" << endl;
    for (int i = 0; i < 7; i++) {
        cout << "Modelo " << i + 1 << ": " << contadorPorModelo[i] << " unidades vendidas." << endl;
    }
    cout << "total es " << total << endl;
    
}
