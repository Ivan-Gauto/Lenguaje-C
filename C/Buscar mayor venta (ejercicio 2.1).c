#include <stdio.h>
#include <string.h>

void inicializarVariables();
void ingresarVentas();
void sumarVentasSuc();
void sumarVentasMen();
void mayorVenta();
void mostrarInforme();


enum tMeses {
	ENERO = 1, FEBRERO, MARZO, ABRIL, MAYO, JUNIO, JULIO, AGOSTO, SEPTIEMBRE, OCTUBRE, NOVIEMBRE, DICIEMBRE
};

typedef char tString[100];

tString meses[12] = {"Enero", "Febrero", "Marzo", "Abril", "Mayo", "Junio", "Julio", "Agosto", "Septiembre", "Octubre", "Noviembre", "Diciembre"};
float matVentas[6][12], vecVenSuc[6], vecVenMen[12];
int i, j, posicion;
float mayor;

int main() {
	inicializarVariables();
	ingresarVentas();
	sumarVentasSuc();
	sumarVentasMen();
	mayorVenta();
	mostrarInforme();
	return 0;
}

void inicializarVariables() {
	for(i=0; i<6; i++) {
		for(j=0; j<DICIEMBRE; j++) {
			matVentas[i][j] = 0;
		}
	}
	for(i=0; i<6; i++) {
		vecVenSuc[i] = 0.0;
	}
	for(j=0; j<DICIEMBRE; j++) {
		vecVenMen[j] = 0.0;
	}	
	mayor = 0.0;
}

void ingresarVentas() {
	for(i=0; i<6; i++) {
		printf("\nIngrese ventas de sucursal nro. %d \n", i+1);
		for(j=0; j<DICIEMBRE; j++) {
			printf("\nMes de %s: ", meses[j]);
			fflush(stdin);
			scanf("%f", &matVentas[i][j]);
		}
	}
}


void sumarVentasSuc() {
	for(i=0; i<6; i++) {
		for(j=0; j<DICIEMBRE; j++) {
			vecVenSuc[i] = vecVenSuc[i] + matVentas[i][j];
		}
	}	
}

void sumarVentasMen() {
	for(j=0; j<DICIEMBRE; j++) {
		for(i=0; i<6; i++) {
			vecVenMen[j] = vecVenMen[j] + matVentas[i][j];
		}
	}
}

void mayorVenta() {
	printf("\n\n");
	for(i=0; i<6; i++) {
		if(vecVenSuc[i] > mayor) {
			mayor = vecVenSuc[i];
			posicion = i+1;
		}
	}
}

void mostrarInforme() {
	printf("\n--------------Ventas por sucursal en funcion de los meses--------------\n");
	for(i=0; i<6; i++) {
		printf("\n\n  sucursal nro: %d    \n\n", i+1);
		for(j=0; j<DICIEMBRE; j++) {
			printf("    %s: %c%.2f\n", meses[j], 36, matVentas[i][j]);
		}
	}
	printf("\n-------------------------------------------------------------------------");
	printf("\n\nLa mayor recaudacion en ventas en el a%co fue de %c%.2f en la sucursal nro. %d\n", 164, 36, mayor, posicion);
	printf("\n-------------------------------------------------------------------------");
	printf("\nRecaudacion total de sucursales por mes: \n\n");
	for(j=0; j<DICIEMBRE; j++) {
		printf("%s: %c%.2f  \n\n", meses[j], 36, vecVenMen[j]);
	}	
}


