#ifndef FUNCIONES_H
#define FUNCIONES_H

// Intercambia valores de dos variables
void swap(int *a, int *b);

// Calcula longitud de cadena sin usar strlen
int longitudCadena(char *cadena);

// Invierte arreglo in-place usando apuntadores
void invertirArreglo(int *arr, int size);

// Cuenta números pares en arreglo
int cuentaPares(int *arr, int size);

#endif