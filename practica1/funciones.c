#include <stdio.h>

//Prototipos de funciones
void swap (int *a, int *b);
int longitudCadena ( char * cadena);
  
void invertirArreglo (int *arr , int size);
int cuentaPares (int *arr , int size);

// Test swap
void swap (int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Test longitudCadena
int longitudCadena (char * cadena) {
  int longitudCadena = 0;
    while(*cadena != '\0') {
        longitudCadena++;
        cadena++;
    }
    return longitudCadena;
}

// Tes InvertirArreglo
void invertirArreglo (int *arr, int size) {
  int *inicio = arr;
  int *fin = arr + size - 1;

  while(inicio < fin) {
    int temp = *inicio;
    *inicio = *fin;
    *fin = temp;
    inicio++;
    fin--;
  }
}

int main() {
    // Puedes probar aquí tus funciones

    return 0;
}