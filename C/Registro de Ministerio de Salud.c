#include <stdio.h>

void inicializarVariables();
void ingresarCasos();
void acumCasos();
void buscarMayor();
void buscarMenor();
void mostrarInforme();

typedef char tString[1000];
tString vecMeses[3] = {"Marzo", "Abril", "Mayo"}, mes1, mes2;
int i, j, vecCasos[3], matCasos[3][5], menor, mayor, dia1, dia2;

int main() {
	ingresarCasos();
	acumCasos();
	buscarMayor();
	mostrarInforme();
	return 0;
}

void inicializarVariables() {
	for(i=0; i<3; i++) {
		for(j=0; j<5; j++) {
			matCasos[i][j] = 0;
		}
	}
	mayor = 0;
	menor = 99;
}

void ingresarCasos() {
	for(i=0; i<3; i++) {
		printf("Ingrese casos del mes de %s: \n", vecMeses[i]);
		for(j=0; j<5; j++) {
			printf("Dia %d: ", j+1);
			scanf("%d", &matCasos[i][j]);
		}
	}
}

void acumCasos() {
	for(i=0; i<3; i++) {
		for(j=0; j<5; j++) {
			vecCasos[i] = vecCasos[i] + matCasos[i][j];
		}
	}
}

void buscarMayor() {
	for(i=0; i<3; i++) {
		for(j=0; j<5; j++) {
			if(matCasos[i][j] > mayor) {
				mayor = matCasos[i][j];
				dia1 = j+1;
				mes1 = vecMeses[i];
			}
			if(matCasos[i][j] < menor) {
				menor = matCasos[i][j];
				dia2 = j+1;
				mes2 = vecMeses[i];
			}
		}
	}	
}

void mostrarInforme() {
	for(i=0; i<3; i++) {
	printf("\n\n");
		for(j=0; j<5; j++) {
			printf("   %d   ", matCasos[i][j]);
		}
	}
	printf("\n\n");
	printf("Cantidad de casos por mes: \n\n");
	for(i=0; i<3; i++) {
		printf("%s   %d   ", vecMeses[i], vecCasos[i]);
	}
	printf("\nLa mayor cantidad de casos fue de %d en el dia %d del mes de %s", mayor, dia1, mes1);
	printf("\nLa menor cantidad de casos fue de %d en el dia %d del mes de %s", menor, dia2, mes2);
}

