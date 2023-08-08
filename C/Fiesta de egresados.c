#include <stdio.h> 

void iniciarVariables();
void ingresarDatos();
void evaluarEntradas();
void mostrarResultados();

float total, descuento;
int consumicion, anticipada;

int main () {
	
	ingresarDatos();
	evaluarEntradas();
	mostrarResultados();
	
	return 0;
}

void ingresarDatos() {
	printf("1 - con consumision\n2 - sin consumision \n");
	scanf("%d",&consumicion);
	fflush(stdin);
	printf("¿La venta de entradas fue anticipada? \n s                         n \n");
	scanf("%c", &anticipada);
}

void evaluarEntradas() {
	if((anticipada == 's')&&(consumicion == 1)) {
		total = 750;
		descuento = total * 0.20;
	}
	if((anticipada == 's')&&(consumicion == 2)) {
	    total = 500;
	    descuento = total * 0.20;
	} 
	if ((anticipada == 'n')&&(consumicion == 1)) {
		total = 750;
	}
	if ((anticipada == 'n')&&(consumicion == 2))
	total = 500;
}

void mostrarResultados() {
	printf("Consumicion: %d \n", consumicion);
	printf("Anticipada: %c \n", anticipada);
	printf("total: $%.2f \n", total);
	printf("total con descuento: $%.2f", descuento);
}


