#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;


struct alumno{
    int curso;
    int legajo;
    char nombre[50];
};


void burbuja(alumno, int);


int main() {
   int N = 7;
   alumno vector[] = {1, 2, 4, 56, 77, 5444, 323};

   burbuja(vector, N);
   cout << "Vector ordenado: ";
   for (int i = 0; i < N; i++) {
        cout << vector[i] << " " << endl ;
   }
   

  
   

   return 0;
}

void burbuja(alumno vector[],int N)
{
	int i,j;
	alumno aux;
	for(i=1;i<N;i++) //pasos
	{
		for(j=1;j<=N-i;j++) //comparaciones
		{
			if(vector[j-1].curso>vector[j].curso ||
			 (vector[j-1].curso==vector[j].curso &&
			 vector[j-1].legajo>vector[j].legajo) || (strcmp(vector[j-1].nombre,vector[j].nombre)==1) )
			{
				//intercambio
				aux=vector[j-1];
				vector[j-1] = vector[j];
				vector[j]=aux;
			}
		}
	}
}
