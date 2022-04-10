#include <stdio.h>
int main(){

	FILE *fp;
	char nombreAchivo[200], linea[200], caracter;
	
	printf("Nombre archivo a leer:\n");
	scanf("%s",nombreAchivo);

	fp = fopen(nombreAchivo,"r");
	if(fp == NULL){
		printf("Error al abrir archivo %s\n",nombreAchivo);
	}else{
		caracter = getc(fp);
		while(caracter != EOF){
			printf("%c", caracter);
			caracter = getc(fp);
		}
		fclose(fp);
	}
	return 0;
}	