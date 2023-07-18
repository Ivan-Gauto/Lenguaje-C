#include <stdio.h>

void inicializarMatriz();
void ingresarVentas();
void sumarVentas();
void sumarSucursales();
void mostrarInforme();

float matVentas[3][3], acumVentas[3];
int totalRubros[3], i, j;

int main() {
	
	inicializarMatriz();
	ingresarVentas();
	mostrarInforme();
	
	return 0;
}

void inicializarMatriz() {
	for(i=0; i<3; i++) {
		for(j=0; j<3; j++) {
			matVentas[i][j] = 0.0;
		}
	}
}

void ingresarVentas() {
	for(i=0; i<3; i++) {
		printf("\nCargar datos de la sucursal %d ", i+1);
		for(j=0; j<3; j++) {
		printf("\ndel rubro %d: ", j+1);
		scanf("%f", &matVentas[i][j]);
		}
	}
}

void sumarVentas() {
	for(j=0; j<3; j++) {
		for(i=0; i<3; i++) {
			acumVentas[3] = acumVentas[3] + matVentas[i];
		}
	}
}

void mostrarInforme() {
	printf("\nElementos cargados en la matriz: \n");
	for(i=0; i<3; i++) {
		printf("\n\n");
		for(j=0; j<3; j++) {
			printf("%.1f   ", matVentas[i][j]);
		}
	}
	printf("\n");
}
