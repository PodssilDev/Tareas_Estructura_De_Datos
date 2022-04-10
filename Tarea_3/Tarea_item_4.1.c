/* 
ESTRUCTURA DE DATOS
Tarea Pseudocodigo y Lenguaje C Item IV

Escribir un programa que lea un archivo y lo muestre por pantalla luego modificar el código anterior 
para que el programa cree una copia del archivo de entrada, llamado “copia.txt”. 
*/
#include <stdio.h>
int main(){
    char nom_arch[200], caracter;
	printf("Nombre archivo a leer:\n");
	scanf("%s",nom_arch);
	FILE *fp_arch;
	FILE *fp_2;
	fp_arch = fopen(nom_arch,"r");
	if(fp_arch== NULL){
		printf("Error al abrir archivo %s\n",nom_arch);
		return 0;
	}
	fp_2 = fopen("copia.txt","w");
	while((caracter = getc(fp_arch)) != EOF){
		putc(caracter, fp_2);
	}
	fclose(fp_arch);
	fclose(fp_2);
	return 0;
}	