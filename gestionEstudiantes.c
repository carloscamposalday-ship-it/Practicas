#include <stdio.h>

typedef struct {
    char nombre[50];
		int matricula;
		double calificaciones[4];
		double promedio;
} Estudiante;

void capturarEstudiante(Estudiante *est);
void calcularPromedio(Estudiante *est);
void mostrarEstudiante(Estudiante est);


int main(){
    Estudiante grupo[4];
		
	printf("=== SISTEMA DE GESTIÓN ACADÉMICA ===\n");
	
	// Capturar datos de 3 estudiantes
	for(int i = 0; i < 4; i++) {
		printf("\nEstudiante %d:\n", i+1);
		capturarEstudiante(&grupo[i]);
	}
	
	// Mostrar todos los estudiantes
	printf("\n=== LISTA COMPLETA DE ESTUDIANTES ===\n");
	for (int i = 0; i < 4; i++) {
		mostrarEstudiante(grupo[i]);
	}
	
	
	// Encontrar el mejor promedio
	int mejorIndex = 0;
	for(int i = 1; i < 4; i++) {
		if(grupo[i].promedio > grupo[mejorIndex].promedio) {
			mejorIndex = i;
		}
	}
	
	
	printf("\n=== ESTUDIANTE CON MEJOR PROMEDIO ===\n");
	printf("Nombre: %s\n", grupo[mejorIndex].nombre);
	printf("Promedio: %.2f\n", grupo[mejorIndex].promedio);
	
	return 0;
}

void capturarEstudiante(Estudiante *est) {
	printf("Ingrese nombre: ");
	scanf("%d", est->nombre);

	printf("Ingrese matrícula: ");
	scanf("%d", &est->matricula);

	for(int i = 0; i < 4; i++) {
		printf("Ingrese calificación %d: ", i+1);
		scanf("%lf", &est->calificaciones[i]);
	}
	calcularPromedio(est);
}

void calcularPromedio(Estudiante *est) {
	// Calcular: suma de calificaciones / 4
	double suma = 0;
	for(int i = 0; i < 4; i++) {
		suma += est->calificaciones[i];
	}
	est->promedio = suma / 4;
}

void mostrarEstudiante(Estudiante est) {
	printf("\n--- Información del Estudiante ---\n");
	//nombre del estudiante
	printf("Nombre: %s\n", est.nombre);
	//matricula del estudiante
	//calificaciones del estudiante 
	//promedio del estudiante
}