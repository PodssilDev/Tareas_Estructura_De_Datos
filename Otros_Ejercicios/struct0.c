#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#define NUM_NOTAS 3

//CLASE MIÉRCOLES 28-04: ESTRUCTURAS - ARREGLOS DINÁMICOS Y PUNTEROS
struct alumno {
	char nombre[31];
	float notas[NUM_NOTAS];
};
typedef struct alumno Alumno; //Alumno es un tipo de dato creado por mi que es de tipo struct alumno


//F1:
//ESTRUCTURAS - Agrego datos de UN alumno
Alumno ingresarDatosAlumno(){
	Alumno a;
	int i;
	printf("\nIngrese nombre del alumno:");
	scanf("%s", a.nombre);
	for (i=0; i<NUM_NOTAS; i++){ //cada i es una nota del alumno
		a.notas[i] = drand48()*6 + 1; //asigna valores float entre 1.0 y 7.0
	}
	return a;
}

//F2:
//ESTRUCTURAS - Agrego datos de VARIOS alumnoS-aquí asigno la memoria
Alumno *agregarAlumnos(int n){
	Alumno *newAlumno;
	int k;
	newAlumno = (Alumno*)malloc(sizeof(Alumno)*n); //memoria para los N alumnos
	for (k=0;k<n;k++){ //en cada posisión k del arreglo almaceno un alumno
		newAlumno[k] = ingresarDatosAlumno();
	}
	return newAlumno;  //retorno la dirección de memoria donde están los datos de alumno 
}


int main(){
	
	/**** ESTRUCTURAS ***/
	/*1) Trabajar con una estructura que almacena datos de un alumno*/
    Alumno alum;
	int i, k;
	alum = ingresarDatosAlumno();        
	
	printf("Nombre del alumno ingresado: %s", alum.nombre);
	for (i=0; i<NUM_NOTAS; i++){
		printf("\nNota %.2f", alum.notas[i]);
	}
	
	
	/*2) Trabajar con un arreglo dinámico de alumnos utilizando la función anterior
		 Aquí asigno lamemoria dinámica*/
    Alumno *alu;
	int n = 3;
	alu = (Alumno*)malloc(sizeof(Alumno)*n); //memoria para los N alumnos
	for (k=0;k<n;k++){
		alu[k] = ingresarDatosAlumno();
	}
	//Mostrar  los datos de cada alumno
	for (k=0;k<n;k++){
		printf("\nAlumno ingresado: %s", alu[k].nombre);
		for (i=0; i<NUM_NOTAS; i++){
			printf("\nNota %.2f", alu[k].notas[i]);
		}
	}


	/*3) Trabajar con un arreglo dinámico de alumnos  asignado la memoria en la función*/
	Alumno *alumno;
	alumno = agregarAlumnos(n);
	//Mostrar  los datos de cada alumno
	for (k=0;k<n;k++){
		printf("\nAlumno ingresado: %s", alumno[k].nombre);
		for (i=0; i<NUM_NOTAS; i++){
			printf("\nNota %.2f", alumno[k].notas[i]);
		}
	}
	return 0;
}



/*NÚMEROS ALEATORIOS*/
/*
numero = rand() % 11; 		==> El resto va  de 0 a 10 en este caso
numero = rand () % (N-M+1) + M; ==> Caso general número aleatorio entre  M y N

numero = drand48();				==> devuelve un número del 0.0 (incluido) al 1.0 (excluido)
numero = drand48() * (N-M) + N; ==> Caso general número aleatorio entre  M y N (con decimales)

*/