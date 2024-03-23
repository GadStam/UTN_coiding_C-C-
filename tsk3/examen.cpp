#include <iostream>
#include <cstring>

using namespace std;

struct alumno
{
    char nombre[30];
    int curso;
    int nlegajo; // número de legajo 8 dígitos
    char turno[2];

};

void cargarDatos(FILE*, alumno);
void leerDatos(FILE*, alumno, alumno [], int);
void ordenarPorCurso(alumno [], int);
void informarResultado(int[], int[], alumno [], int);

int main(){
    FILE* f = fopen("REGISTROSAL.DAT","wb+");
    // wb wb+ rb rb+
    alumno al;

    cargarDatos(f, al);

    fseek(f, 0, SEEK_END);
    int D = ftell(f);

    int cantReg = D / sizeof(alumno);
    cout << "cant registros es:" << cantReg << endl;

    alumno vecAlum[cantReg];

    leerDatos(f, al, vecAlum, cantReg);

    fclose(f);

    return 0;
}

void cargarDatos(FILE* f, alumno al){
    cout << "Ingrese un nombre:";
    cin >> al.nombre;

    while(strcmp(al.nombre, "x") != 0)
    {
        cout << "Ingrese legajo:" << endl;
        cin >> al.nlegajo;
        cout << "Ingrese curso:" << endl;
        cin >> al.curso;
        cout << "Ingrese turno:" << endl;
        cin >> al.turno;

        fwrite(&al, sizeof(alumno), 1, f);

        cout << "Ingrese un nombre (x para terminar): ";
        cin >> al.nombre;
    }
}

void ordenarPorCurso(alumno vecAlum[], int cantReg) {
    for (int i = 0; i < cantReg - 1; i++) {
        for (int j = 0; j < cantReg - i - 1; j++) {
            if (vecAlum[j].curso > vecAlum[j + 1].curso) {
                // Intercambiar los elementos
                alumno temp = vecAlum[j];
                vecAlum[j] = vecAlum[j + 1];
                vecAlum[j + 1] = temp;
            }
        }
    }
}

void leerDatos(FILE* f, alumno al, alumno vecAlum[], int cantReg){
    fseek(f, 0, SEEK_SET);
    int i = 0;
    int contadorPorCurso[30] = {0};
    int contadorGrupos[30] = {0}; // Inicializamos con ceros
    
    while(fread(&al, sizeof(alumno), 1, f)){
        vecAlum[i] = al;
        contadorPorCurso[al.curso - 10]++;
        i++;
    }
    ordenarPorCurso(vecAlum, cantReg);

    for (int i = 0; i < cantReg; i++)
    {
        cout << "nombre alumno:" << vecAlum[i].nombre << endl;
        cout << "curso alumno:" << vecAlum[i].curso << endl;
        
    }
    
    cout << "Cantidad de alumnos por curso:" << endl;
    for (int i = 0; i < 30; i++)
    {
        if (contadorPorCurso[i] > 0)
        {
            cout << "Curso " << i + 10 << ": " << contadorPorCurso[i] << " alumnos" << endl;
            cout << "Ingrese cantidad de grupos del curso K" << i + 10 << ": ";
            cin >> contadorGrupos[i];
            int alumnosRestantes = contadorPorCurso[i] % contadorGrupos[i];
            if(alumnosRestantes > 0){
                contadorGrupos[i]++;

            }
        }
    }

    for (int i = 0; i < 30; i++)
    {
        if (contadorGrupos[i] > 0){
            cout << "Curso " << i + 10 << ": tiene " << contadorGrupos[i] << " grupos" << endl;
            
        }
    }
    informarResultado(contadorGrupos, contadorPorCurso, vecAlum, cantReg);
}



void informarResultado(int grupos[], int cursos[], alumno vecAl[], int cantReg){
    cout << "------------------------------" << endl;
    for(int i = 0; i < 30; i++){
        cout << "Curso K" << i + 10 << endl;
        cout << "Cantidad de grupos: " << grupos[i] << endl;
        for (int j = 0; j < cantReg; j++) {
            if (vecAl[j].curso == i + 10) {
                cout << "Legajo: " << vecAl[j].nlegajo << endl;
            }
        }
         cout << "------------------------------" << endl;
    }
}
