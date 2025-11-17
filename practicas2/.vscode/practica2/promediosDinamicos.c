#include <stdio.h>      // Librería estándar para entrada/salida (printf, scanf)
#include <stdlib.h>     // Librería para memoria dinámica (malloc, realloc, free)

int main(void) {        // Punto de entrada del programa
    printf("=== Calculadora de Promedio Dinámica (Punteros) ===\n\n");

    int opcion = 0;                 // Variable para la opción del menú
    double *p = NULL;               // Puntero que almacenará las calificaciones dinámicamente
    int total = 0;                  // Total de calificaciones almacenadas

    while (opcion != 2) {           // Bucle principal: se repite hasta que la opción sea 2
        // === MENÚ PRINCIPAL ===
        printf("1) Ingresar calificaciones\n");
        printf("2) Salir\n");
        printf("Seleccione una opcion: ");

        // === VALIDACIÓN DE ENTRADA ===
        // Si el usuario mete una letra o símbolo, limpia el búfer y vuelve al inicio
        if (scanf("%d", &opcion) != 1) {
            int c; 
            while ((c = getchar()) != '\n' && c != EOF) {}   // Limpia la entrada
            printf("\nEntrada inválida. Intente de nuevo.\n\n");
            opcion = 0;  // Reinicia la opción
            continue;    // Vuelve al menú
        }

        // === CONTROL DE OPCIONES ===
        switch (opcion) {

        // === CASO 1: Ingresar calificaciones ===
        case 1: {
            int n;  // Cantidad de calificaciones nuevas
            printf("\n¿Cuántas calificaciones desea ingresar?: ");
            
            // Validar que el número sea mayor a 0
            if (scanf("%d", &n) != 1 || n <= 0) {
                int c; while ((c = getchar()) != '\n' && c != EOF) {} // Limpia la entrada
                printf("Número inválido.\n\n");
                continue;  // Regresa al menú
            }

            // === RESERVA O EXPANSIÓN DE MEMORIA DINÁMICA ===
            // malloc: primera vez / realloc: ampliar espacio existente
            double *tmp = (total == 0)
                        ? (double*)malloc((size_t)n * sizeof(double)) 
                        : (double*)realloc(p, (size_t)(total + n) * sizeof(double));

            // Verificar si malloc/realloc falló
            if (!tmp) {
                printf("Error: no se pudo asignar memoria.\n");
                free(p);   // Libera memoria previa si existe
                return 1;  // Termina el programa con error
            }

            p = tmp; // Actualiza el puntero principal (por si realloc movió la memoria)

            // === PUNTERO AL PRIMER ESPACIO LIBRE ===
            double *q = p + total; // q apunta a la siguiente posición libre de memoria

            // === CAPTURA DE CALIFICACIONES ===
            for (int i = 0; i < n; i++) {
                while (1) { // Bucle hasta que se ingrese un número válido en el rango
                    printf("Ingrese la calificación %d (0 a 10): ", total + i + 1);

                    // Leer valor directamente en la dirección (q + i)
                    if (scanf("%lf", (q + i)) != 1) {
                        int c; while ((c = getchar()) != '\n' && c != EOF) {}
                        printf("Entrada inválida.\n");
                        continue; // Reintentar
                    }

                    // Validar rango permitido
                    if (*(q + i) < 0.0 || *(q + i) > 10.0) {
                        printf("Debe estar entre 0 y 10.\n");
                        continue; // Reintentar
                    }
                    break; // Salir si la calificación es válida
                }
            }

            // === ACTUALIZAR TOTAL DE CALIFICACIONES ===
            total += n; // Sumar las nuevas al total general

            // === CALCULAR PROMEDIO USANDO PUNTEROS ===
            double suma = 0.0;                         // Reinicia suma
            for (double *it = p, *fin = p + total; it < fin; it++) {
                suma += *it;                           // *it: valor apuntado
            }

            double prom = suma / (double)total;        // Calcular promedio final

            // === MOSTRAR RESULTADOS ===
            printf("\nPromedio: %.2f\n", prom);
            printf("Estado: %s\n\n", (prom >= 7.0) ? "Aprobado" : "Reprobado");
            break; // Termina case 1
        }

        // === CASO 2: Salir ===
        case 2:
            // Liberar memoria antes de salir
            if (p) { 
                free(p);   // Libera el bloque de memoria dinámica
                p = NULL;  // Evita que el puntero quede colgando
            }
            printf("\nMemoria liberada. Hasta luego.\n");
            break;

        // === CUALQUIER OTRA OPCIÓN ===
        default:
            printf("\n=== Opción inválida ===\nPor favor seleccione una opción válida.\n\n");
        }
    }

    return 0; // Fin correcto del programa
}
