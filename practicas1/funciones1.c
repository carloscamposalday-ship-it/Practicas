#include <stdio.h>

// Intercambia los valores de dos variables enteras
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Calcula la longitud de una cadena sin usar strlen
int longitudCadena(char *cadena) {
    char *ptr = cadena;
    while (*ptr != '\0') {
        ptr++;
    }
    return ptr - cadena;
}
void invertirArreglo(int *arr, int size) {
    int *inicio = arr;
    int *fin = arr + size - 1;
    
    while (inicio < fin) {
        swap(inicio, fin);
        inicio++;
        fin--;
    }
}

// Cuenta números pares en arreglo
int cuentaPares(int *arr, int size) {
    int contador = 0;
    for (int i = 0; i < size; i++) {
        if (*(arr + i) % 2 == 0) {
            contador++;
        }
    }
    return contador;
}