#include <stdio.h>

void ingresarDatos();
void calcularIMC();
void mostrarResultado();

float altura, peso, IMC;

int main() {
	ingresarDatos();
	calcularIMC();
	mostrarResultado();
}

void ingresarDatos() {
	printf("Ingrese altura \n");
	scanf("%f", &altura);
	printf("Ingrese peso \n");
	scanf("%f", &peso);
};

void calcularIMC() {
	IMC = peso / altura;
};

void mostrarResultado() {
	printf("Su indice de masa corporal es: %f.2", IMC);
};

