#include <stdio.h>

void inicializarMatriz();
void mostrarMatriz();
void cargarMatriz();
void mostrarMatrizCarg();

int matriz[2][2];
int valores, i, j;

int main() {
	
	inicializarMatriz();
	mostrarMatriz();
	
	return 0;
}

void inicializarMatriz() {
	for(i=0; i<2; i++) {
		for(j=0; j<2; j++) {
			matriz[i][j] = 0;
		}
	}
}

void mostrarMatriz() {
	printf("La matriz esta inicializada en 0: \n");
	for(i=0; i<2; i++) {
		printf("\n\n");
		for(j=0; j<2; j++) {
			printf("%d   ", matriz[i][j]);
		}
	}
	printf("\n");
}
