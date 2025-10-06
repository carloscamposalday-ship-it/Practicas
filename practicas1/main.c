#include <stdio.h>

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
    invertirArreglo(arreglo, size);
    printf("\nArreglo invertido: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arreglo[i]);
    }
    printf("\n\n");

    return 0;
  } 