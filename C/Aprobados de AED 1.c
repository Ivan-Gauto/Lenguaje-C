#include <stdio.h>

void inicializarVariables();
void ingresarNotas();
void calcularPromedio();
void calcularPorcentaje();
void notasMayores();
void mostrarInforme();

int vecNotas[10];
float promedio, porcentaje;
int i, sumarNotas, totalAprobados, totalNotas, notasAprobadas;

int main() {
	inicializarVariables();
	ingresarNotas();
	calcularPromedio();
	calcularPorcentaje();
	mostrarInforme();
	notasMayores();
return 0;
}

void inicializarVariables() {
	i = 0;
	for(i=0; i<10; i++) {
		vecNotas[i] = 0;
	}
	sumarNotas = 0;
	notasAprobadas= 0;
	totalNotas = 0;
	promedio = 0.0;
	porcentaje = 0.0;
}

void ingresarNotas() {
	for(i=0; i<10; i++) {
		printf("Ingrese nota del alumno %d: ", i+1);
		scanf("%d", &vecNotas[i]);
	}
}

void calcularPromedio() {
	for(i=0; i<10; i++) {
		if(vecNotas[i] >= 6) {
			totalAprobados++;
		    sumarNotas = sumarNotas + vecNotas[i];
		}		
	}
	promedio = sumarNotas / totalAprobados;
}

void calcularPorcentaje() {
	for(i=0; i<10; i++) {
		totalNotas++;
		if(vecNotas[i] >= 6) {
			notasAprobadas++;
		}
	}
	porcentaje = notasAprobadas * 100 / totalNotas;
}

void notasMayores() {
	for(i=0; i<10; i++) {
		if(vecNotas[i] >= 6) {
			printf("\nLa nota del alumno aprobado de la posicion %d es %d\n", i, vecNotas[i]);
		}
	}
}

void mostrarInforme() {
	printf("\n________________________________________________________________\n");
	printf("\nEl promedio de notas de aprobados en la materia es: %.1f", promedio);
	printf("\nEl porcentaje de aprobados es: %.1f%c", porcentaje, 37);
	printf("\n________________________________________________________________\n");
}
