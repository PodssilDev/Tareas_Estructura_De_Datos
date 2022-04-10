/*
ESTRUCTURA DE DATOS
Tarea Funciones y Punteros

Implementar un programa en C que calcule el valor de la serie de Fibonacci de un número x:
De forma iterativas y recursiva. 
*/
#include <stdio.h>
#include <time.h>

// Función recursiva
// Entrada: El numero n a calcular el valor
// Salida: El valor del fibonacci 
int fibonacci_recursivo(int n){
    if((n == 0) || (n == 1)){
        return n;
    }
	else{
		return (fibonacci_recursivo(n - 1) + fibonacci_recursivo(n - 2));
	}
}

// Función iterativa 
// Entrada: El numero n a calcular el valor
// Salida: El valor del fibonacci 
int fibonacci_iterativo(int n){
    int i, siguiente = 1, actual = 0, temp = 0;
    if(n == 0){
		return actual;
	}
	for (i = 2; i <= n; i++){
        temp = actual;
        actual = siguiente;
        siguiente = siguiente + temp;
    }
    return siguiente;
}

int main(){
    int numero_serie, termino;
	time_t inicio, fin, tiempo;
	printf("Ingrese el elemento de la serie que quiere conocer: ");
    scanf("%d", &numero_serie);
    time(&inicio);
	termino = fibonacci_iterativo(numero_serie);
    time(&fin);
    tiempo = fin - inicio;
	printf("Termino %d \n", termino);
	printf("Tiempo iterativo: %ld segundos\n", tiempo);
    time(&inicio);
	termino = fibonacci_recursivo(numero_serie);
    time(&fin);
    tiempo = fin - inicio;
	printf("Tiempo recursivo: %ld segundos\n", tiempo);
	return 0;
}
