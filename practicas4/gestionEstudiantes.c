#include <stdio.h>

typedef struct {
    char nombre[50];
    // AGREGAR: Campos según el PDF - matricula, calificaciones[4], promedio
    int matricula;
    double calificaciones[4];
    double promedio;
} Estudiante;

// AGREGAR: Prototipos de funciones
void capturarEstudiante(Estudiante *est);
void calcularPromedio(Estudiante *est);
void mostrarEstudiante(Estudiante est);

int main(){
    // MODIFICAR: Arreglo de 4 estudiantes como indica el PDF
    Estudiante grupo[4];
    
    printf("=== SISTEMA DE GESTIÓN ACADÉMICA ===\n");
    
    // MODIFICAR: Capturar datos de 4 estudiantes
    for(int i = 0; i < 4; i++) {
        printf("\nEstudiante %d:\n", i+1);
        capturarEstudiante(&grupo[i]);
    }
    
    // Mostrar todos los estudiantes
    printf("\n=== LISTA COMPLETA DE ESTUDIANTES ===\n");
    // AGREGAR: Mostrar información de todos los estudiantes
    for(int i = 0; i < 4; i++) {
        mostrarEstudiante(grupo[i]);
    }
    
    // Encontrar el mejor promedio
    int mejorIndex = 0;
    // AGREGAR: Encontrar el índice del estudiante con mejor promedio
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
    // AGREGAR: Implementación de captura de datos
    printf("Ingrese nombre: ");
    scanf("%s", est->nombre);
    
    printf("Ingrese matrícula: ");
    scanf("%d", &est->matricula);
    
    // AGREGAR: Capturar 4 calificaciones
    for(int i = 0; i < 4; i++) {
        printf("Ingrese calificación %d: ", i+1);
        scanf("%lf", &est->calificaciones[i]);
    }
    
    // Llamar a función para calcular promedio
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
    // AGREGAR: Mostrar información del estudiante
    //nombre del estudiante
    printf("Nombre: %s\n", est.nombre);
    //matricula del estudiante
    printf("Matrícula: %d\n", est.matricula);
    //calificaciones del estudiante
    printf("Calificaciones: ");
    for(int i = 0; i < 4; i++) {
        printf("%.2f ", est.calificaciones[i]);
    }
    //promedio del estudiante
    printf("\nPromedio: %.2f\n", est.promedio);
}