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