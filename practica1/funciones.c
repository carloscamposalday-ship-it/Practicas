#include <stdio.h>

//Prototipos de funciones
void swap (int *a, int *b);
int longitudCadena ( char * cadena);
void invertirArreglo (int *arr , int size);
int cuentaPares (int *arr , int size);

// Funcion swap
void swap (int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Funcion longitudCadena
int longitudCadena (char * cadena) {
  int longitudCadena = 0;
    while(*cadena != '\0') {
        longitudCadena++;
        cadena++;
    }
    return longitudCadena;
}

// Funcion invertirArreglo
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

// Funcion cuentaPares
int cuentaPares(int *arr, int size) {
  int contador = 0;
  for(int i = 0; i < size; i++) {
    if(*(arr + i) % 2 == 0) {
      contador++;
    }
  }
  return contador;
}
int main() {
    // Puedes probar aquí tus funciones
    

    return 0;
}