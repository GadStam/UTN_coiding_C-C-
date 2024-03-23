/*Codifique o diagrame una función ProcesarNovedades(nombreDeArchivo,
cursos) que lee de un archivo registros con el id del curso, el id del estudiante, el parcial (1, 2, 3, ó 4), y la nota,
y utiliza la función AgregarNota(insertarOrdenado) para registras las novedades en la lista cursos. Una nota cero equivale a un
ausente. 
ahora cargar toda la info de cada lista de estudiantes
*/

#include <iostream>
#include <cstring>
using namespace std;
struct infoArch{
    int idCurso;
    int idEstudiante;
    int nParcial;
    int notaParcial;
};

struct infoEvaluaciones{
    int nota;
    int recuperatorio;
};

struct Evaluaciones{
    infoEvaluaciones info;
    Evaluaciones* sgte;
};

struct Estudiantes{ // listasecundaria
    int idEstudiante;
    Estudiantes* sgte;

    Evaluaciones* Arraevaluaciones[4];

};

struct infoCursos{ //info lista primaria
    int idCurso;
    int promo;
    int regulares;
    int recu;
    Estudiantes* ptrEstu;

};

struct Cursos{ //lista primaria
infoCursos info;
Cursos *sgte;
};

Cursos* ProcesarNovedades(FILE*, Cursos*&);
void AgregarNota(Cursos*, int, int, int, double);
Cursos* InsertarOrdenado(Cursos*&, int);


Cursos* ProcesarNovedades(FILE* f, Cursos*& ListaCursos ){
infoArch reg;
Cursos* auxLista;
Estudiantes* auxListaEstu;
int idCursoAux;
while(fread(&reg, sizeof(infoArch), 1, f)){
idCursoAux = reg.idCurso;
auxLista = InsertarOrdenado(ListaCursos,idCursoAux);
auxListaEstu = InsertarSinRepetir(auxLista->sgte, reg.idEstudiante);

}
}