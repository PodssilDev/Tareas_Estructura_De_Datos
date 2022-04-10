/* 
ESTRUCTURA DE DATOS
Tarea Pseudocodigo y Lenguaje C Item IV

Crear un programa que compare dos archivos e indique el carácter donde ellos difieran (si es que difieren)
*/
// PARA ESTE EJERCICIO SE ASUME QUE AMBOS ARCHIVOS TIENEN EL MISMO LARGO Y QUE LOS ARCHIVOS PARTEN 
// DESDE LA POSICION 0
#include <stdio.h>
int main(){
    char nom_arch[200], caracter;
	char nom_arch2[200], caracter2;
	int posicion = 0;
	printf("Nombre archivo a leer:\n");
	scanf("%s",nom_arch);
	printf("Nombre archivo a leer:\n");
	scanf("%s",nom_arch2);
	FILE *fp_arch;
	FILE *fp_2;
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
	while((caracter = getc(fp_arch)) != EOF && (caracter2 = getc(fp_2)) != EOF){
		if (caracter != caracter2){
			break;
		}
		posicion = posicion + 1;
	}
	fclose(fp_arch);
	fclose(fp_2);
	printf("La posicion en la que los archivos difieren es la posicion %d", posicion);
	return 0;
}	