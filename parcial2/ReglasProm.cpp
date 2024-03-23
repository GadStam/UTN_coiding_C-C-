#include <iostream>
#include <cstring>
using namespace std;

struct Archivo
{
    int curso;
    int idEstudiante;
    int parcial;
    int nota;
};

struct Evaluaciones
{
    int val;
    Evaluaciones *next;
};

struct InfoEstudiante
{
    int id;
    Evaluaciones *evaluaciones[4];
};

struct Estudiante
{
    InfoEstudiante info;
    Estudiante *next;
};

struct InfoCurso
{
    int id, promocionados, regularizados, recursantes;
    Estudiante *estudiantes;
};

struct Curso
{
    InfoCurso info;
    Curso *next;
};

void ProcesarNovedades(FILE *, Curso *&);
void AgregarNota(Curso *&, int, int, int, int);
void CalcularEstadísiticas(Curso *&);

void ProcesarNovedades(FILE *f, Curso *&lista)
{
    Archivo arc;
    while (fread(&arc, sizeof(Archivo), 1, f))
    {
        if (arc.nota != 0)
            AgregarNota(lista, arc.curso, arc.idEstudiante, arc.parcial, arc.nota);
    }
    return;
}

void AgregarNota(Curso *&lista, int curso, int estudiante, int parcial, int nota)
{
    Estudiante *encontro2;
    Curso *encontro;
    encontro = buscar(lista, curso);
    if (encontro == NULL)
        return;
    else
        encontro2 = buscar2(encontro->info.estudiantes, estudiante);

    if (encontro2 == NULL)
        return;
    else
    {
        int i = 0;
        Evaluaciones *auxE = encontro2->info.evaluaciones[parcial - 1];
        while (auxE != NULL && i <= 3)
        {
            if (auxE->val == NULL)
            {
                auxE->val = nota;
            }
            pop(auxE);
            i++;
        }
    }
    return;
}

int getEstado(Evaluaciones *);

void CalcularEstadísiticas(Curso *&lista)
{
    Curso *aux = lista;
    while (aux != NULL)
    {
        Estudiante *auxE = lista->info.estudiantes;
        while (auxE != NULL)
        {
            int i = getEstado(lista->info.estudiantes->info.evaluaciones);

            if (i == 1)
                lista->info.promocionados++;
            else if (i == 2)
                lista->info.regularizados++;
            else if (i == 3)
                lista->info.recursantes++;
            pop(auxE);
        }
        pop2(aux);
    }
}