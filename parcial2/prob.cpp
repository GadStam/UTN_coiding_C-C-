struct NodoSubLista{
    int info;
    NodoSubLista* sgte;
};



struct infoLD{
        int Campo1;
        int Campo2;
        NodoSubLista* vec[4];

};

struct ListaResultado{
infoLD info;
ListaResultado *sgte;
} ;

void CargarLista (FILE* f, ListaPrinci*& lista) {
    InfoArch al;
    ListaPrinci* lista_aux = lista; 
    InfoListaSecu aux2; 

    // ARRANCO A LEER EL ARCHIVO
    while (fread(&al, sizeof(InfoArch), 1, f)) {
        
        // INSERTO SIN REPETIR EL ID DE SUCURSAL, Y ME GUARDO LA DIRECCION EN UN NODO AUX
        lista_aux = InsertarSinRepetir(lista, al.id_sucursal); // INSERTO SIN REPETIR LA SUCURSAL 

        // CREO EL AUX 2 PORQUE EL INSERTAR ORDENADO SOLO ACEPTA DOS PARAMETROS 
        aux2.id_vendedor = al.id_vendedor; 
        aux2.cantidad_vendida = al.cantidad_vendida;

        // CON LA DIRECCION DE MI ID DE SUCURSAL, CARGO EN MI VECTOR EL MES Y EL ID VENDEDOR CON SU CANT VENDIDA 
        InsertarOrdenado(lista_aux->info.Arreglo[al.mes - 1], aux2);
    }

}