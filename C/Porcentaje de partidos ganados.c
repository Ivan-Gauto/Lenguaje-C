#include <stdio.h>

void ingresarDatos();
void calcularPorcentaje();
void mostrarPorcentaje();

int partidosGan, partidosJu;
float porcParGan;

int main() {
	ingresarDatos();
	calcularPorcentaje();
	mostrarPorcentaje();
	return 0;
}

void ingresarDatos() {
	printf("Partidos jugados: ");
	scanf("%d", &partidosJu);
	printf("Partidos ganados: ");
	scanf("%d", &partidosGan);
}

void calcularPorcentaje() {
	porcParGan = (partidosGan * 100)/ partidosJu;
}


void mostrarPorcentaje() {
	printf("\nPorcentaje de partidos ganados: %c%.1f", 37, porcParGan);
}
