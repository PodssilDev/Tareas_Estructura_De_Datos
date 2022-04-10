#include <stdio.h> 
#include <stdlib.h>
#include "lista.h"

enlace crea_nodo(int n)
{
    enlace t;

    t = malloc(sizeof(enlace));
    if (t != NULL)
    {
        t->item = n;
        t->siguiente = NULL;
    }
    return t;
}

enlace nueva_lista()
{
    int n;
    enlace head, nuevo, t = NULL;

    printf("Ingrese elementos: ");
    while (!feof(stdin))
    {
        scanf("%d ",&n);
        nuevo = crea_nodo(n);
        if (t == NULL)
	    {
			t = nuevo;
			head = t;
			}
		else
		{
			t->siguiente = nuevo;
			t = t->siguiente;
			}
    }
    printf("\n");
	return head;
}

enlace insertar_final(int n, enlace t)
{
    enlace nuevo, head = t;

    nuevo = crea_nodo(n);
    if (t == NULL)
		head = nuevo;
    else
    {
        while (t->siguiente != NULL)
			t = t->siguiente;
        t->siguiente = nuevo;
    }  
    return head;
}

enlace concatena_listas(enlace primero, enlace segundo)
{
    enlace head = primero;
    while (primero->siguiente != NULL)
		primero = primero->siguiente;
    primero->siguiente = segundo;
    return head;
}

void imprime_lista(enlace t)
{
    while (t != NULL)
    {
		printf("%d ", t->item);
        t = t->siguiente;
    }
    printf("\n");
}
