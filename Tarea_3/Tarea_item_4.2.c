/* 
ESTRUCTURA DE DATOS
Tarea Pseudocodigo y Lenguaje C Item IV

Crear un programa que lea un archivo de entrada con números (uno por cada línea) y e
scriba un archivo de salida con la suma de estos números 
*/
#include <stdio.h>
int main(){
	char nombre[200];
    int numeros[10];
    int i, suma;
	suma  = 0;
	FILE *fp, *fp_2;
	//lee el archivo
	printf("Ingrese el nombre del archivo: ");
	scanf("%s",nombre);
    fp = fopen(nombre,"r");
	if(fp == NULL){
      printf("Error al abrir archivo");
      return 0;
   }
    for (i = 0; i < 10; i++)
    {
        fscanf(fp, "%d", &numeros[i]);
		suma = suma + numeros[i];
    }
	fclose(fp);
    
	// muestra el resutado de la suma
	printf("La suma total es: %d\n\n", suma);
	
	// escribe el resutado en un archivo
	fp_2 = fopen("resultado.txt", "w");
	fprintf(fp_2, "%d", suma);
	fclose(fp_2);
	return 0;
}