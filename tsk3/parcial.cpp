/*Escribir un programa que procese los datos en un archivo €sv que contiene la información de las
calificaciones de alumos de un curso. Para cada alumo, se tiene: nombre, apellido, puntaje del
proceso y puntaje del examen final (ambas de 0 a 100).

Para el puntaje final del curso, se calcula de la siguiente manera:
puntaje_final_curso = 0.4*puntaje_proceso + 0.6"puntaje_examen_final

El programa crear otro archivo en donde se añada un campo que contenga el puntaje final
del curso para cada alumno */

#include <iostream>
#include <cstring>
using namespace std;

struct Alumno{
    char nombres[50];
    char apellidos[50];
    int calificacionProcesamiento;
    int calificacionFinal;
};

struct Alu2{
    char nombres[50];
    char apellidos[50];
    int calificacionProcesamiento;
    int calificacionFinal;
    int puntaje_final_curso;
};

void leerAlumnos(FILE*, Alumno[], Alu2[], int);
void escribirArchivo(Alu2[], int, FILE*);

int main(){
    FILE* A = fopen("ALUMNOS.DAT", "rb");
    fseek(A, 0, SEEK_END);
    int cant_reg = ftell(A) / sizeof(Alumno);
    fseek(A, 0, SEEK_SET);
    Alumno vecAlumnos[cant_reg];
    Alu2 vecEscribir[cant_reg];

    leerAlumnos(A, vecAlumnos, vecEscribir, cant_reg);

    fclose(A);

    FILE* F = fopen("FINAL.DAT", "wb+");

    int i = 0;

    escribirArchivo(vecEscribir, cant_reg, F);
   
    return 0;


}

void leerAlumnos(FILE*A, Alumno vecAlumnos[], Alu2 vecEscribir[], int size){
    int i = 0;
    Alumno al;
    while(fread(&al, sizeof(Alumno), 1, A)){
        vecAlumnos[i] = al;
        i++;
    }

    for(i = 0; i < size; i++){
        strcpy(vecEscribir[i].nombres, vecAlumnos[i].nombres);
        strcpy(vecEscribir[i].apellidos, vecAlumnos[i].apellidos);
        vecEscribir[i].calificacionProcesamiento = vecAlumnos[i].calificacionProcesamiento;
        vecEscribir[i].calificacionFinal = vecAlumnos[i].calificacionFinal;
        vecEscribir[i].puntaje_final_curso = 0.4*vecAlumnos[i].calificacionProcesamiento + 0.6*vecAlumnos[i].calificacionFinal;
    }


}

void escribirArchivo(Alu2 vecEscribir[], int cant_reg, FILE* F){
    int i = 0;
     while(i < cant_reg){
        fwrite(&(vecEscribir[i]),sizeof (Alu2 ), 1,F);
        i++;
    }

}

