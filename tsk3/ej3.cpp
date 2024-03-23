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

int main()
{
    alumno al;

    FILE* input = fopen("DIAFINALES.DAT", "rb");
    FILE* output = fopen("MATFINALES.DAT", "wb+");

    int codigoDeseado;

    cout << "Ingrese el código de materia deseado: ";
    cin >> codigoDeseado;

    int size = sizeof(al);
    while(fread(&al, size, 1, input))
    {
        if(al.codigo_materia == codigoDeseado)
        {
            fwrite(&al, size, 1, output);
        }
    }
    fclose(input);

    cout << endl << "Se ha creado un archivo \"MATFINALES.DAT\" que contiene los alumnos que deben rendir esa materia" << endl;
    cout << endl << "Los alumnos inscriptos a finales son: " << endl;

    fseek(output, 0, SEEK_SET);
    while(fread(&al, size, 1, output))
    {
        cout << "   " << al.nombre << endl;
    }
    cout << endl;
    fclose(output);

    return 0;
}