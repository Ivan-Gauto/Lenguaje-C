# include <stdio.h>

void inicializarVariables();
void ingresarDatos();
void calcularArea();
void mostrarResultados();

int main() {
	inicializarVariables();
	ingresarDatos();
	calcularArea();
	mostrarResultado();
}

void inicializarVariables() {
	area = 0;
	PI = 3,14;
	radio = 0;
	cantidadDeCircunferencias = 0;
}

ingresarDatos() {
	printf("Ingrese valor del radio \n");
	scanf("%f", radio);
	printf("Ingrese cantidad de circunferencias \n");
	scanf("%d", cantidadDeCircunferencias);
}

calcularArea() {
	area = (PI*(radio*radio));
	
}
