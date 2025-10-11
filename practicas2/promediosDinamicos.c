#include <stdio.h>
#include <stdlib.h> //Libreria para manejo de momrria dinamica

/**
 * Función: limpiarBuffer
 * -----------------------
 * Elimina los caracteres restantes en el búfer de entrada (stdin)
 * después de usar funciones como scanf().
 *
 * Esto evita que queden saltos de línea ('\n') u otros caracteres
 * pendientes que puedan afectar las siguientes lecturas con getchar()
 * o scanf().
 */
void limpiarBuffer(void)
{
    int c; // Variable para almacenar temporalmente cada carácter leído

    // Mientras el carácter leído no sea un salto de línea ('\n')
    // ni el final de archivo (EOF), sigue leyendo y descartando
    // los caracteres que estén pendientes en el búfer de entrada.
    while ((c = getchar()) != '\n' && c != EOF)
    {
        // No hacemos nada dentro del ciclo: solo leemos para vaciar el búfer
    }
}
void main()
{
    printf("=== Calculadora de Promedio Dinámica ===\n\n");
    int opcion = 0;

    /* -------------------------------------------------------------------
    Variables Dinámicas (Reservar memoria en tiempo de ejecución):
    -Calificaciones: arreglo dinámico para amacenar las calificaciones
    -numCalificaciones: número de calificaiones a ingresar
    -------------------------------------------------------------------*/

    float *calificaciones = NULL; // Puntero para el arreglo dináminco
    int numCamlificaciones = 0;   // Número de calificaciones a ingresar

    while (opcion != 2)
    {
        printf("1) Ingresar calificaciones\n");
        printf("2) Salir\n");
        printf("Seleccione una opcion: ");
        if (scanf("%i", &opcion) != 1)
        {
            printf("\n=== Entrada invalida === \nPor favor seleccione una opcion del menu:\n");
            limpiarBuffer(); // Limpiar el búfer de entrada para evitar problemas en la siguiente lectura
            continue;        // Volver al inicio del bucle para pedir la opción nuevamente
        }

        switch (opcion)
        {
        case 1:

            /*-------------------------------------------------------------------
            Flujo principal para capturar calificaciones de forma incremetal.
            Cumple con:
            -Pregunta n (o "¿Cuántas más?").
            -Usa malloc/realloc según corresponda.
            -Valida cada calificacion (0,10).
            -Calcula y muestra el promedio actualizado.
            -Indicar Aprobado/Reprobado (mínimo 7.0).
            -Preguntar si desea agragar más (s/n).
            ----------------------------------------------------------------------*/
            char continuar = 's'; // Variable para controlar si se agraga más calificaciones
            do
            {
                int nuevasCalificaciones = 0; // Número de calificaciones a agregar en esta iteración

                if (numCamlificaciones == 0)
                    printf("\n¿Cuántas calificaciones desea ingresar ahora? ");
                else
                    printf("\nCuántas calificaciones más desea agragar ahora? ");

                if(scanf("%d", &nuevasCalificaciones) != 1 || nuevasCalificaciones <= 0) {
                    printf("\n=== Entrada invalida === \nPor favor ingrese un número válido de calificaciones.\n");
                    limpiarBuffer(); // Limpiar el búfer de entrada para evitar problemas en la siguiente lectura
                    continue; // Volver al inicio del bucle para pedir el número nuevamente
                }
            }

        case 2:
            // se libera la memoria reservada

            // mensaje de despedida
            printf("\nMemoria liberada!!! Hasta luego.\n");
            break;
        default:
            // opcion del usuario invalida
            printf("\n=== Opcion invalida === \nPor favor seleccione una opcion del menu:\n");
        }
    }
}
