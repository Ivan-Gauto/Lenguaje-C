#include <stdio.h>

void iniciarVariables();
void ingresarDatos();
void calcularPrecio();
void imprimirTicket();

int unidades;
float precioUnit, descuento, precioDescuento, total;
char formaDePago;

int main() {
	
	iniciarVariables();
	ingresarDatos();
	calcularPrecio();
	calcularBeneficio();
	imprimirTicket();
	
	return 0;
}

void iniciarVariables() {
	
	precioUnit = 0;
	descuento = 0;
	precioDescuento = 0;
	total = 0;
	
}

void ingresarDatos() {
	printf("Ingresar cantidad de productos a comprar: \n");
	scanf("%d", &unidades);
	printf("Ingresar precio unitario: \n");
	scanf("%f", &precioUnit);
	fflush(stdin);
	printf("Ingrese forma de pago: \n");
	scanf("%c", &formaDePago);
}

void calcularPrecio() {
	total = precioUnit * unidades;
}

void calcularBeneficio() {
	
	if((total >= 5000)||(unidades > 10)) {
		precioDescuento = (total * 0.85);
		descuento = (total * 0.15);	
	} else {
		precioDescuento = total;
	}
	
}

void imprimirTicket() {
	
printf("____________________________________________________\n \n");
printf("Cantidad de unidades: %d - Precio unitario: $%.2f \n\n", unidades, precioUnit);
printf("total: $%.2f \n \n", total);
printf("Forma de pago: %c \n \n", formaDePago);
printf("Descuento: $%.2f \n \n", descuento);
printf("total a pagar: $%.2f \n \n", precioDescuento);
printf("%cGracias por su compra! \n", 33);
printf("____________________________________________________");

};
