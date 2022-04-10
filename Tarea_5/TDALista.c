/*TAREA TDA LISTA
ESTRUCTURA DE DATOS
*/
#include <stdio.h>
#include <stdlib.h>
struct info {
	int dato;  
};
typedef struct info Info;

struct nodo{
	Info *info;
	struct nodo *sig;
};
typedef struct nodo Nodo;

struct lista{
	Nodo *head;
};
typedef struct lista Lista;


// Crear una lista
Lista * crear_lista(){
	Lista *lista;
	lista = (Lista *) malloc(sizeof(Lista));
	lista->head = NULL;
	return lista;
}

//Insertar un Nodo al inicio de la lista
void insertarNodoInicio(Lista *L, int pval){
	Info *inf_nuevo;
	inf_nuevo= (Info *) malloc(sizeof(Info));
	inf_nuevo->dato = pval;
	Nodo *nodo_nuevo;
	nodo_nuevo = (Nodo *) malloc(sizeof(Nodo));
	nodo_nuevo->info = inf_nuevo;  
	nodo_nuevo->sig = NULL;
	if (L->head == NULL){
		L->head = nodo_nuevo;
	}else{	
		nodo_nuevo->sig = L->head;
		L->head = nodo_nuevo;
	}
}
//Recorrer la lista hasta el final
void recorrer_lista(Lista *L){
    int cont;
    Nodo *aux;
    aux = L->head;
    while (aux != NULL){
        cont = 0;
        cont = aux->info->dato;
        printf("\n%d", cont);
        aux = aux->sig;
    }
}
//Eliminar un elemento de la lista (Que no esta en el inicio)
void eliminar_elemento(Lista *L, int valor){
	Nodo *aux;
	Nodo *aux2;
	Nodo *aux3;
	aux = L->head;
	while (aux != NULL){
		aux3 = aux->sig;
		if (aux3 != NULL && aux3->info-> dato == valor){
			aux2 = aux->sig;
			aux->sig = aux2->sig;
			aux2-> sig = NULL;
			free(aux2);
			break;
        }
        aux = aux->sig;
    }
}

//Insertar al final de la lista 
void insertar_final(Lista *L, int elemento){
	Info *info;
	Nodo *nodo_nuevo;
	Nodo *aux;
	aux = L->head;
	//crear info 
	info = (Info *) malloc(sizeof(Info));
	info->dato = elemento;
	// Crear el nodo y asignar
	nodo_nuevo = (Nodo *) malloc(sizeof(Nodo));
	nodo_nuevo->info = info; 
	nodo_nuevo->sig = NULL;
	while(aux->sig != NULL)
		aux = aux->sig;
	aux->sig = nodo_nuevo;
}

//Eliminar al inicio de la lista
void eliminar_inicio(Lista *L){
	if (L->head != NULL){
		Nodo *aux;
		aux = L->head;
		L->head = aux->sig;
		aux->sig = NULL;
		free(aux);
	}
}
//Eliminar elementos repetidos de una lista 
void eliminar_repetidos(Lista *L){
    int cont;
    int valor;
    Nodo *aux;
    Nodo *aux2;
    aux = L-> head;
    while (aux != NULL){
        cont = 0;
        valor = aux->info->dato;
        aux2 = L->head;
        while (aux2!= NULL){
            if (aux2->info->dato == valor){
                cont = cont + 1;
            }
            aux2 = aux2->sig;
        }
        if (cont >=2){
          eliminar_elemento(L,valor);
          cont = cont -1;
          aux = L->head;
        }
        else{
          aux = aux->sig;
        }
    }
}
//Unir dos listas
void union_lista(Lista *L, Lista *L2){
    Nodo *aux;
	Nodo *aux2;
    aux = L->head;
	aux2 = L2->head;
	while (aux->sig != NULL){
		aux = aux->sig;
	}
	aux-> sig =L2->head;
	L2-> head = NULL;
}

int main(){
    Lista *lis;
    lis = crear_lista();
    printf("Lista creada");
}

