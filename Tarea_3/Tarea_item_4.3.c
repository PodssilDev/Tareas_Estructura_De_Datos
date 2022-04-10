/* 
ESTRUCTURA DE DATOS
Tarea Pseudocodigo y Lenguaje C Item IV

Crear un programa que lea dos archivos y entregue otro con la concatenación 
*/
#include <stdio.h>
int main(){
    char nom_arch[200], caracter;
	char nom_arch2[200];
	printf("Nombre archivo a leer:\n");
	scanf("%s",nom_arch);
	printf("Nombre archivo a leer:\n");
	scanf("%s",nom_arch2);
	FILE *fp_arch;
	FILE *fp_2;
	FILE *fp_3;
	fp_arch = fopen(nom_arch,"r");
	if(fp_arch== NULL){
		printf("Error al abrir archivo %s\n",nom_arch);
		return 0;
	}
	fp_2 = fopen(nom_arch2,"r");
	if(fp_2== NULL){
		printf("Error al abrir archivo %s\n",nom_arch2);
		return 0;
	}
	fp_3 = fopen("resultado.txt","w");
	while((caracter = getc(fp_arch)) != EOF){
		putc(caracter, fp_3);
	}
	fp_3 = fopen("resultado.txt","a");
	while((caracter = getc(fp_2)) != EOF){
		putc(caracter, fp_3);
	}
	fclose(fp_arch);
	fclose(fp_2);
	fclose(fp_3);
	return 0;
}	