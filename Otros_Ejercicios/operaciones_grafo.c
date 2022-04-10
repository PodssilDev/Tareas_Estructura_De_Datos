#include <stdio.h>
#include <stdlib.h>
#include "grafo.h"

 
arista crea_arista(int v, int w){
	arista A;
	A.v = v;
	A.w = w;
	return A;
}
	
int **inicia_matriz(int r, int c, int valor){ 
	int i, j;
	int **t = malloc(r * sizeof(int*));
	for (i = 0; i < r; i++)
		t[i] = malloc(c * sizeof(int));
	for (i = 0; i < r; i++)
		for (j = 0; j < c; j++)
			t[i][j] = valor;
	return t;
}
	
Grafo inicia_grafo(int V){ 
	Grafo G = malloc(sizeof *G);
	G->V = V; 
	G->A = 0;
	G->adj = inicia_matriz(V, V, 0);
	return G;
}

void inserta_arista(Grafo G, arista a){ 
	int v = a.v, w = a.w;
	if (G->adj[v][w] == 0) 
		G->A++;
	G->adj[v][w] = 1;
	G->adj[w][v] = 1;
}

void remueve_arista(Grafo G, arista a){ 
	int v = a.v, w = a.w;
	if (G->adj[v][w] == 1) 
		G->A--;
	G->adj[v][w] = 0;
	G->adj[w][v] = 0;
}

int pertenece_arista(Grafo G, arista a){ 
	int v = a.v, w = a.w, pertenece;
	if (G->adj[v][w] == 1) 
		pertenece = 1;
	else
		pertenece = 0;
	return pertenece;
}


int obtener_aristas(arista a[], Grafo G){ 
	int v, w, A = 0;
	for (v = 0; v < G->V; v++)
		for (w = v+1; w < G->V; w++)
			if (G->adj[v][w] == 1)
				a[A++] = crea_arista(v, w);
	return A;
}


int obtener_grado(Grafo G, int n){
	int v, grado = 0;
	for (v = 0; v < G->V; v++)
		grado += G->adj[n][v];
	return grado;
}
	
int obtener_adyacentes(int a[], Grafo G, int n){
	int v, j =0;
	for (v = 0; v < G->V; v++)
		if (G->adj[n][v] == 1)
			a[j++] = v;
	return j;
}

int es_clique(int a[], Grafo G, int n){ 
	int v, w, clique = 1;
	for (v = 0; v < n - 1; v++)
		for (w = v + 1; w < n; w++)
			if (G->adj[a[v]][a[w]] != 1){
				clique = 0;
				break;
			}
	return clique;
}

int es_tour(int a[], Grafo G, int n){
	int v, tour = 1;
	for (v = 0; v < (n - 1); v++)
		if (G->adj[a[v]][a[v + 1]] == 0)
			tour = 0;
	if (G->adj[a[n - 1]][a[0]] == 0)
		tour = 0;
	return tour;
}

int es_cobertura(arista c[], Grafo G, int n){
	int i, j, agregar_v, agregar_w;
	int vertices[G->V], K = 0;
	for (i = 0; i < n; i++){
		agregar_v = 1, agregar_w = 1;
		for (j = 0; j < K; j++){
			if (c[i].v == vertices[j])
				agregar_v = 0;}
		for (j = 0; j < K; j++){
			if (c[i].w == vertices[j])
				agregar_w = 0;}
					
		if (agregar_v == 1)
			vertices[K++] = c[i].v;
		if (agregar_w == 1)
			vertices[K++] = c[i].w;
		}	
	if (K ==  G->V)
		return 1;
	else 
		return 0;
	}
			



 

int main()
{

	int V = 4;
	Grafo G1 = inicia_grafo(V);
	arista arista_1;

	arista_1 = crea_arista(0, 1);
	inserta_arista(G1, arista_1);
	arista_1 = crea_arista(0, 2);
	inserta_arista(G1, arista_1);
	arista_1 = crea_arista(1, 2);
	inserta_arista(G1, arista_1);
	arista_1 = crea_arista(2, 3);
	inserta_arista(G1, arista_1);
	arista_1 = crea_arista(1, 3);
	inserta_arista(G1, arista_1);


	// Es clique
	int clique[] = {0, 1, 2};
	int C = es_clique(clique, G1, 3);		
	printf("Es clique %i \n", C);

	// Es tour
	int tour[] = {0, 1, 3, 2};
	int T = es_tour(tour, G1, 4);		
	printf("Es tour %i \n", T); 

	// Es cobertura
	arista cobertura[2];
	cobertura[0] = crea_arista(0, 1);
	cobertura[1] = crea_arista(2, 3);
	int B = es_cobertura(cobertura, G1, 2);
	printf("Es cobertura %i \n", B); 
	
	return 0;
}
