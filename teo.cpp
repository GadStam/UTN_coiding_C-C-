
#include<iostream>
using namespace std;
#include<stdlib.h>
#include<time.h>



void saludo (string nombre_usuario){
    cout << nombre_usuario;
}











string pregunta(string mensaje_preg){
    string respuesta;
    cout << mensaje_preg << endl;
    cin >> respuesta;
    return respuesta;
}

void hola(string mensaje){ // esta es mi funcion hola
cout << mensaje << endl;
}



int main() {
   string mensaje = "biensevido"; // defino mesnaje
   hola(mensaje); // llamo a la funcion hola y le paso mensaje





   string mensaje_preg = "decime tu nombre";
   string nombre;

   nombre = pregunta(mensaje_preg);
   cout << "hola como estas" << nombre;
    saludo(nombre);



   return 0;

}
