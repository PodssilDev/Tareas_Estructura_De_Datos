#include <stdlib.h>  
#include "cola.h"


static enlace head, tail;

enlace nuevoNodo(Item item, enlace siguiente)
{
  enlace x = malloc(sizeof(*x));

  x->item = item;
  x->siguiente = siguiente;
  return x;
}

void inicializaCola(int maxn)
{
  head = NULL;
}

int esVacia(void)
{
  return head == NULL;
}

void colaPut(Item item)
{
  if (head == NULL)
    {
      head = (tail = nuevoNodo(item, head));
      return;
    }
  tail->siguiente = nuevoNodo(item, tail->siguiente);
  tail = tail->siguiente;
}

Item colaGet(void)
{
  Item item = head->item;
  enlace t = head->siguiente;

  free(head);
  head = t;
  return item;
}