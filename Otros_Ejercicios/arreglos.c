#include<stdio.h>

int main()
{
	int cantidad;
	printf("Ingrese el tamaño del arreglo: \n");
	scanf("%d", &cantidad);
	int arreglo[cantidad];
    // se asignan valores al arreglo
	for(int i = 0; i < cantidad; i++){
		printf("Ingrese el valor a almacenar: \n");
		scanf("%d", &arreglo[i]);

	}	

    // se muestran por pantalla los valores
	for(int i = 0; i < cantidad; i++){
		printf("El valor en la posicion %d es %d\n", i, arreglo[i]);

	}	
	return 0;
}


