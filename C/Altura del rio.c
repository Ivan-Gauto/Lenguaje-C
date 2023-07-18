#include <stdio.h>

void inicializarVariables();
void ingresarAltSeries();
void buscarMesAlt();
void compararAltSeries();

int mes1, mes2, i, j;
float altSerie1[12], altSerie2[12], menorAlt1, menorAlt2, menor1, menor2;

int main() {
	
	inicializarVariables();
	ingresarAltSeries();
	buscarMesAlt();
	compararAltSeries();
	
	return 0;
}

void inicializarVariables() {
	for (i=0; i<=12; i++) {
		altSerie1[i] = 0;
	}
	for (j=0; j<=12; j++) {
		altSerie2[j] = 0;
	}
	menor1 = 99;
	menor2 = 99;
}

void ingresarAltSeries() {
	for (i=0; i<12; i++) {
		mes1 = i + 5;
		if(mes1 >= 13) {
			mes1 = i - 7;
		}
		printf("Ingrese altura del mes %d de la serie 1: ", mes1);
		scanf("%f", &altSerie1[i]);
	}
	printf("___________________________________________________\n\n");
	for (j=0; j<12; j++) {
		mes2 = j + 5;
		if(mes2 >= 13) {
			mes2 = j - 7;
		}
	    printf("Ingrese altura del mes %d de la serie 2: ", mes2);
	    scanf("%f", &altSerie2[j]);
	}
}

void buscarMesAlt() {
	for (i=0; i<12; i++) {
		if (altSerie1[i] < menor1) {
		    menor1 = altSerie1[i];
		    mes1 = mes1 + 5;
		}
	    if (mes1 >= 13) {
		    mes1 = i - 7;
		}
	}
	for (j=0; j<12; j++) {
		if (altSerie2[j] < menor2) {
		    menor2 = altSerie2[j];
		    mes2 = mes2 + 5;
		}
		if(mes2 >= 13) {
		   mes2 = j - 7;
		}
	}		
}

void compararAltSeries() {
	printf("\n___________________________________________________________________________\n\n");
	if (menor1 < menor2) {
		printf("La menor altura del rio fue en el mes %d de la serie 1 con: %.1f", mes1, menor1);
	} else if (menor1 > menor2) {
		printf("La menor altura del rio fue en el mes %d de la serie 2 con: %.1f", mes2, menor2);
	}
	printf("\n___________________________________________________________________________\n");
}
