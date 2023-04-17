#include <stdio.h> 
#include <math.h>

void inicializarVariables();
void ingresarDatos();
void calcularArea();
void mostrarResultados();

float radio, PI, area;
int cantidadDeCircunferencias;

int main(){
	inicializarVariables();
	ingresarDatos();
	calcularArea();
	mostrarResultados();
	
	return 0;
}

void inicializarVariables() {
	radio  = 0;
	area = 0;
	cantidadDeCircunferencias = 0;
	PI = 3,1415;
}

void ingresarDatos() {
	printf("Ingrese el valor del radio \n");
	scanf("%f", &radio);
	printf("Ingrese cantidad de circunferencias \n");
	scanf("%d", &cantidadDeCircunferencias);
}

void calcularArea() {
	area = (PI *(radio * radio));
	printf("El area es:", cantidadDeCircunferencias , area, PI);
}

void mostrarResultados() {
	printf("El area es %.2f m \n El ancho es %.2f m \n la cantidad de figuras es %d m", area, cantidadDeCircunferencias);
};



