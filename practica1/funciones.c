#include <stdio.h>

//Prototipos de funciones
void swap (int *a, int *b);
int longitudCadena ( char * cadena);
  
void invertirArreglo (int *arr , int size);
int cuentaPares (int *arr , int size);

// Definición de swap
void swap (int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Definición de longitudCadena
int longitudCadena (char * cadena) {
  int longitudCadena = 0;
    while(*cadena != '\0') {
        longitudCadena++;
        cadena++;
    }
    return longitudCadena;
}
int main() {
    // Puedes probar aquí tus funciones
    return 0;
}