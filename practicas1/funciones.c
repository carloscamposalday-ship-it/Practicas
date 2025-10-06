#include <stdio.h>

// Intercambia dos enteros
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Calcula la longitud de una cadena
int longitudCadena(char *cadena) {
    char *ptr = cadena;
    while (*ptr != '\0') { // Avanza hasta el final
        ptr++;
    }
    return ptr - cadena; // Diferencia de punteros
}

// Invierte un arreglo de enteros
void invertirArreglo(int *arr, int size) {
    int *inicio = arr;
    int *fin = arr + size - 1;
    while (inicio < fin) {
        swap(inicio, fin); // Intercambia extremos
        inicio++;
        fin--;
    }
}

// Cuenta los pares en un arreglo
int cuentaPares(int *arr, int size) {
    int contador = 0;
    for (int i = 0; i < size; i++) {
        if (*(arr + i) % 2 == 0) { // Si es par
            contador++;
        }
    }
    return contador;
}
