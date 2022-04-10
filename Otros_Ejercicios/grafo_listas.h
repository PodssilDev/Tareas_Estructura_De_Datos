 
typedef struct nodo *enlace;

struct nodo{ 
	int v; 
	enlace siguiente; 
	};

typedef struct { 
	int v; 
	int w;}arista;

struct grafo { 
	int V; 
	int A; 
	enlace *adj; 
	};

typedef struct grafo *Grafo;

