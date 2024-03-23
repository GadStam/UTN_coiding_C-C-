struct infoLS{
	int idvendedor;
	int cantidadVend;
};
struct nodoLS{
	infoLS  info;
	nodoLS* sgte;
};

struct infoLP{
	int mes;
	nodoLS* ptrls;
};

struct nodoLP{
    infoLP info;
   nodoLP* sgte;    
};

int main()
{
    FILE* f= fopen(....);
    nodoLP listaLP=NULL;
    archivo auxArch;
    
    while(fread(.....))
	{
    	infoLP lp;
    	lp.mes = auxArch.mes;
    	lp.ptrls = NULL;
    	nodoLP* NodoLP = insertarSinRepetir(listaLP,lp);	
    	infoLS ils;
    	ils.cantidadVend = auxArch.cantidadVend;
    	ils.idvendedor = auxArch.idvendedor;
    	insertarOrdenado(NodoLP->info.ptrls,ils);
	}	
}