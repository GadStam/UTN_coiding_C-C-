#include <iostream>
#include <cstring>

using namespace std;

struct Mensaje {
    int IdConversacion;
    char Nombre[30];
    bool Notificar;
    bool VistaPrevia;
};

struct Nodo {
    Mensaje info;
    Nodo* sgte;

    Nodo(Mensaje mensaje) : info(mensaje), sgte(nullptr) {}
};

// Función para buscar un mensaje por su IdConversacion en una pila de mensajes
Mensaje* buscarMensajePorIdConversacion(Nodo* pilaMensajes, int idConversacion) {
    Nodo* p = pilaMensajes;

    while (p != nullptr) {
        if (p->info.IdConversacion == idConversacion) {
            return &(p->info); // Devolvemos un puntero al mensaje encontrado
        } else {
            p = p->sgte;
        }
    }

    return nullptr; // Mensaje no encontrado
}

// Función para agregar un nodo a la pila de mensajes
void pushNodo(Nodo*& pilaMensajes, Nodo* nodo) {
    nodo->sgte = pilaMensajes;
    pilaMensajes = nodo;
}

// Función para eliminar el nodo superior de la pila de mensajes
void popNodo(Nodo*& pilaMensajes) {
    if (pilaMensajes != nullptr) {
        Nodo* nodoAEliminar = pilaMensajes;
        pilaMensajes = pilaMensajes->sgte;
        delete nodoAEliminar;
    }
}

int main() {
    // Crear algunos mensajes de ejemplo
    Mensaje mensaje1 = {1, "Mensaje1", true, false};
    Mensaje mensaje2 = {2, "Mensaje2", false, true};
    Mensaje mensaje3 = {6, "Mensaje3", true, true};

    // Crear una pila de mensajes
    Nodo* pilaMensajes = nullptr;

    // Agregar los nodos a la pila utilizando la función pushNodo
    pushNodo(pilaMensajes, new Nodo{mensaje1});
    pushNodo(pilaMensajes, new Nodo{mensaje2});
    pushNodo(pilaMensajes, new Nodo{mensaje3});

    // Buscar un mensaje por su IdConversacion
    int idConversacionABuscar = 3;
    Mensaje* mensajeEncontrado = buscarMensajePorIdConversacion(pilaMensajes, idConversacionABuscar);

    if (mensajeEncontrado) {
        cout << "Mensaje encontrado en la conversación " << idConversacionABuscar << ": " << mensajeEncontrado->Nombre << endl;
    } else {
        cout << "Mensaje no encontrado en la conversación " << idConversacionABuscar << endl;
    }

    // Eliminar el nodo superior de la pila utilizando la función popNodo
    popNodo(pilaMensajes);

    // Liberar la memoria de los nodos restantes en la pila
    while (pilaMensajes != nullptr) {
        popNodo(pilaMensajes);
    }

    return 0;
}
