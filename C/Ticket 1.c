#include <stdio.h>

void ingresarDatos();
void calcularTotal();
void mostrarResultados();

float precio, total;
int cantidad;

int main() {	
	ingresarDatos();
	calcularTotal();
	mostrarResultados();	
	return 0;
}

void ingresarDatos() {	
	printf("Ingrese precio del producto: ");
	scanf("%f", &precio);
	printf("Ingrese cantidad de productos: ");
	scanf("%d", &cantidad);	
}

void calcularTotal() {	
	total = precio * cantidad;	
}

void mostrarResultados() {
	printf("___________________________________________________\n\n");
	printf("Cantidad de unidades: %d - Precio unitario: $%.2f \n", cantidad, precio);
	printf("Total a pagar: $%.2f \n", total);
	printf("%cGracias por su compra! \n", 173);
	printf("__________________________________________________");
}


