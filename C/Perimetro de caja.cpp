#include <stdio.h>

void inicializarVariables();
void ingresarDatos();
void calcularPerimetro();
void mostrarResultados();

float lado1, lado2, perimetro;

int main(){
	inicializarVariables();
	ingresarDatos();
	calcularPerimetro();
	mostrarResultados();
	
	return 0;
}

void inicializarVariables() {
	lado1 = 0;
	lado2 = 0;
	perimetro = 0;
}

void ingresarDatos() {
	printf("Ingrese el valor del ancho \n");
	scanf("%f", &lado1);
	printf("Ingrese el valor del largo \n");
	scanf("%f", &lado2);
}

void calcularPerimetro() {
	perimetro = 2*(lado1 + lado2);
	printf("El perimetro es:", perimetro);
}

void mostrarResultados() {
	printf("El largo es %.2f m \n El ancho es %.2f m \n El perimetro es %.2f m", lado1, lado2, perimetro);
};

