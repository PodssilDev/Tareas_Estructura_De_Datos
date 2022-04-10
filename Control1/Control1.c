/*CONTROL 1
ESTRUCTURA DE DATOS
*/

//Se incluyen las librerias para poder trabajar con las funciones nativas del compilador
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// Se declara el arreglo dinamico de estructuras
struct partido *partidos;
struct partido
{
	char juego[10];
	int dia;
	int mes;
	int hora;
	char lugar[10];
};

// Se declara la primera funcion, la cual es para la opcion 1
void primera_opcion(struct partido *part, int cant_partidos){
	//Se declaran las variables de la funcion
	int dia, mes;
	int contador = 0;
	//Se solicita dia y mes del partido
	printf("Ingrese el dia del partido: ");
	scanf("%d", &dia);
	printf("Ingrese el mes del partido(numero): ");
	scanf("%d", &mes);
	for (int i = 0; i < cant_partidos; i++){
		if (dia == part[i].dia){
			if (mes == part[i].mes){
				printf("%s a las %d en %s\n", part[i].juego, part[i].hora, part[i].lugar);
				contador = contador + 1;
			}
		}
	}
	printf("Hay %d partidos para el %d del %d.\n", contador, dia, mes);
}

// Se declara la segunda funcion, que es para la opcion 2
//Nota: Se que aqui falta un caso, pero lamentablemente ya no me queda tiempo
void segunda_opcion(struct partido *part, int cant_partidos){
	char codigo[3];
	printf("Ingrese el codigo del pais: ");
	scanf("%s", codigo);
	int i = 0;
	int contador = 0;
	int cont2 = 0;
	for (int i = 0; i < cant_partidos; i++){
		contador = 0;
		if (codigo[0] == part[i].juego[0]){
			if (codigo[1] == part[i].juego[1]){
				if (codigo[2] == part[i].juego[2]){
					contador = 3;
				}
			}
		}
		else if (codigo[0] == part[i].juego[3]){
			if (codigo[1] == part[i].juego[4]){
				if (codigo[2] == part[i].juego[5]){
					contador = 3;
				}
			}
		}
		if (contador == 3){
			printf("%s: %d del %d a las %d en %s\n", part[i].juego, part[i].dia, part[i].mes, part[i].hora, part[i].lugar);
			cont2 = cont2 + 1;
		}
	}
	printf("Hay %d partidos para %s.\n", cont2, codigo);
}

//Se declara la tercera funcion para la opcion 3
void tercera_opcion(struct partido *part, int cant_partidos){
	char lugar_partido[3];
	int i = 0;
	int j = 0;
	int contador = 0;
	int cont2 = 0;
	printf("Ingrese el lugar del encuentro: ");
	scanf("%s", lugar_partido);
	for (int i = 0; i < cant_partidos; i++){
		for (j = 0; j < 3; j++){
			if (lugar_partido[j]!= part[i].lugar[j]){
				contador = 2;
			}
		}
		if (contador != 2){
			printf("%s: %d del %d a las %d\n", part[i].juego, part[i].dia, part[i].mes, part[i].hora);
			cont2 = cont2 + 1;
		}
		contador = 0;
		
	}
	printf("Hay %d partidos programados en %s.\n",cont2, lugar_partido);
}

//Main recibe dos parametros para poder colocar el nombre del archivo a traves de la consola
int main(int argc, char *argv[]){
	//Se declara un arreglo
	char nombre_arch[30];
	//Se declaran variables
	int opcion;
	int cant_partidos, i;
	// Copiamos el contenido de argv[] nombre_arch
	strcpy(nombre_arch,argv[1]);
	// Declaramos el puntero *pt_arch para poder abrir el archivo
	FILE *pt_arch;
	pt_arch = fopen(nombre_arch, "r");
	//Se comprueba si el archivo fue correctamente abierto
	if (pt_arch == NULL){
		printf("ERROR: El archivo no fue abierto correctamente o no fue encontrado\n");
		printf("Intentelo denuevo\n");
		return 0;
	}
	// Se recibe la cantidad de datos que se deben reservar en memoria, que corresponde al primer dato del archivo
	fscanf(pt_arch, "%d", &cant_partidos);
	//Declaramos el arreglo con memoria dinamica
	partidos = (struct partido*)malloc(sizeof(struct partido) * cant_partidos);
	// Llenamos las estructuras con los contenidos del archivo
	// Los arreglos no llevan amperson debido a que son conjuntos de memoria
	for (i = 0; i < cant_partidos; i++){
		fscanf(pt_arch, "%s" ,partidos[i].juego);
		fscanf(pt_arch, "%d", &partidos[i].dia);
		fscanf(pt_arch, "%d", &partidos[i].mes);
		fscanf(pt_arch, "%d", &partidos[i].hora);
		fscanf(pt_arch, "%s", partidos[i].lugar);
	}  
	// Se imprime el menu junto con sus opciones
	printf("Menu:\n");
	printf("1) Partidos por fecha\n");
	printf("2) Partidos por pais\n");
	printf("3) Partidos por lugar\n");
	printf("4) Salir\n");
	printf("\n");
	printf("Ingrese una opcion: ");
	// Se solicita la opcion a ejecutar
	scanf("%d",&opcion);
	printf("\n");
	// Si la opcion no corresponde, se le solicitara al usuario ingresarla nuevamente
	while (opcion >= 5 || opcion <= 0){
		printf("Ingreso una opcion equivocada. Porfavor intentelo denuevo\n");
		printf("Ingrese una opcion: ");
		scanf("%d",&opcion);
		printf("\n");
	}
	// Si el usuario elige la primera opcion
	if (opcion == 1){
		//Se llamara a la funcion primera_opcion, que imprimira lo que corresponde a la opcion 1
		primera_opcion(partidos, cant_partidos);
		//Se libera la memoria del arreglo dinamico
		free(partidos);
		// Se cierra el archivo
		int fclose(FILE *pt_arch);
		// Se acaba el programa
		return 0;
		
	}
	//Si el usuario escoge la segunda opcion
	else if (opcion == 2){
		//Se llamara a la funcion segunda_opcion, que imprimira lo que corresponde a la opcion 2
		segunda_opcion(partidos, cant_partidos);
		//Se libera la memoria del arreglo dinamico
		free(partidos);
		//Se cierra el archivo
		int fclose(FILE *pt_arch);
		//Se acaba el programa
		return 0;
	}
	//Si el usuario escoge la tercera opcion
	else if (opcion == 3){
		//Se llamara a la funcion tercera_opcion, que imrpimira lo que corresponde a la funcion 3
		tercera_opcion(partidos, cant_partidos);
		//Se libera la memoria del arreglo dinamico
		free(partidos);
		//Se cierra el archivo
		int fclose(FILE *pt_arch);
		//Se acaba el programa
		return 0;
	}
	//Si el usuario escoge salir
	else if (opcion == 4){
		//Se libera la memoria del arreglo dinamico
		free(partidos);
		//Se cierra el archivo
		int fclose(FILE *pt_arch);
		//Se acaba el programa 
		return 0;
	}
}
