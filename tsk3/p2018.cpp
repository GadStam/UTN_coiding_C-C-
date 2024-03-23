#include <iostream>
#include <cstring>
using namespace std;

struct Alumnos{
    int curso;
    char alumno[30];
    int legajo;
    char turno[2];
};

void leerArchivo(FILE*,Alumnos[],int);
void burbuja(Alumnos[],int);
void calcAlum(int, Alumnos[],int);

int main(){

    FILE* f = fopen("ALUMNOS.DAT", "rb");
    fseek(f, 0, SEEK_END);
    int tamArchivo = ftell(f) / sizeof(Alumnos);
    fseek(f, 0, SEEK_SET);

    Alumnos vecAlumnos[tamArchivo];

    leerArchivo(f, vecAlumnos, tamArchivo );

    fclose(f);










    return 0;
}



void leerArchivo(FILE* f,Alumnos vecAlumnos[],int size){
    int cant_grupos = 0;
    Alumnos al;
    int i = 0;
    int cantAlu[size] = {0};
    while(fread(&al, sizeof(Alumnos), 1, f)){
        vecAlumnos[i] = al;
        i++;

    }

    burbuja(vecAlumnos, size);
    calcAlum(cantAlu, vecAlumnos, size);

    for(i = 0; i < size; i++){
        cout << "ingrese cant grupos para el curso: " << i+10 << endl;
        cin >> cant_grupos;
        if(cantAlu[i] % cant_grupos == 0){
            cout << "la cantidad de grupos es:" << cant_grupos;
        }else{
            cout << "la cantidad de grupos es:" << cant_grupos+1;

        }
         for(int j = 0; j < size; j++){
                if(vecAlumnos[j].curso == i){
                    cout << "legajos: "<<endl;
                    cout << vecAlumnos[j].legajo << endl;
                }
            }
    }


}

void burbuja(Alumnos vecAlumnos[],int size){
    for(int i = 0; i < size; i++){
        for(int j = 0; j<size-1-i;j++){
            if(vecAlumnos[j].curso > vecAlumnos[j+1].curso){
                int aux = vecAlumnos[j].curso;
                vecAlumnos[j].curso = vecAlumnos[j+1].curso;
                vecAlumnos[j+1].curso=aux ;
            }
        }
    }
}

void calcAlum(int cantAlu [], Alumnos vecAlumnos[],int size){
     for(int i = 0; i < size; i++){
        for(int j = 0; j<size-1-i;j++){
            if(vecAlumnos[j].curso == vecAlumnos[j+1].curso){
                cantAlu[i]++;
            }
        }
    }
}



void corte_control(Alumnos vecAlumnos[],int size){
    int contador = 0;
    int i = 0;
    int curso;
    int cant_grupos;
    while(i < size){
        curso = vecAlumnos[i].curso;
        contador = 0;
        cout << "el curso es " << vecAlumnos[i].curso << endl;
        while(i < size && curso == vecAlumnos[i].curso){
            contador++;
            i++;
        }
        cout<<contador<<"es la cantidad de alumnos"<<endl;
        cout << "ingrese cantidad grupos" << endl;
        cin >> cant_grupos;
        if((contador % cant_grupos) != 0){
            cant_grupos += 1;
        }

    
    }

}