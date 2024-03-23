#include <iostream>
#include <cstring>

using namespace std;


struct infoChat{
    int IdConversacion;
    char Nombre[30];
   bool Notificar; 
    bool VistaPrevia;
};

struct Nodo{
    infoChat info;
    Nodo* sgte;
};

struct infoVec{
    int idUsuario;
    char nombre[30];
    bool bloqueado;
};

void NotificarMensajeRecibido(Nodo*&, infoVec[], int, int, int, Mensaje);
string NumeroTelefonicoDelUsuario(int);
string VistaPreviaMensaje(Mensaje);

void NotificarMensajeRecibido(Nodo*& Lista, infoVec vec[], int N, int idConversacion, int idUsuarioEmisor, Mensaje mensaje){
N = 200;
Nodo* nodoAux = NULL;
int pos;

nodoAux = BuscarLista(Lista, idConversacion);
pos = BuscarContacto(vec, N, idUsuarioEmisor);

bool bloqueado;
string nombreContacto;

if(pos != -1){
    bloqueado = vec[pos].bloqueado;
    nombreContacto = vec[pos].nombre;
}else{
    bloqueado = false;
    nombreContacto = NumeroTelefonicoUsuario(idUsuarioEmisor);
}

if (bloqueado == false && nodoAux->info.Notificar == true) { // Notificar
 string titulo, descripcion;
 if (conversacion->info.nombre == “”) { // Si es conversación Directa
 titulo = nombreContacto; //para emitir en la notificación solo el nombre del emisosr
 if (conversacion->info.vistaPrevia) {//Si desea vista previa
 descripcion = VistaPrevia(mensaje);//la descripción para emitir notificación
 }
 else {
 descripcion = “Nuevo Mensaje.”;
 }
 }// fin de conversación directa
 else { // Conversacion Grupal
 titulo = conversacion->info.nombre; // debe mostrar nombre del grupo
 if (conversacion->info.vistaPrevia) {
 descripcion = nombreContacto + “: “ + VistaPrevia(mensaje);
 }
 else {
 descripcion = “Nuevo Mensaje de ” + nombreContacto;
 }
 }// fin conversación grupal
 EmitirNotificacion(titulo, descripcion);//si corresponde emite
 } // fin condicional de usuario que se debe notificar
 return; // fin de la funcion
}





}

 



int BuscarContacto(infoVec vec[], int N, int idUsuarioEmisor){
    int pos = -1;
    for(int i = 0; i < N; i++){
            if(vec[i].idUsuario == idUsuarioEmisor){
                    pos = i;
                }
            }
            return pos;
}

Nodo* BuscarLista(Nodo*& Lista, int idConversacion){
    while (Lista != NULL && Lista -> info.IdConversacion != idConversacion){
        Lista = Lista->sgte;
        }
        return Lista;
}


