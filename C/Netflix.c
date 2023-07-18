#include <stdio.h>
#include <string.h>

void datoDeControl();
void ingresarPelicula();
void evaluarPelicula();
void mostrarResultado();

struct netflix {
	int casadosConHijos;
	int drive;
	int bladeRunner;
} r_netflix, v_netflix;

char pelicula, respuesta;

int main() {
	datoDeControl();
	while(respuesta != 'n') {
	ingresarPelicula();
	evaluarPelicula();
	datoDeControl();	
	}
    mostrarResultado();
	return 0;
}

void datoDeControl() {
	printf("\n%cDesea ingresar pelicula? ", 168);
	scanf("%s", &respuesta);
	fflush(stdin);
} 

void ingresarPelicula() {
	printf("\ningrese pelicula:\n1-Blade Runner 2-Drive 3-Casados con hijos ");
	scanf("%d", &pelicula);
}

void evaluarPelicula() {
	switch(pelicula) {
		case 1: 
		printf("\nCuantas personas vieron Blade Runner?: ");
	    scanf("%d", &r_netflix.bladeRunner);
	    break;
	    case 2:
	    printf("\nCuantas personas vieron Drive?: ");
	    scanf("%d", &r_netflix.drive);
	    break;
	    case 3:
	    printf("\nCuantas personas Casados Con Hijos?: ");
	    scanf("%d", &r_netflix.casadosConHijos);	
	    break;
	}
}

void mostrarResultado() {
	int casadosConHijos = r_netflix.casadosConHijos;
    int drive = r_netflix.drive;
    int bladeRunner = r_netflix.bladeRunner;
    printf("\nLa cantidad de personas que vieron Blade Runner son %d", bladeRunner);
    printf("\nLa cantidad de personas que vieron Drive son %d", drive);
    printf("\nLa cantidad de personas que vieron Casados con hijos son %d", casadosConHijos);
}
