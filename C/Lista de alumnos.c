#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#define MAX 20

typedef char tString[MAX];

typedef struct {
	int libretaUni;
	tString nombre;
}tAlumno;

typedef struct nodo {
	tAlumno alumno;
	struct nodo * siguiente;
}tListaAlumnos;

tAlumno datos;
tListaAlumnos * listaAlumnos;
int opcion, posicion;

void inicializarLista();
void ingresarOpcion();
void menu();
void ingresarDatos();
void ingresarPosicion();
bool listaVacia(tListaAlumnos *);
void insertarAlumnos(tAlumno);
void insertarPrimerAlum(tAlumno);
void insertarSigAlu(tAlumno);
void insertarEnPos(int, tAlumno);
void eliminarPrimerAlum();
void eliminarEnPos(int);
void mostrarAlumnos(tListaAlumnos *);
void contarAlumnos(tListaAlumnos *);

int main() {
	
	inicializarLista();
	menu();
	
	return 0;
}

void inicializarLista() {
	listaAlumnos = NULL;
	printf("\n---Lista inicializada---\n");
}

bool listaVacia(tListaAlumnos * pLista) {
	return (pLista == NULL);
}

void ingresarOpcion() {
	printf("\nIngrese opcion: \n0-Salir 1-Ingresar 2-Eliminar 3-Ingresar en posicion 4-Eliminar en posicion 5-mostrar alumnos 6-contar alumnos\n");
	scanf("%d", &opcion);
}

void menu() {
	ingresarOpcion();
	while(opcion != 0) {
		switch(opcion) {
			case 1: 
				ingresarDatos();
				insertarAlumnos(datos);
			break;
			case 2: 
				eliminarPrimerAlum();
			break;
			case 3: 
				ingresarDatos();
				ingresarPosicion();
				insertarEnPos(posicion, datos);
			break;
			case 4: 
				ingresarPosicion();
				eliminarEnPos(posicion);
			break;
			case 5: 
				mostrarAlumnos(listaAlumnos);
			break;
			case 6:
				contarAlumnos(listaAlumnos);
			break;
			default: printf("\n***Opcion invalida***\n");
		}
		ingresarOpcion();
	}
}

void ingresarDatos() {
	printf("\nIngrese nro. de libreta universitaria: ");
	scanf("%d", &datos.libretaUni);
	printf("\nIngrese nombre de alumno: ");
	scanf("%s", &datos.nombre);
}

void ingresarPosicion() {
	printf("\nIngrese posicion a modificar: ");
	scanf("%d", &posicion);
}

void insertarPrimerAlum(tAlumno pAlumno) {
	tListaAlumnos * nuevoNodo;
	nuevoNodo = (tListaAlumnos *) malloc(sizeof(tListaAlumnos));
	nuevoNodo->alumno = pAlumno;
	nuevoNodo->siguiente = NULL;
	listaAlumnos = nuevoNodo;
	printf("\n---Primer alumno insertado---\n");
}

void insertarSigAlum(tAlumno pAlumno) {
	tListaAlumnos * nuevoNodo;
	nuevoNodo = (tListaAlumnos *) malloc(sizeof(tListaAlumnos));
	nuevoNodo->alumno = pAlumno;
	nuevoNodo->siguiente = listaAlumnos;
	listaAlumnos = nuevoNodo;
}

void insertarAlumnos(tAlumno pAlumno) {
	if(listaVacia(listaAlumnos)) {
		insertarPrimerAlum(pAlumno);
	} else {
		insertarSigAlum(pAlumno);
	}
}

void insertarEnPos(int posicion, tAlumno pAlumno) {
	tListaAlumnos * listaAux = listaAlumnos;
	int i;
	for(i=1; i<posicion-1; i++) {
		listaAux = listaAux->siguiente;
	}
	tListaAlumnos * nuevoNodo = (tListaAlumnos *) malloc(sizeof(tListaAlumnos));
	nuevoNodo->alumno = pAlumno;
	nuevoNodo->siguiente = listaAux->siguiente;
	listaAux->siguiente = nuevoNodo;
}

void eliminarPrimerAlum() {
	if(listaVacia(listaAlumnos)) {
		printf("\n***No hay alumnos para quitar de la lista***\n");
	} else {
		tListaAlumnos * suprimir = listaAlumnos;
		listaAlumnos = listaAlumnos->siguiente;
		printf("\n---Alumno eliminado: %s-%d---\n", suprimir->alumno.nombre, suprimir->alumno.libretaUni);
		free(suprimir);
		suprimir = NULL;
	}
}

void eliminarEnPos(int pPosicion) {
	tListaAlumnos * listaAux = listaAlumnos;
	int i;
	for(i=1; i<pPosicion-1; i++) {
		listaAux = listaAux->siguiente;
	}
	tListaAlumnos * nodoSuprimir = listaAux->siguiente;
	listaAux->siguiente = nodoSuprimir->siguiente;
	printf("\n---Ha sido eliminado el alumno %s-%d de la posicion %d---\n", nodoSuprimir->alumno.nombre, nodoSuprimir->alumno.libretaUni, pPosicion);
	free(nodoSuprimir);
	nodoSuprimir = NULL;
}

void mostrarAlumnos(tListaAlumnos * pListaAlumnos) {
	if(listaVacia(listaAlumnos)) {
		printf("\n***No hay alumnos para mostrar de la lista***\n");
	} else {
		printf("\n");
		tListaAlumnos * listaAux = pListaAlumnos;
		while(listaAux != NULL) {
			printf("%s-%d | ", listaAux->alumno.nombre, listaAux->alumno.libretaUni);
			listaAux = listaAux->siguiente;
		}
		printf("\n");
	}
}

void contarAlumnos(tListaAlumnos * pListaAlumnos){
	if(listaVacia(pListaAlumnos)) {
		printf("\n---La cantidad de alumnos es 0---\n");	
	} else {
		tListaAlumnos * listaAux = pListaAlumnos;
		int cantidad = 0;
		while(listaAux != NULL) {
			cantidad++;
			listaAux = listaAux->siguiente;
		}
		printf("\n---Cantidad de alumnos: %d---\n", cantidad);
	}
}

