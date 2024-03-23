#include <iostream>
#include <cstring>
using namespace std;

struct ACTAS {
    char Libro[7];
    int Folio;
    int Fecha;
    int codigo_materia;
    int legajo;
    char apellido[21];
    int nota; // 0 indica ausente)
};

struct TOTALES {
    char Libro[7];
    int Folio;
    int cantAlumnos;
    int cantAusente;
    int cantAprobados;
    int cantDesaprobados;
};

void leerActas(FILE*, ACTAS[], int);
void escribirTotales(FILE*, TOTALES[], int, ACTAS[]);

int main() {
    FILE* a = fopen("ACTASFINALES.dat", "rb");
    fseek(a, 0, SEEK_END);
    int tamanioArchivo = ftell(a) / sizeof(ACTAS);
    fseek(a, 0, SEEK_SET);

    ACTAS vecActas[tamanioArchivo];

    leerActas(a, vecActas, tamanioArchivo);
    fclose(a);

    FILE* t = fopen("TOTALES.dat", "wb");

    TOTALES vecTotales[tamanioArchivo];

    escribirTotales(t, vecTotales, tamanioArchivo, vecActas);
    fclose(t);

    return 0;
}

void leerActas(FILE* a, ACTAS vecActas[], int size) {
    ACTAS act;
    int i = 0;
    while (fread(&act, sizeof(ACTAS), 1, a)) {
        vecActas[i] = act;
        i++;
    }
}

void escribirTotales(FILE* t, TOTALES vecTotales[], int size, ACTAS vecActas[]) {
    for (int i = 0; i < size; i++) {
        strcpy(vecTotales[i].Libro, vecActas[i].Libro);
        vecTotales[i].Folio = vecActas[i].Folio;
        vecTotales[i].cantAlumnos = 1;

        if (vecActas[i].nota == 0) {
            vecTotales[i].cantAusente = 1;
        } else if (vecActas[i].nota >= 6) {
            vecTotales[i].cantAprobados = 1;
        } else {
            vecTotales[i].cantDesaprobados = 1;
        }
        fwrite(&vecTotales[i], sizeof(TOTALES), 1, t);
    }
}
