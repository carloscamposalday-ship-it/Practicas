#include <stdio.h>
#include <stdlib.h>

void main() {
    printf("=== Calculadora de Promedio Dinámica ===\n\n");
    int opcion = 0; // opción del menú principal

    // Variable para gestión de memoria dinámica
    double *p = NULL; // puntero al bloque dinámico de calificaciones
    int total = 0;    // contador del total de calificaciones almacenadas

    while (opcion != 2) {
        // Mostrar menú principal
        printf("1) Ingresar calificaciones\n");
        printf("2) Salir\n");
        printf("Seleccione una opcion: ");

        // Validar entrada (evita bucles si se escribe letra o símbolo)
        if (scanf("%d", &opcion) != 1) {
            int c; while ((c = getchar()) != '\n' && c != EOF) {} // limpia búfer
            printf("\nEntrada inválida. Por favor ingrese un número.\n\n");
            opcion = 0;
            continue;
        }
        
       switch (opcion) {
        case 1: {
            // Solicitar cantidad de calificaciones
            int nuevas;
            printf("\n¿Cuántas calificaciones desea ingresar?: ");
            if (scanf("%d", &nuevas) != 1 || nuevas <= 0) {
                int c; while ((c = getchar()) != '\n' && c != EOF) {} // limpia entrada
                printf("Número inválido.\n\n");
                continue;
            }

            // Gestión de memoria dinámica
            if (total == 0) {
                // Primera vez: reservar memoria
                p = (double *)malloc(nuevas * sizeof(double));
            } else {
                // Expandir memoria existente
                p = (double *)realloc(p, (total + nuevas) * sizeof(double));
            }

            // Verificar si la reserva de memoria fue exitosa
            if (p == NULL) {
                printf("Error: No se pudo asignar memoria.\n");
                return;
            }

            // Puntero auxiliar que apunta al primer hueco libre
            double *q = p + total;

            // Captura de calificaciones con notación de punteros (solo 0..10)
            for (int i = 0; i < nuevas; i++) {
                // bucle hasta que se ingrese un double válido en [0,10]
                while (1) {
                    printf("Ingrese la calificación %d (0 a 10): ", total + i + 1);

                    // validar que sea número
                    if (scanf("%lf", (q + i)) != 1) {
                        int c; while ((c = getchar()) != '\n' && c != EOF) {} // limpia
                        printf("Entrada inválida. Intente de nuevo.\n");
                        continue;
                    }

                    // validar rango 0..10
                    if (*(q + i) < 0.0 || *(q + i) > 10.0) {
                        printf("Error: La calificación debe estar entre 0 y 10.\n");
                        continue;
                    }

                    // válido: salir del while(1)
                    break;
                }
            }

            // Actualizar contador total de calificaciones
            total = total + nuevas;

            // Cálculo del promedio usando punteros
            double suma = 0.0;
            double *it = p;          // puntero al inicio
            double *fin = p + total; // puntero al final

            while (it < fin) {
                suma += *it; // sumar el valor apuntado
                it++;        // avanzar al siguiente
            }

            double promedio = suma / total;

            // Mostrar resultados
            printf("\nPromedio: %.2f\n", promedio);
            if (promedio >= 7.0) {
                printf("Estado: Aprobado\n");
            } else {
                printf("Estado: Reprobado\n");
            }
            printf("\n");
            break;
        }

        case 2:
            // Se libera la memoria reservada
            if (p != NULL) {
                free(p);
                p = NULL;
            }

            // Mensaje de despedida
            printf("\nMemoria liberada!!! Hasta luego.\n");
            break;

        default:
            // Opción del usuario inválida
            printf("\n=== Opción inválida ===\nPor favor seleccione una opción del menú.\n\n");
        }
    }
}
