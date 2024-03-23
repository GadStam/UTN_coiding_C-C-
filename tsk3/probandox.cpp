#include <iostream>
#include <cstring>
using namespace std;

struct Alumnos{
    int curso;
    char alumno[30];
    int legajo;
    char turno[2];
    
};
void cargarDatos(FILE*, Alumnos);
void leerArchivo(FILE*,Alumnos[],int);
void burbuja(Alumnos[],int);
void informarResultados(Alumnos[],int);

int main(){
    FILE* r = fopen("REGISTROSAL.DAT","wb+");
    Alumnos al;

    cargarDatos(r, al);

    fclose(r);

    FILE* f = fopen("REGISTROSAL.DAT", "rb");
    fseek(f, 0, SEEK_END);
    int tamArchivo = ftell(f) / sizeof(Alumnos);
    fseek(f, 0, SEEK_SET);

    Alumnos vecAlumnos[tamArchivo];

    

    leerArchivo(f, vecAlumnos, tamArchivo );

    burbuja(vecAlumnos, tamArchivo);

    informarResultados(vecAlumnos, tamArchivo);



    fclose(f);










    return 0;
}

void burbuja(Alumnos vecAlumnos[], int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size - 1 - i; j++) {
            // Primero se compara por "curso"
            if (vecAlumnos[j].curso > vecAlumnos[j + 1].curso) {
                // Intercambio por "curso"
                Alumnos aux = vecAlumnos[j];
                vecAlumnos[j] = vecAlumnos[j + 1];
                vecAlumnos[j + 1] = aux;
            }
            // Si los cursos son iguales, se compara por "legajo"
            else if (vecAlumnos[j].curso == vecAlumnos[j + 1].curso &&
                     vecAlumnos[j].legajo > vecAlumnos[j + 1].legajo) {
                // Intercambio por "legajo"
                Alumnos aux = vecAlumnos[j];
                vecAlumnos[j] = vecAlumnos[j + 1];
                vecAlumnos[j + 1] = aux;
            }
        }
    }
}


void leerArchivo(FILE*f,Alumnos vecAlumnos[],int size){
    Alumnos al;
    int i = 0;
    while(fread(&al, sizeof(Alumnos), 1, f)){
        vecAlumnos[i] = al;
        i++;
    }
}

void informarResultados(Alumnos vecAlumnos[],int size){

    int contador = 0;
    int i = 0;
    int curso;
    int cant_grupos;
    int total = 0;;
    
    while(i < size){
        curso = vecAlumnos[i].curso;
        contador = 0;
        cout << "el curso es k" << vecAlumnos[i].curso << endl;
        while(i < size && curso == vecAlumnos[i].curso){
            contador++;
            cout << "el legajo es " << vecAlumnos[i].legajo << endl;
            i++;
        }
        cout<<contador<<" es la cantidad de alumnos"<<endl;
        cout << "ingrese cantidad grupos" << endl;
        cin >> cant_grupos;
        
        if((contador % cant_grupos) != 0){
            cant_grupos += 1;
        }
        cout << "cantidad grupos: " << cant_grupos << endl;

        total += cant_grupos;

    
    }

    cout << "total grupos " << total << endl;
    

} 

void cargarDatos(FILE* f, Alumnos al){
    cout << "Ingrese un nombre:";
    cin >> al.alumno;

    while(strcmp(al.alumno, "x") != 0)
    {
        cout << "Ingrese legajo:" << endl;
        cin >> al.legajo;
        cout << "Ingrese curso:" << endl;
        cin >> al.curso;
        cout << "Ingrese turno:" << endl;
        cin >> al.turno;

        fwrite(&al, sizeof(Alumnos), 1, f);

        cout << "Ingrese un nombre (x para terminar): ";
        cin >> al.alumno;
    }
}


    