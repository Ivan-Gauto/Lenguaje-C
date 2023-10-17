#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#define MAX 25

typedef char tString[MAX];

typedef struct {
	tString nombreApellido;
	tString email;
	int categoria;
	float monto;
}tDatosPersona;

typedef struct nodo {
	tDatosPersona datosPersona;
	struct nodo * siguiente;
}tNodoPersona;

tNodoPersona * personas;

void inicializarPila();
bool pilaVacia(tNodoPersona *);
int ingresarOpcion();
void menu();
tDatosPersona ingresarDatos();
void apilarPersona(tDatosPersona);
void desapilarPersona();
float calcularPorcentaje(tNodoPersona *);
int contarProfesionales(tNodoPersona *);
int montoRecEstudiantes(tNodoPersona *);
int totalRecaudado(tNodoPersona *);
void mostrarInforme(tNodoPersona *);

int main() {
	inicializarPila();
	printf("Pila vacia?: %s", pilaVacia(personas) == true ? "SI" : "NO");
	menu();
	return 0;
}

void inicializarPila() {
	personas = NULL;
	printf("\nPila inicializada...\n");
}

bool pilaVacia(tNodoPersona * pNodoPersonas) {
	return pNodoPersonas == NULL;
}

int ingresarOpcion() {
	int opcion;
	printf("\nSeleccione una opcion: \n\t1-Apilar persona \n\t2-desapilar persona \n\t3-Mostrar informe ");
	printf("\n\t0-salir \n-> ");	
	scanf("%d", &opcion);
	return opcion;	
}

void menu() {
	int opcion = ingresarOpcion();
	switch(opcion) {
		case 0:
			printf("\n---Programa finalizado---\n");
			break;
		case 1: {
			tDatosPersona datos = ingresarDatos();
			apilarPersona(datos);
			menu();
			break;
		}
		case 2:
			desapilarPersona();
			menu();
			break;
		case 3:
			mostrarInforme(personas);
			menu();
			break; 
		default: 
			printf("\n---Opcion invalida---\n");
			menu();
			break;	
	}
}

tDatosPersona ingresarDatos() {
	tDatosPersona datos;
	printf("Ingrese nombre y apellido: ");
	fflush(stdin);
	scanf("%[^\n]s", &datos.nombreApellido);
	printf("Email: ");
	fflush(stdin);
	scanf("%s", &datos.email);
	printf("\n1-Estudiante 2-Profesional 3-Publico en general: ");
	scanf("%d", &datos.categoria);
	if(datos.categoria == 1) {
		datos.monto = 200;
	} else if(datos.categoria == 2 || datos.categoria == 3) {
		datos.monto = 350;
	}
	return datos;
}

void apilarPersona(tDatosPersona pDatosPersona) {
	tNodoPersona * nuevaPersona = (tNodoPersona *) malloc(sizeof(tNodoPersona));
	nuevaPersona->datosPersona = pDatosPersona;
	nuevaPersona->siguiente = personas;
	personas = nuevaPersona;
	printf("\n***Se guardaron los datos de %s***\n", nuevaPersona->datosPersona.nombreApellido);
}

void desapilarPersona() {
	if(pilaVacia(personas)) {
		printf("\n---No hay personas para desapilar de la pila---\n");
	} else {
		tNodoPersona * personaSuprimir = personas;
		personas = personaSuprimir->siguiente;
		printf("\n***Persona eliminada de la pila: %s***\n", personaSuprimir->datosPersona.nombreApellido);
		free(personaSuprimir);
		personaSuprimir = NULL;
	}
	
}

int contarProfesionales(tNodoPersona * pNodoPersona) {
	tNodoPersona * pilaAux = pNodoPersona;
	int profesionales = 0;
	while(pilaAux != NULL) {
		if(pilaAux->datosPersona.categoria == 2) {
			profesionales++;
		}
		pilaAux = pilaAux->siguiente;
	}
	return profesionales;
}

float calcularPorcentaje(tNodoPersona * pNodoPersona) {
	tNodoPersona * pilaAux = pNodoPersona;
	int total = 0;
	int profesionales = contarProfesionales(pNodoPersona);
	float porcentaje;
	while(pilaAux != NULL) {
		total++;
		pilaAux = pilaAux->siguiente;
	}
	porcentaje = profesionales * 100 / total;
	return porcentaje;
}

int montoRecEstudiantes(tNodoPersona * pNodoPersona) {
	tNodoPersona * pilaAux = pNodoPersona;
	int recEstudiantes = 0;
	while(pilaAux != NULL) {
		if(pilaAux->datosPersona.categoria == 1) {
			recEstudiantes += pilaAux->datosPersona.monto;
		}
		pilaAux = pilaAux->siguiente;
	}
	return recEstudiantes;
}

int totalRecaudado(tNodoPersona * pNodoPersona) {
	tNodoPersona * pilaAux = pNodoPersona;
	int totalRec;
	while(pilaAux != NULL) {
		totalRec += pilaAux->datosPersona.monto;
		pilaAux = pilaAux->siguiente;
	}
	return totalRec;
}

void mostrarInforme(tNodoPersona * pNodoPersona) {
	if(pilaVacia(pNodoPersona)) {
		printf("\n---No hay personas en la pila---\n");
	} else {
		tNodoPersona * pilaAux = pNodoPersona;
		int totalRec = totalRecaudado(pNodoPersona);
		int recEstudiantes = montoRecEstudiantes(pNodoPersona);
		int profesionales = contarProfesionales(pNodoPersona);
		float porcentajeProf = calcularPorcentaje(pNodoPersona);
		printf("\n******************************************\n");
		while(pilaAux != NULL) {
			printf("Nombre y apellido: %s", pilaAux->datosPersona.nombreApellido);
			printf("\nEmail: %s", pilaAux->datosPersona.email);
			switch(pilaAux->datosPersona.categoria) {
				case 1:
					printf("\nCategoria: Estudiante");
					break;
				case 2:
					printf("\nCategoria: profesional");
					break;
				case 3:
					printf("\nCategoria: publico en general");
					break;
			}
			printf("\n******************************************\n");
			pilaAux = pilaAux->siguiente;
		}
		printf("\n******************************************");
		printf("\nTotal recaudado: %d", totalRec);
		printf("\nTotal recaudado solamente estudiantes: %d", recEstudiantes);
		printf("\nTotal de profesionales: %d", profesionales);
		printf("\nPorcentaje de profesionales en el evento: %.1f", porcentajeProf);	
		printf("\n******************************************\n");
	}

}


