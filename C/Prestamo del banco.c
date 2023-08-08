#include <stdio.h> 

void ingresarSueldo();
void calcularPrestamo();
void mostrarResultado();

float prestamo, sueldo;

int main() {	
	ingresarSueldo();
	calcularPrestamo();
	mostrarResultado();
	return 0;
}

void ingresarSueldo() {
	printf("Ingrese su sueldo \n");
	scanf("%f", &sueldo);
}

void calcularPrestamo() {
	if (sueldo >= 100000) {
		prestamo = 300000;
	} else {
		prestamo = sueldo * 0.75;
	}
}

void mostrarResultado() {
	printf("Su prestamo es: $%.2f", prestamo);
}
