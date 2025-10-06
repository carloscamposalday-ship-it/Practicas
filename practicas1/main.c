#include <stdio.h>
#include "funciones.h"

void swap(int *a, int *b);
int longitudCadena(char *cadena);
void invertirArreglo(int *arr, int size);
int cuentaPares(int *arr, int size);

int main() {
    printf("=== Prueba de funciones ===\n");
    
    // Prueba swap
    int a = 5, b = 10;
    printf("Antes swap: a=%d, b=%d\n", a, b);
    swap(&a, &b);
    printf("Despues swap: a=%d, b=%d\n\n", a, b);
    
    // Prueba longitudCadena
    char cadena[] = "Hola Mundo";
    printf("Cadena: '%s'\n", cadena);
    printf("Longitud: %d\n\n", longitudCadena(cadena));
    
    // Prueba invertirArreglo
    int arreglo[] = {1, 2, 3, 4, 5};
    int size = 5;
    printf("Arreglo original: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arreglo[i]);
    }

    printf("\n"); // <-- Aquí va el salto de línea

    invertirArreglo(arreglo, size);
    printf("\nArreglo invertido: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arreglo[i]);
    }
    printf("\n\n");

        
    // Prueba cuentaPares
    int numeros[] = {1, 2, 3, 4, 5, 6, 7, 8};
    int tam = 8;
    printf("Numeros: ");
    for (int i = 0; i < tam; i++) {
        printf("%d ", numeros[i]);
    }
    printf("\nPares encontrados: %d\n", cuentaPares(numeros, tam));
    
    return 0;
}

  