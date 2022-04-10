#include <stdio.h>
#include <stdlib.h>
/*ESTRUCTURA DE DATOS DE LA PILA*/
struct nodo{
	int info;
	struct nodo *sig;
};
typedef struct nodo Nodo;

struct pila{
	Nodo *top;
};
typedef struct pila Pila;



/*DEFINICIÓN DE LAS OPERACIONES*/

Pila *crearPila(){
	Pila  *pila;
	pila = (Pila*) malloc(sizeof(Pila));
	pila->top = NULL;
	return pila;
}


int isEmpty(Pila *p){
	if(p->top == NULL)
		return 1;
	else
		return 0;
}

void push(Pila *p, int pval){
	Nodo *nuevo_nodo;
	nuevo_nodo = (Nodo*) malloc(sizeof(Nodo));
	nuevo_nodo->info = pval;
	nuevo_nodo->sig= NULL;

	if (!(isEmpty(p)))
		nuevo_nodo->sig = p->top;
	p->top= nuevo_nodo;
}

int tope(Pila *p){ //retorno el valor que contiene el tope
	return p->top->info;
}

int pop(Pila *p){ //retorno el valor del elemento eliminado
	int x;
	if (!isEmpty(p)){
		Nodo *aux;
		aux = p->top;
		x = tope(p);
		p->top = aux->sig;
		aux->sig = NULL;
		free(aux);
	}else{
		printf("\nPila Vacía");
	}
	return x;
}



/* COMPLETAR LAS OPERACIONES QUE FALTAN EN EL TDA y probarlas */
int main(){
	Pila *A;
	A = crearPila();
	push(A,2);
	push(A,5);
	push(A,8);
	printf("\nTope de la pila: %d", tope(A));
	printf("\nElemento desapilado: %d", pop(A));
	printf("\nTope de la pila: %d", tope(A));
	return 0;
}