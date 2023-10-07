#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#define MAX 25
#define N 5

typedef char tString[MAX];

typedef int tVertice;

typedef struct {
	tVertice origen;
	tVertice destino;
}tArista;

typedef bool tConjuntoVertices[N];

typedef bool tConjuntoAristas[N][N];

typedef struct {
	tConjuntoVertices vertices;
	tConjuntoAristas aristas;
}tGrafoNoPonderado;

void inicializarGrafo(tGrafoNoPonderado *);
int ingresarVertice();
tArista ingresarArista();
int ingresarOpcion();
void menu();
void agregarVertice(tGrafoNoPonderado *, tVertice);
void agregarArista(tGrafoNoPonderado *, tArista);
void borrarVertice(tGrafoNoPonderado *, tVertice);
void borrarArista();
int maximoVertice(tGrafoNoPonderado);
void visualizarMatrizAdyacencia(tGrafoNoPonderado);
bool existeVertice(tGrafoNoPonderado, tVertice);
bool existeArista(tGrafoNoPonderado, tArista);

tGrafoNoPonderado grafoNP;

int main() {
	inicializarGrafo(&grafoNP);
	menu();
	return 0;
}

void inicializarGrafo(tGrafoNoPonderado * pGrafoNP) {
	int i, j;
	for(i=1; i<=N; i++) {
		pGrafoNP->vertices[i] = false;
		for(j=1; j<=N; j++) {
			pGrafoNP->aristas[i][j] = false;
		}
	}
	printf("\nGrafo no ponderado inicializado...\n");
}

bool existeVertice(tGrafoNoPonderado pGrafoNP, tVertice pVertice) {
	return pGrafoNP.vertices[pVertice] == true;
}

bool existeArista(tGrafoNoPonderado pGrafoNP, tArista pArista) {
	return pGrafoNP.aristas[pArista.origen][pArista.destino] == true;
}

int ingresarOpcion() {
	int opcion;
	printf("\nSeleccione una opcion: \n");
	printf("\n\t1-Agregar vertice");
	printf("\n\t2-Agregar arista");
	printf("\n\t3-Borrar vertice");
	printf("\n\t4-Borrar arista");
	printf("\n\t5-Visualizar matriz de adyacencia");
	printf("\n-> ");
	scanf("%d", &opcion);
	return opcion;
}

void menu() {
	int opcion = ingresarOpcion();
	switch(opcion) {
		case 1: {
			int vertice = ingresarVertice();
			agregarVertice(&grafoNP, vertice); 
			menu();
			break;
		}
		case 2: {
			tArista arista = ingresarArista();
			agregarArista(&grafoNP, arista);
			menu();
			break;
		}
		case 3: {
			int vertice = ingresarVertice();
			borrarVertice(&grafoNP, vertice);
			menu();
			break;
		}
		case 4: {
			tArista arista = ingresarArista();
			borrarArista(&grafoNP, arista);
			menu();
			break;
		}
		case 5: 
			visualizarMatrizAdyacencia(grafoNP);
			menu();
			break;
		default: 
			printf("\n---Opcion invalida---\n");
			menu(); 
			break;
	}
}

int ingresarVertice() {
	int vertice;
	printf("\nIngrese vertice: ");
	scanf("%d", &vertice);
	return vertice;
}

tArista ingresarArista() {
	tArista arista;
	printf("\nIngrese origen de la arista: ");
	scanf("%d", &arista.origen);
	printf("\nIngrese destino de la arista: ");
	scanf("%d", &arista.destino);
	return arista;
}

void agregarVertice(tGrafoNoPonderado * pGrafoNP, tVertice pVertice) {
	pGrafoNP->vertices[pVertice] = 1;
	printf("\nVertice %d insertado\n", pVertice);
}

void agregarArista(tGrafoNoPonderado * pGrafoNP, tArista pArista) {
	bool aristaValida = pGrafoNP->vertices[pArista.origen] == true
	&& pGrafoNP->vertices[pArista.destino] == true;
	if(aristaValida) {
		pGrafoNP->aristas[pArista.origen][pArista.destino] = true;
		printf("\nArista: %d ----------- %d agregada\n", pArista.origen, pArista.destino);
	} else {
		printf("\n---Arista no valida, alguno de los nodos no esta activo---\n");
	}
}

void borrarVertice(tGrafoNoPonderado * pGrafoNP, tVertice pVertice) {
	pGrafoNP->vertices[pVertice] = false;
	printf("Vertice desactivado: %d\n", pVertice);
}

void borrarArista(tGrafoNoPonderado * pGrafoNP, tArista pArista) {
	if(existeArista(* pGrafoNP, pArista)) {
		pGrafoNP->aristas[pArista.origen][pArista.destino] = false;
	} else {
		printf("\n---No existe la arista que se desea borrar---\n");
	}
}

int maximoVertice(tGrafoNoPonderado pGrafoNP) {
	int i;
	int max = 0;
	for(i=1; i<=N; i++) {
		if(pGrafoNP.vertices[i] == true) {
			max = i;
		}
	}
	return max;
}

void visualizarMatrizAdyacencia(tGrafoNoPonderado pGrafoNP) {
	int i, j;
	int maxVertice = maximoVertice(pGrafoNP);
	for(i=1; i<=maxVertice; i++) {
		for(j=1; j<=maxVertice; j++) {
			tArista aristaActual = {.origen = i, .destino = j};
			if(existeVertice(pGrafoNP, i) && existeVertice(pGrafoNP, j) && existeArista(pGrafoNP, aristaActual)) {
				printf("1\t");
			} else {
				printf("0\t");
			}
		}
		printf("\n");
	}
}
