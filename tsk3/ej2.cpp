/*2.	Se dispone de un conjunto de boletas de inscripción de alumnos a examen en el
mes de mayo.
Cada boleta tiene los siguientes datos: nombre y apellido, número de legajo, código
de materia, día, mes y año del examen. Los datos finalizan con un nombre y apellido =”x”.
Desarrollar un programa que a partir del ingreso de las boletas mencionadas, por
teclado, genere un archivo binario de inscripción de alumnos a exámenes finales
DIAFINALES.DAT, según el siguiente diseño:
a. Nro. de legajo (8 dígitos
)
b. Código de materia (6 dígitos)
c. Día del examen (1..31)
d. Mes del examen (1..12)
e. Año del examen (4 dígitos)
f. Nombre-Apellido (25caract)
3.	Dado el archivo binario generado en el ejercicio anterior, desarrolle un programa
que solicitando por teclado un código de materia permita seleccionar todos los registros que se anotaron para rendirla y los grabe en otro archivo (MATFINALES.DAT), con el mismo
diseño.*/



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

int main(){
    FILE* f=fopen("DIAFINALES.DAT","wb");
	//wb wb+ rb rb+
	alumno al;
    
    
    cout << "Ingrese un nombre:";
	cin >> al.nombre;
    cout << "Ingrese un apellido:";
	cin >> al.apellido;
	
	while(strcmp(al.nombre, "x") != 0 && strcmp(al.apellido, "x") != 0)
	{
		cout << "Ingrese legao" << endl;
		cin >> al.nlegajo;
		cout << "Ingrese codigo:" << endl;
		cin >> al.codigo_materia;
		cout << "Ingrese dia:" << endl;
		cin >> al.dia;
        cout << "Ingrese mes:" << endl;
		cin >> al.mes;
        cout << "Ingrese año:" << endl;
		cin >> al.ano;
        
		
		fwrite(&al,sizeof(alumno),1,f);

        cout << "Ingrese un nombre (x para terminar): ";
        cin >> al.nombre;
        cout << "Ingrese un apellido (x para terminar): ";
        cin >> al.apellido;
    }
    
    fclose(f);
    return 0;
}



