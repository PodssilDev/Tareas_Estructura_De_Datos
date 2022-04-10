typedef int Item; 

typedef struct nodoCola *enlace;

struct nodoCola 
{
	Item item;
	enlace siguiente;
};

// Operaciones
void inicializaCola(int);
int esVacia(void);
void colaPut(Item);
Item colaGet(void);
