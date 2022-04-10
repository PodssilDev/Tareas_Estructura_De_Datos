typedef struct nodo *enlace;  

struct nodo
{ 
  int item;
  enlace siguiente;
};

enlace crea_nodo(int n);
enlace nueva_lista(void);
enlace insertar_final(int x, enlace t);
enlace concatena_listas(enlace u, enlace t);
void imprime_lista(enlace h);
