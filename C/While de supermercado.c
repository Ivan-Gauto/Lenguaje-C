#include <stdio.h>
#include <string.h>

void iniciarVariables();
void datosDeControl();
void ingresarDatos();
void calcularCompra();
void mostrarResultados();

int cantidad, cantidadTotal;
float precioUnit, precioSubTotal, precioTotal;
char nombreProducto[30];

int main () {
	iniciarVariables();
	datosDeControl();
	while (cantidad != 0) {
		ingresarDatos();
		calcularCompra();
		mostrarResultados();
		datosDeControl();
	}
	mostrarResultados();
	return 0;
}

void iniciarVariables() {
	precioUnit = 0;
	cantidad = 0;
	precioTotal = 0;
	cantidadTotal = 0;
}

void datosDeControl() {
	printf("Ingrese cantidad de productos: ");
	scanf("%d", &cantidad);
}

void ingresarDatos() {
	fflush(stdin);
	printf("Ingrese nombre del producto: ");
	scanf("%[^\n]s", &nombreProducto);
	printf("Ingrese precio del producto: ");
	scanf("%f", &precioUnit);
}

void calcularCompra() {
	precioSubTotal = precioUnit * cantidad;
	cantidadTotal = cantidadTotal + cantidad;
	precioTotal =  precioTotal + precioSubTotal;
}

void mostrarResultados() {
	printf("\n ____________________________________________\n");
	printf("|\n");
	printf("|Producto: %s %d X %.2f \n", nombreProducto, cantidad, precioUnit);
	printf("|Subtotal a pagar: %.2f \n", precioSubTotal);
	printf("|Cantidad de productos: %d \n", cantidadTotal);
	printf("|Total a pagar: %.2f \n", precioTotal);
	printf("|\n");	
	printf("|%cGracias por su compra! \n", 33);
	printf("|____________________________________________\n\n");
}

