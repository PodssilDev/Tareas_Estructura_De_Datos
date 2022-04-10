typedef struct{
	int numero_elementos;
	int elementos[512];} conjunto;

void crea_conjunto(conjunto *c);

void agrega(conjunto *c, int n);

void elimina(conjunto *c, int n);

void busca_elemento(conjunto c, int n, int *encontrado);




