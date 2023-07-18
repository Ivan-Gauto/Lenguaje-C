#include <stdio.h>

void inicializarVariables();
void preguntaControl();
void ingresarValoracion();
void acumOpiniones();
void buscarMayor();
void mostrarInforme();

typedef char tString[100];
tString vecOpinion[3] = {"Excelente", "Bueno", "Malo"};
int i, j, matOpinion[5][3], matAcum[5][3], mayor1, mayor2, aceite1, aceite2;
char respuesta;

int main() {
	inicializarVariables();
	preguntaControl();
	while(respuesta == 's') {
		ingresarValoracion();
		acumOpiniones();
		preguntaControl();
	}
	buscarMayor();
	mostrarInforme();
	return 0;
}

void inicializarVariables() {
	for(i=0; i<5; i++) {
		for(j=0; j<3; j++) {
			matOpinion[i][j] = 0;
			matAcum[i][j] = 0;
		}
	}
	mayor1 = 0;
	mayor2 = 0;
}

void preguntaControl() {
	fflush(stdin);
	printf("\nDesea ingresar valoracion? (s-n): ");
	scanf("%c", &respuesta);
	fflush(stdin);
}

void ingresarValoracion() {
	printf("\nPara si-1 para no-0 \n\n");
	for(i=0; i<5; i++) {
		printf("ingrese valoracion del aceite nro. %d \n", i+1);
		for(j=0; j<3; j++) {
			printf("%s: ", vecOpinion[j]);
			fflush(stdin);
			scanf("%d", &matOpinion[i][j]);
		}
	}
}

void acumOpiniones() {
	for(i=0; i<5; i++) {
		for(j=0; j<3; j++) {
		    matAcum[i][j] = matAcum[i][j] + matOpinion[i][j];
		}
	}
}

void buscarMayor() {
	for(j=0; j<3; j++) {
		for(i=0; i<5; i++) {
			if(matAcum[i][0] > mayor1) {
				mayor1 = matAcum[i][0];
				aceite1 = i+1;
			}
			if(matAcum[i][2] > mayor2) {
				mayor2 = matAcum[i][2];
				aceite2 = i+1;
			}
		}
	}
}

void mostrarInforme() {
	for(i=0; i<5; i++) {
		printf("\n\n");
		for(j=0; j<3; j++) {
			printf("   %d   ", matAcum[i][j]);
		}
	}
	printf("\n\n   El aceite nro. %d fue el de mejor valoracion\n\n", aceite1);
	printf("   El aceite nro. %d fue el de peor valoracion\n", aceite2);
}
