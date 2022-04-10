/*LUNES 26/04
Con este programa practicamos:
Funciones con pasada de parámetros por valor
Funciones con pasada de parámetros por referencia*/

#include <stdio.h>
/*Los arreglos se pasan por referencia y n se está pasando por valor*/
int sumarArreglo(int array[], int n){ 
	int suma = 0;
	int i;
	for (i=0; i<n; i++){
		suma = suma + array[i];
	}
	return suma;
}
int producto_punto(int A[], int B[], int n){
	int resultado = 0;
	int i;
	for(i=0; i<n; i++){
		resultado += A[i] * B[i];
	}
	return resultado;
}
int compara_arreglos(int A[], int B[], int n){
	int i;
	for(i=0; i<n; i++){
		if (A[i] != B[i]){  //cuando sea distinto return 0
			return 0;
		}
	}
	return 1; // si retorna un 1 son iguales
}
/*F1: Esta Función almacena el resultado de las funciones sumarArreglo,
	  productoPunto y compara en un arreglo creado en el main y pasado
	  por referencia .
      Nos damos cuenta que las actualizaciones realizadas al arreglo
	  resultado SE VEN reflejadas en el main*/
void realizarCalculos1(int resultado[], int A[], int B[], int n){
	resultado[0] = sumarArreglo(A, n);
	resultado[1] = producto_punto(A,B,n);
	resultado[2] = compara_arreglos(A,B,n);	
}


/*F2: Esta Función almacena el resultado de las funciones sumarArreglo,
      productoPunto y comparaArreglos en distintas variables (sum, prod y comp) 
	  pasadas por valor.
      Nos damos cuenta que las actualizaciones realizadas a estas variables
	  NO SE VEN reflejadas en el main*/
void realizarCalculos2(int A[], int B[], int n, int sum, int prod, int comp){
	sum = sumarArreglo(A, n);
	prod = producto_punto(A,B,n);
	comp = compara_arreglos(A,B,n);	
	printf("\nSuma elementos arreglo A\t: %d", sum);
	printf("\nProducto punto arreglos A y B\t: %d", prod);
	printf("\nComparación de arreglos A y B\t: %d", comp);
}

/*F3: Esta Función almacena el resultado de las funciones sumarArreglo,
      productoPunto y comparaArreglos en distintas variables (sum, prod y comp) 
	  pasadas por referencia.
      Nos damos cuenta que las actualizaciones realizadas a estas variables
	  SE VEN reflejadas en el main*/
void realizarCalculos3(int A[], int B[], int n, int *sum, int *prod, int *comp){
	*sum = sumarArreglo(A, n);
	*prod = producto_punto(A,B,n);
	*comp = compara_arreglos(A,B,n);	
}


int main() {
	int R[3];
	int A[] = {10,34,25,2,8};
	int B[] = {10,34,25,1,8};
	int largo = 5;
	printf("\nLOS ARREGLOS SE PASAN POR REFERENCIA - realizarCalculos1:");
	realizarCalculos1(R,A,B,largo); //F1:el arreglo R es pasado por referencia 
	printf("\nSuma elementos arreglo A\t: %d", R[0]);
	printf("\nProducto punto arreglos A y B\t: %d", R[1]);
	printf("\nComparación de arreglos A y B\t: %d", R[2]);
	
	
    /* Ahora usaremos variables distintas para almacenar cada resultado de las funciones*/
	printf("\n\nPASADA DE PARÁMETROS POR VALOR - realizarCalculos2:");
	int sum=-1, pro=-1, com=-1; //Inicializamos	
	realizarCalculos2(A,B,largo, sum, pro, com);//F2:parámetros sum, pro y com pasados por valor
	printf("\nDirección de memoria de sum\t: %p", &sum);
	printf("\nSuma elementos arreglo A\t: %d", sum);
	printf("\nProducto punto arreglos A y B\t: %d", pro);
	printf("\nComparación de arreglos A y B\t: %d", com);


	//PASADA DE PARÁMETROS POR REFERENCIA
	printf("\n\nPASADA DE PARÁMETROS POR REFERENCIA - realizarCalculos3:");
	realizarCalculos3(A,B,largo, &sum, &pro, &com); /*F3:parámetros sum, pro y com pasados por referencia
													     pasando sus direcciones de memoria */
	printf("\nDirección de memoria de sum\t: %p", &sum);
	printf("\nSuma elementos arreglo A\t: %d", sum);
	printf("\nProducto punto arreglos A y B\t: %d", pro);
	printf("\nComparación de arreglos A y B\t: %d", com);


	printf("\n\nPASADA DE PARÁMETROS POR REFERENCIA - realizarCalculos4:");
	int *suma, *produ, *compa;
	realizarCalculos3(A,B,largo, suma, produ, compa); /*F4:parámetros suma, produ y compa pasados por referencia
													      ya que se definieron como punteros */
	printf("\nEl puntero suma almacena \t: %p", suma);
	printf("\nSuma elementos arreglo A\t: %d", *suma);
	printf("\nProducto punto arreglos A y B\t: %d", *produ);
	printf("\nComparación de arreglos A y B\t: %d", *compa);

	return 0;
}