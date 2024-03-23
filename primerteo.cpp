#include <iostream>
using namespace std;

void saludo(string bienvenida){
cout << bienvenida << endl;
}

string peticion(string pregunta){
    string nombre_usuario;
    cout << pregunta << endl;
    cin >> nombre_usuario;
    return nombre_usuario;
}

void muestra (string nombre){
    cout << nombre << endl;
}

int main(){
string bienvenida = "hola bienvenido";
string pregunta = "decime tu nombre";

string nombre;

saludo(bienvenida);

nombre = peticion(pregunta);

muestra(nombre);

return 0;
}