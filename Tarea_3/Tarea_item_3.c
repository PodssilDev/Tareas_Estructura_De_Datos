/* 
ESTRUCTURA DE DATOS
Tarea Pseudocodigo y Lenguaje C Item III

Recibir dos valores a y b, y muestre por pantalla: a^b y a/b con 4 decimales de precision 
El valor de la serie de Fibonacci para el menor de los elementos 
Crear un arreglo A de enteros de largo 20, leer sus valores desde la entrada por teclado y mostrar por pantalla: 
a) Cantidad de elementos mayores que un cierto valor X (a pedir por teclado) 
b) Promedio de los elementos en el arreglo A 
c) Usar la instrucción switch sobre los datos para indicar si un elemento es par o impar
*/
#include <stdio.h>
#include <math.h>
int main(){
	int opcion, conta2; 
	printf("1) Recibir dos valores a y b, y mostrar por pantalla..\n");
	printf("2) Crear un arreglo A de enteros de largo 20, leer sus valores...\n");
	printf("Ingrese opcion 1 o 2: ");
	scanf("%d", &opcion);
	if (opcion == 1){
		float a, b, cont, division, fibonacci, n, potencia;
		printf("Ingrese el valor de a: ");
		scanf("%f",&a);
		printf("Ingrese el valor de b: ");
		scanf("%f",&b);
		if (a < b){
			n = a;
		}
		else{
			n = b;
		}
		cont = b;
		potencia = 0;
		division = a/b;
		conta2 = 0;
		fibonacci = ((pow(((1+sqrt(5))/2),n))- (pow(((1-sqrt(5))/2),n)))/ sqrt(5);
		while (cont > 1){
			if (conta2 == 0){
				potencia = potencia + (a * a);
				conta2 = conta2 + 1;
				cont = cont - 1.0;
			}
			else{
				potencia = potencia *a;
				cont = cont - 1.0;
			}
		}
		if (b == 1){
			printf("La potencia de a^b es; %.4f\n", a);
		}
		else{
			printf("La potencia de a^b es; %.4f\n", potencia);
		}
		printf("La division a/b es: %.4f\n", division);
		printf("El fibonnaci de %f es %.4f\n", n, fibonacci);
		return 0;
	}
	else if (opcion == 2){
		int A[20];
		int valor, i;
		float suma;
		printf("Ingrese el valor a comparar: ");
		scanf("%d", &valor);
		conta2 = 0;
		suma =0;
		for(i = 0; i < 20; i++){
			printf("Ingrese el %d elemento del arreglo: ", i);
			scanf("%d", &A[i]);
		}
		for (i = 0; i < 20; i++){
			if (A[i] > valor){
				conta2 = conta2 + 1;
			}
		}
		for (i = 0; i < 20; i++){
			suma = suma + A[i];
		}
		suma = suma / 20;
		printf("La cantidad de elementos mayores que %d es %d\n", valor, conta2);
		printf("El promedio de los elementos del arreglo es %f\n", suma);
		return 0;
	}
	else{
		return 0;
	}
}

