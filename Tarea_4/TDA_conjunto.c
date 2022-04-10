/*TAREA TDA
ESTRUCTURA DE DATOS
*/
#include <stdio.h>
#include "conjunto.h"
 
int error_conjunto;

void crea_conjunto(conjunto *c){
	error_conjunto = 0;
	c->numero_elementos = 0;
}

void busca_elemento(conjunto c, int n, int *encontrado){
	int inferior, superior, central;
	inferior = 0;
	superior = c.numero_elementos - 1;
	*encontrado = 0;
	while ((inferior <= superior) && (!(*encontrado))){
		central = (inferior + superior) / 2;
		if (c.elementos[central] == n){
			*encontrado = 1;
		}
		else{
			if (c.elementos[central] < n){
				inferior = central + 1;
			}
			else{
				superior = central - 1;
			}
		}
	}

}



void agrega(conjunto *c, int n){
	int encontrado, i;
	busca_elemento(*c, n, &encontrado);
	if (!encontrado)
		if (c->numero_elementos < 512){
			i = c->numero_elementos-1;
			while(n < c->elementos[i] && i >= 0){
				c->elementos[i + 1] = c->elementos[i]; 
				i--;
			}
			c->elementos[++i] = n;
			c->numero_elementos++;
		}
		else
			error_conjunto = 1;
}


void elimina(conjunto *c, int n)
{
	int encontrado,i;
	busca_elemento(*c, n, &encontrado);
	if (encontrado)
	{
		i = 0;
		while(n != c->elementos[i])
			i++;
		i++;
		while(i < c->numero_elementos){
			c->elementos[i - 1] = c->elementos[i];
			i++;
			}
		c->numero_elementos--;
}
}


void muestra_conjunto(conjunto *c){
	int i;
	printf("El conjunto tiene %d elementos \n", c->numero_elementos);	
	for (i = 0; i < c->numero_elementos; i++){
			printf("elemento %d: %d \n", i + 1, c->elementos[i]);	
		}
	}

void interseccion_conjunto(conjunto *c, conjunto *c2){
	int i = 0;
	int j = 0;
	int cont;
	if (c->numero_elementos > c2->numero_elementos){
		while (i < c2->numero_elementos){
			cont = 0;
			for (j = 0; j < c->numero_elementos; j++){
				if (c2->elementos[i] == c->elementos[j]){
					cont = 1;
				}
			}
			if (cont == 0){
				elimina(c2, c2->elementos[i]);
			}
			i++;
		}
	}
}

void union_conjunto(conjunto *c, conjunto *c2){
	int i = 0;
	int j = 0;
	int cont;
	if (c->numero_elementos > c2->numero_elementos){
		while (i < c2->numero_elementos){
			cont = 0;
			for (j = 0; j < c->numero_elementos; j++){
				if (c2->elementos[i] == c->elementos[j]){
					cont = 1;
				}
			}
			if (cont == 0){
				agrega(c, c2->elementos[i]);
			}
			i++;
		}
	}
}
void diferencia_conjunto(conjunto *c, conjunto *c2){
	int i = 0;
	int j = 0;
	int cont;
	if (c->numero_elementos > c2->numero_elementos){
		while (i < c2->numero_elementos){
			cont = 0;
			for (j = 0; j < c->numero_elementos; j++){
				if (c2->elementos[i] == c->elementos[j]){
					cont = 1;
				}
			}
			if (cont == 1){
				elimina(c, c2->elementos[i]);
			}
			i++;
		}
	}
}
int main ()
{
	conjunto un_conjunto, conjunto_2;
	int encontrado, i, opcion;
	// Se crea un conjunto vacío
	crea_conjunto(&un_conjunto);
	crea_conjunto(&conjunto_2);
	// Se agregan elementos al conjunto
	agrega(&un_conjunto, 0);
	agrega(&un_conjunto, 2);
	agrega(&un_conjunto, 4);
	agrega(&un_conjunto, 6);
	agrega(&un_conjunto, 8);
	agrega(&conjunto_2, 3);
	agrega(&conjunto_2, 4);
	agrega(&conjunto_2, 5);
	agrega(&conjunto_2, 6);
	muestra_conjunto(&un_conjunto);
	muestra_conjunto(&conjunto_2);
	printf("Menu:\n");
	printf("1) Union de dos conjunto A y B\n");
	printf("2) Interseccion de dos conjuntos A y B\n");
	printf("3) Diferencia A - B entre un conjunto A y un conjunto B\n");
	printf("4) Salir\n");
	while (opcion != 4){
		printf("Seleccione una opcion: ");
		scanf("%d", &opcion);
		if (opcion == 1){
			union_conjunto(&un_conjunto, &conjunto_2);
			printf("La Union de los conjuntos es:\n");
			muestra_conjunto(&un_conjunto);
			return 0;
		}
		if (opcion == 2){
			interseccion_conjunto(&un_conjunto, &conjunto_2);
			printf("La Interseccion de los conjuntos es:\n");
			muestra_conjunto(&conjunto_2);
			return 0;
		}
		if (opcion ==3){
			diferencia_conjunto(&un_conjunto, &conjunto_2);
			printf("La diferencia de los conjuntos es:\n");
			muestra_conjunto(&un_conjunto);
			return 0;
		}
		if (opcion == 4){
			return 0;
		}
	}
}