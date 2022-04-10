/*
ESTRUCTURA DE DATOS
Tarea Funciones y Punteros

Construya un programa que implemente las siguientes funciones:
• Suma de elementos de un arreglo A de enteros
• Lectura de un archivo con números y que lo almacene en un arreglo (el primer valor del archivo corresponde a la cantidad de elementos a leer)
• Comparar dos arreglos de enteros
• Producto punto de enteros
*/

#include<stdio.h>
int suma_elementos(void){
    int cantidad, suma, i;
	printf("Ingrese la cantidad de elementos: \n");
	scanf("%d", &cantidad);
	int arreglo[cantidad];
	i = 0;
	while (i < cantidad){
		printf("Ingrese el elemnto %i del arreglo: \n", i + 1);
		scanf("%i", &arreglo[i]);
		i = i + 1;
	}
	suma = 0;
	i = 0;
	while (i < cantidad){
		suma = suma + arreglo[i];	
		i = i + 1;
	}
	return suma;
}


void lee_archivo(char nombre[]){
	int elementos, i;
	FILE * fp;
	fp = fopen ("file.txt", "r");
	fscanf(fp, "%d", &elementos);
	int numeros[elementos];
	i = 0;
	while(i < elementos){
		fscanf(fp, "%i", &numeros[i]);
		++i;			
	}
	fclose(fp);
	printf("Los valores leidos desde el archivo son:\n");
	i = 0;
	while(i < elementos){
		printf("%d \n", numeros[i]);
		++i;
	}
}	
	
	
int compara_arreglos(void){
    int cantidad, i, todos_iguales;
	printf("Ingrese la cantidad de elementos de los arreglos: \n");
	scanf("%d", &cantidad);
	int arreglo_a[cantidad];
	int arreglo_b[cantidad];
	i = 0;
	while (i < cantidad){
		printf("Ingrese el elemnto %i del arreglo A: \n", i + 1);
		scanf("%i", &arreglo_a[i]);
		++i;
	}
	
	i = 0;
	while (i < cantidad){
		printf("Ingrese el elemnto %i del arreglo B: \n", i + 1);
		scanf("%i", &arreglo_b[i]);
		++i;
	}
	todos_iguales = 1;
	i = 0;
	while ((i < cantidad) && (todos_iguales)){
		if (arreglo_a[i] != arreglo_b[i])
			todos_iguales = 0;
		++i;
	}
	return todos_iguales;
}	

	
int calcula_producto_punto(void){
    int cantidad, i, suma;
	printf("Ingrese la cantidad de elementos de los arreglos: \n");
	scanf("%d", &cantidad);
	int arreglo_a[cantidad];
	int arreglo_b[cantidad];
	i = 0;
	while (i < cantidad){
		printf("Ingrese el elemnto %i del arreglo A: \n", i + 1);
		scanf("%i", &arreglo_a[i]);
		++i;
	}
	i = 0;
	while (i < cantidad){
		printf("Ingrese el elemnto %i del arreglo B: \n", i + 1);
		scanf("%i", &arreglo_b[i]);
		++i;
	}
	suma = 0;
	i = 0;
	while(i < cantidad){
		suma = suma + arreglo_a[i] * arreglo_b[i];
		++i;
	}
	return suma;
}


int main(){
int opcion, resultado;
char nombre[200];
do{
	printf("Seleccione una de las siguientes opciones:\n");
	printf("1. Sumar elementos de un arreglo\n");
	printf("2. Lectura de un archivo con numeros\n");
	printf("3. Comparar dos arreglos de enteros\n");
	printf("4. Producto punto de dos arreglos de enteros\n");
	printf("5. Salir\n");
	scanf("%d",&opcion);
	switch (opcion)
	{
		case 1: 	
			resultado = suma_elementos();
			printf("La suma de los elementos del arreglo es: %i \n", resultado);
			break;
		case 2:
			printf("Ingrese el nombre del archivo a leer\n");
			printf("Nombre archivo a leer:\n");
			scanf("%s", nombre);
			lee_archivo(nombre);
			break;
		case 3:  
			resultado = compara_arreglos();
			if (resultado)
				printf("Los arreglos son iguales\n");
			else
				printf("Los arreglos son diferentes\n");
			break;
		case 4:  
			resultado = calcula_producto_punto();
			printf("El producto punto de los arreglos es: %i\n", resultado);
			break;		
		case 5:  
			printf("Programa terminado\n");
			break;
		default:
			printf("Selecion incorrecta, intentelo nuevamente\n");
			break;
} 
} while (opcion != 5);
return 0;
}
