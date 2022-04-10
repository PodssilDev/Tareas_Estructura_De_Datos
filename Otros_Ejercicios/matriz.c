#include<stdio.h>
#include<stdlib.h>
// Función que encuentra el mayor elemento de una matriz
int mayor(int **arreglo, int filas, int columnas){
	int mayor = arreglo[0][0];
	for(int i = 0; i < filas; ++i){
		for(int j = 0; j < columnas; ++j){
			if(mayor < arreglo[i][j])
				mayor = arreglo[i][j];
		}
	}
	return mayor;
}

 
int main()
{
	int filas, columnas;
	printf("Ingrese el numero de filas:");
	scanf("%d",&filas);
	printf("Ingrese el numero de columnas:");
	scanf("%d",&columnas);
	// Se crea la matriz
	int **a = (int **) malloc(sizeof(int *) * filas);
	// Se asigana memoria para las columnas de la matriz
	for(int i = 0; i < filas; ++i){
		a[i] = (int*) malloc(sizeof(int) * columnas);
	}	

	for(int i = 0; i < filas; ++i){
		for(int j = 0; j < columnas; ++j){
			printf("Ingrese un valor a almacenar en (%d, %d):", i, j);
			scanf("%d", &a[i][j]);
		}	
	}

    int m = mayor(a, filas, columnas);
    printf("El numero mayor es: %d \n:", m);
    int aux;
	printf("\n Ingrese un numero para finalizar \n:");
	scanf("%d", &aux);
    
    // Se libera memoria de las filas
	for(int i = 0; i < filas; ++i){
		free(a[i]);
	}
	// Se libera memoria de la matriz
	free(a);

	return 0;
}

