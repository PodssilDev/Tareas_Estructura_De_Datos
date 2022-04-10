/* 
TAREA 1
ESTRUCTURA DE DATOS

A pesar de que el enunciado no lo pedia, realice el menu para habilitar un facil acceso a todas las funciones,
de una forma similar a un ejercicio que se realizo durante una de las clases del profesor Mario Inostroza.
Para evitar cualquier confusion, comentare la gran mayoria de las lineas. Respecto a las entradas, se asume de que 
el archivo que contiene los datos del arreglo siempre tendra el mismo formato.

*/

// Se incluyen las librerias para poder trabajar con las funciones nativas del compilador
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Se crea un puntero
int *datos;

// Ordena_seleccion corresponde a la funcion del ordenamiento por seleccion
void ordena_seleccion(int *data, int cant_filas){
	// Se declaran las variables que se usara en la funcion
	int i, j, min, temp, num;
	// Para i hasta la cantidad de filas menos uno
	for (i = 0; i < (cant_filas - 1); i++){
		// Se declara a min como el valor de i 
		min = i;
		// Para j = i + 1 hasta la cantidad de filas
		for (j = i + 1; j < cant_filas; j++){
			// Si el elemento actual es menor que el menor
			if (data[j] < data[min])
				// Se asigna el nuevo elemento menor 
				min = j;
		}
		// Se realiza el intercambio de datos si es que i es distinto a min
		if (i != min){
			temp = data[i];
			data[i] = data[min];
			data[min] = temp;
			
		}
	}
	// Se da la opcion para poder imprimir todo el arreglo ordenado
	printf("Ingrese un 1 si desea imprimir el arreglo ordenado: ");
	scanf("%d", &num);
	if (num ==1){
		for (i = 0; i < cant_filas; i++){
			printf("%d\n", data[i]);
		}
	}
}

// Ordena_inseccion corresponde a la funcion del ordenamiento por insercion
void ordena_insercion(int *data, int cant_filas){
	// Se declaran las variables que se usaran en la funcion
	int i, j, temp, num;
	i = 0; 
	// Mientras i sea menor a la cantidad de filas
	while(i < cant_filas){
		// Se declara a temp como el valor actual del arreglo
		temp = data[i];
		// Se declara j como el valor de i menos uno
		j = i - 1;
		// Mientras j sea mayor a 0 y se cumpla que el valor de data[j] sea mayor al elemento de temp
		while (j >= 0 && data[j] > temp) {
			// Se asigna el elemento posterior al elemento actual
			data[j + 1] = data[j];
			// Se resta j en 1 para poder seguir iterando
			j = j - 1;
		}
		// Se guarda el elemento posterior en la variable temp
		data[j+1] = temp;
		// Se aumenta el contador para poder seguir iterando
		i++;
	}
	// Se da la opcion para imprimir todo el arreglo ordenado
	printf("Ingrese un 1 si desea imprimir el arreglo ordenado: ");
	scanf("%d", &num);
	if (num ==1){
		for (i = 0; i < cant_filas; i++){
			printf("%d\n", data[i]);
		}
	}
}

// Ordena_burbuja corresponde a la funcion del ordenamiento por el metodo de la burbuja
void ordena_burbuja(int *data, int cant_filas){
	// Se declaran las variables que se usaran en la funcion
	int i = 0;
	int j, temp, num;
	// Mientras i sea menor a la cantidad de filas menos uno
	while(i < cant_filas-1){
		//  Se declara j como 0
		j = 0;
		// Mientras j sea menor a la cantidad de filas menos uno
		while(j < cant_filas-1){
			// Si el elemento actual es mayor al elemento posterior
			if (data[j] > data[j+1]){
				// Se guarda en temp el elemento actual
				temp = data[j];
				// Se realiza el intercambio de datos
				data[j] = data[j+1];
				data[j+1] = temp;
			}
			// Se aumenta j en 1 para continuar iterando
			j = j+1;
		}
		// Se aumenta i en 1 para continuar iterando
		i = i + 1;
	}
	//  Se da la opcion de imprimir el arreglo ordenado
	printf("Ingrese un 1 si desea imprimir el arreglo ordenado: ");
	scanf("%d", &num);
	if (num ==1){
		for (i = 0; i < cant_filas; i++){
			printf("%d\n", data[i]);
		}
	}
}

// ordena_rapidosort corresponde a la funcion del metodo de Quicksort 
void ordena_rapidosort(int *data, int inicio,int cant_filas){
	// Se declaran las variables que se usaran en la funcion
	int i, j, pivote, temp, final;
	final = cant_filas;
	// Mientras inicio sea menor a final 
	if(inicio < final){
		// Se guarda en pivote el valor de inicio
		pivote = inicio;
		// Se guarda en i el valor de inicio
		i = inicio;
		// Se guarda en j el valor de final
		j = final;
		// Mientras i sea menor a j
		while(i < j){
			// Mientras el elemento actual sea menor o igual al elemento pivote y se cumpla tambien que i sea menor a final
			while(data[i] <= data[pivote] && i<final){
				// Se aumenta i, esto es para poder realizar el proceso de la particion
				i++;
			}
			// Mientras el elemento actual sea mayor al pivote
			while(data[j]> data[pivote]){
				// Se reduce j, esto es para poder realizar el proceso de la particion
				j--;
			}
			// Si i es menor que j
			if(i < j){
				// Se realiza el intercambio de posiciones
				temp = data[i];
				data[i] = data[j];
				data[j] = temp;
			}
		}
		// Se guarda en temp el elemento de la posicion pivote
		temp = data[pivote];
		// Se guarda en el elemento pivote el dato de la posicion j
		data[pivote] = data[j];
		// Se guarda en j el elemento de temp (Que era el elemento de la posicion pivote)
		data[j] = temp;
		// Se llama la funcion dos veces, para que se pueda realizar completamente el proceso de ordenamiento (Recursividad)
		ordena_rapidosort(data,inicio,j-1);
		ordena_rapidosort(data,j+1,final);
	}
}


// busqueda_binaria corresponde a la funcion para la Busqueda Binaria de un elemento en un arreglo ordenado
void busqueda_binaria(int *data, int cant_filas){
	// Se declaran las variables que se usaran en la funcion
	int i, max, min, pivote, numero;
	int cond = 0;
	// Se ingresa el numero a buscar
	printf("Ingrese el numero a buscar en el arreglo ordenado: ");
	scanf("%d",&numero);
	min = 0;
	max = cant_filas;
	// Mientras el menor sea menor (valga la redundancia) al maximo
	while (min <= max){
		// se guarda en pivote la posicion de al medio de las posiciones
		pivote = (min + max)/2;
		// Si el numero esta en la posicion pivote
		if (datos[pivote] == numero){
			// Cond se cambia a 1 y se rompe el ciclo
			cond = 1;
			break;
		}
		// Si el elemento esta en una posicion mayor al pivote
		if (datos[pivote] > numero){
			// Se declara al maximo como el pivote
			max = pivote;
			// Se calcula nuevamente la posicion de al medio
			pivote = (min + max)/2;
		}
		// Si el elemento esta en una posicion menor al pivote
		if (datos[pivote] < numero){
			// Se declara al minimo como el pivote
			min = pivote;
			// Se calcula nuevamente la posicion de al medio
			pivote = (min + max)/2;
		}
	}
	// Si cond es 1, entonces se encontro el elemento y se imprime la posicion del elemento
	if (cond == 1){
		printf("El numero %d se encuentra en la posicion %d del arreglo ordenado\n", numero, pivote);
	}
	// De lo contrario, el elemento no esta en el arreglo
	else{
		printf("El numero %d no se encuentra en el arreglo ordenado\n",numero);
	}
}

//Todas las funciones tienen la opcion para poder imprimir el arreglo ordenado si se desea.

// Main recibe dos parametros, los cuales permiten que se pueda ingresar el nombre del archivo de texto por consola
int main(int argc, char *argv[]){
	//Se declara un arreglo
	char nombre_arch[30];
	//Se declaran variables
	int opcion;
	int  i = 0;
	int cant_filas;
	// Copiamos el contenido de argv[] nombre_arch
	strcpy(nombre_arch,argv[1]);
	// Declaramos el puntero *pt_arch para poder abrir el archivo
	FILE *pt_arch;
	pt_arch = fopen(nombre_arch, "r");
	// Se comprueba si el archivo fue correctamente abierto
	if (pt_arch == NULL){
		printf("ERROR: El archivo no fue abierto correctamente o no fue encontrado\n");
		printf("Intentelo denuevo\n");
		return 0;
	}
	// Se recibe la cantidad de datos que se deben reservar en memoria, que corresponde al primer dato del archivo
	fscanf(pt_arch, "%d", &cant_filas);
	// Declaramos el arreglo con memoria dinamica
	datos = (int*)malloc(sizeof(int) * cant_filas);
	// Se llena el arreglo con los datos (numeros) del archivo
	while(i < cant_filas){
		fscanf(pt_arch, "%d", &datos[i]);
		i++;
	}
	// Se crea el menu para acceder a las distintas funciones del programa
	printf("Menu:\n");
	printf("1) Ordenamiento por Seleccion\n");
	printf("2) Ordenamiento por Insercion\n");
	printf("3) Ordenamiento por Burbuja\n");
	printf("4) Ordenamiento por Quicksort\n");
	printf("5) Busqueda Binaria\n");
	printf("6) Salir\n");
	printf("NOTA: Si el archivo es muy grande, puede que tenga que esperar un poco\n");
	printf("Ingrese una opcion: ");
	// Se solicita la opcion a ejecutar
	scanf("%d",&opcion);
	// Si se elige la opcion 1
	if (opcion == 1){
		// Se llama a la funcion de ordenamiento por seleccion
		ordena_seleccion(datos, cant_filas);
		// Se libera la memoria del arreglo dinamico
		free(datos);
		// Se cierra el archivo
		int fclose(FILE *pt_arch);
		return 0;
	}
	// Si se elige la opcion 2
	else if (opcion == 2){
		// Se llama a la funcion del metodo de insercion
		ordena_insercion(datos, cant_filas);
		// Se libera la memoria del arreglo dinamico
		free (datos);
		// Se cierra el archivo
		int fclose(FILE *pt_arch);
		return 0;
	}
	// Si se elige la opcion 3
	else if (opcion == 3){
		// Se llama a la funcion del metodo de la burbuja
		ordena_burbuja(datos, cant_filas);
		// Se libera la memoria del arreglo dinamico
		free (datos);
		// Se cierra el archivo
		int fclose(FILE *pt_arch);
		return 0;
	}
	// Si se elige la opcion 4
	else if (opcion == 4){
		// Se declaran dos variables que permitiran el funcionamiento del metodo de Quicksort
		int inicio = 0;
		int num = 0;
		// Se llama a la funcion del metodo de Quicksort
		ordena_rapidosort(datos,inicio, cant_filas);
		// Esta vez, la opcion de imprimir el arreglo ordenado se presenta fuera de la funcion para evitar problemas con la recursividad
		printf("Ingrese un 1 si desea imprimir el arreglo ordenado: ");
		scanf("%d", &num);
		if (num ==1){
			for (i = 0; i < cant_filas; i++){
				printf("%d\n", datos[i]);
			}
		}
		// Se libera la memoria del arreglo dinamico
		free(datos);
		// Se cierra el archivo 
		int fclose(FILE * pt_arch);
		return 0;
	}
	// Si se elige la opcion 5
	else if(opcion == 5){
		// Se ordena el arreglo utilizando el metodo de seleccion, llamando a la funcion ordena_seleccion
		ordena_seleccion(datos, cant_filas);
		// Se llama a la funcion de la busqueda binaria para encontrar la posicion de un elemento en el arreglo
		busqueda_binaria(datos, cant_filas);
		// Se libera la memoria del arreglo dinamico
		free (datos);
		// Se cierra el archivo
		int fclose(FILE *pt_arch);
		return 0;
	}
	//Si se elige la opcion 6
	else if (opcion == 6){
		// Se libera la memoria del arreglo dinamico
		free (datos);
		// Se cierra el archivo
		int fclose(FILE *pt_arch);
		return 0;
	}
	// Si el usuario decide ingresar cualquier otra opcion, el programa se acaba
	return 0;
}
