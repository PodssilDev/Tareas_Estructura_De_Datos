/* 
Escriba un programa en C que solicite un numero de dias por teclado y
los convierta a segundos, mostrando el resultado por pantalla 
*/

#include <stdio.h>
#define HORAS 24
#define SEGUNDOS 60
#define MINUTOS 60
int dias, segs;
int main(){
	printf("Ingrese la cantidad de dias a transformar a segundos: ");
	scanf("%d",&dias);
	segs = dias * HORAS * MINUTOS * SEGUNDOS;
	printf("%d dias en segundos es %d segundos ",dias,segs);
	return 0;
}