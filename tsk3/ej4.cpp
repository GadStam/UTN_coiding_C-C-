#include <iostream>
#include <cstring>
using namespace std;

struct alumno
{
    char nombre[50];
    char apellido[50];
    int nlegajo; //número de legajo 8 digitos
    int codigo_materia;//codigo de la materia  6digitos
    int dia;
    int mes;
    int ano;

};

struct alumno2{
    char nombre[50];
    char apellido[50];
    int nlegajo; //número de legajo 8 digitos
};

void burbuja(alumno [], int);

int main(){
    

    FILE* f = fopen("DIAFINALES.DAT", "rb");
    FILE*a = fopen("LEGAJO.DAT", "wb+");
    alumno2 alu;
      alumno al;

    fseek(f, 0, SEEK_END);
    int D = ftell(f);
    int cantreg;
    cantreg = D / sizeof(alumno);

    alumno vector[cantreg];
    
    
    
    
    
    alumno2 vec2[cantreg];

    fseek(f, 0, SEEK_SET);

    int i = 0;

    while (fread(&al, sizeof(alumno), 1, f)) 
    {
        vector[i] = al;
        i++;
    }

    burbuja(vector, cantreg);

    

    for(int j = 0; j < cantreg; j++){
        fseek(a, (sizeof(alumno2) * (vector[j].nlegajo - 80001)), SEEK_SET);
        cout << "legajo" << vector[j].nlegajo << endl;
        vec2[j].nlegajo = vector[j].nlegajo;

        cout << "nomre" << vector[j].nombre << endl;
         strcpy(vec2[j].nombre, vector[j].nombre);

         cout << "APELLIDO" << vector[j].apellido << endl;
         strcpy(vec2[j].apellido, vector[j].apellido);

        
    

    // Escribimos los datos en el archivo LEGAJO.DAT
    fwrite(&vec2[j], sizeof(alumno2), 1, a);
    }

    fclose(f);
    fclose(a);



    cout << "Contenido del archivo LEGAJO.DAT:" << endl;
FILE* B = fopen("LEGAJO.DAT", "rb+");
alumno2 vec2_read;
while (fread(&vec2_read, sizeof(alumno2), 1, B)) {
    if(vec2_read.nlegajo != 0){

    
    cout << "Legajo: " << vec2_read.nlegajo << endl;
    cout << "Nombre: " << vec2_read.nombre << endl;
    cout << "Apellido: " << vec2_read.apellido << endl;
    cout << "---------------------" << endl;
    }
}
fclose(B);

    

  
    

    

        

        
    return 0;
}

void burbuja(alumno vector[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - 1 - i; j++) {
            if (vector[j].nlegajo > vector[j + 1].nlegajo) {
                int aux = vector[j].nlegajo;
                vector[j].nlegajo = vector[j + 1].nlegajo;
                vector[j + 1].nlegajo = aux;
            }
        }
    }
}
