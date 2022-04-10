#include <stdio.h>
#include <stdlib.h>
#include "grafo_listas.h"

arista crea_arista(int v, int w){
	arista A;
	A.v = v;
	A.w = w;
	return A;
}

enlace nuevo(int v, enlace siguiente)
{ 
	enlace x = malloc(sizeof *x);
	x->v = v; 
	x->siguiente = siguiente;
	return x;
}

Grafo inicia_grafo(int V){ 
	int v;
	Grafo G = malloc(sizeof *G);
	G->V = V; 
	G->A = 0;
	G->adj = malloc(V * sizeof(enlace));
    for (v = 0; v < V; v++) 
		G->adj[v] = NULL;
	return G;
}

void inserta_arista(Grafo G, arista a){ 
 	int v = a.v, w = a.w;
	G->adj[v] = nuevo(w, G->adj[v]);
	G->adj[w] = nuevo(v, G->adj[w]);
	G->A++;
}


int main()
{

	int V = 4, i;
	Grafo G1 = inicia_grafo(V);
	arista arista_1;
	arista_1 = crea_arista(0, 1);
	inserta_arista(G1, arista_1);
	arista_1 = crea_arista(0, 2);
	inserta_arista(G1, arista_1);

	// muestra las listas
	for (i = 0; i < V; i++){
		while(G1->adj[i] != NULL){
			printf("%i ", G1->adj[i]->v);
			G1->adj[i] = G1->adj[i]->siguiente;
		}
		printf("\n");
		}


	return 0;
}
