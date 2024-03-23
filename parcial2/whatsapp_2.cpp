#include <iostream>
#include <cstring>
using namespace std;

struct Info{
    int IdConversacion;
    char Nombre[30];
    bool Notificar;
    bool VistaPrevia;
};


struct Nodo{
    Info info;
    Nodo *sgte;
};

struct InfoContacto{
    int idUsuario;
    char NomContacto[30];
    bool bloqueado;
};

void NotificarMensajeRecibido(Nodo*&, InfoContacto[], int, int, int, Mensaje);
int BuscarContacto(InfoContacto[], int, int);
string NumeroTelefonicoUsuario(int);
string VistaPrevia(Mensaje);
void EmitirNotificación(string, string);



int BuscarContacto(InfoContacto vec[], int n, int IdContacto){
int i =0;
int pos = -1;
while(i < n){
if(vec[i].idUsuario == IdContacto){
    pos=i;
}
i++;
}
return pos;
}

Nodo* BuscarConversacion(Nodo* Lista, int idConversacion) {
 while (Lista != NULL && Lista->info.IdConversacion != idConversacion) {
 Lista = Lista->sgte;
 }
 return Lista;
}




void NotificarMensajeRecibido(Nodo*& Lista, InfoContacto vecContacto[], int tam, int idConversacion, int idUsuarioEmisor, Mensaje mensaje){

while(Lista != NULL){
    if(Lista->info.Notificar){
        
    }
}

}