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
    int numCalificaciones = 0;   // Número de calificaciones a ingresa
    

    // Blucle principal del menú: sigue hast que el usuario elija salir (2)
    while (opcion != 2)
    {
        printf("1) Ingresar calificaciones\n");
        printf("2) Salir\n");
        printf("Seleccione una opcion: ");
        if (scanf("%i", &opcion) != 1)
        {
            printf("\n=== Entrada invalida === \nPor favor seleccione una opcion del menu:\n");
            limpiarBuffer(); // Limpiar el búfer de entrada para evitar problemas en la siguiente lectura
            continue;      // Volver al inicio del bucle para pedir la opción nuevamente
        }

        // Desde aquí se maneja la opción seleccionada por el usuario
        switch (opcion)
        {
        case 1:
        {
            //Este bloque permite ingresar calificaciones en un ciclo
            //Alfinal preguntar si desea ingresar mas calificaciones
            char continuar = 's';
            do
            {
                int nuevasCalificaciones = 0; //Cuántas se agregará en esta iteración
                
                //Mensaje distinto si es la primera captura o si ya hay calificaciones
                if (numCalificaciones == 0)
                    printf("\n¡Cuántas calificaciones desea ingresar ahora? ");
                else
                    printf("\nCuántas calificaficaicones más deseas agragar ahora? ");

                // Leemos cuántas agragará y validamos que sea número > 0
                if (scanf("%d", &nuevasCalificaciones) != 1 || nuevasCalificaciones <= 0) {
                    printf("\n== Entradas invalidas == \nPor favor ingrese un numero valido de calificaciones.\n");
                    limpiarBuffer(); // Limpiar el búfer de entrada para evitar problemas en la siguiente lectura
                    continue; //Reiniciar el ciclo do

                }

                // ===Reserva o redimensión de memoria dinámica===
                // nuevoTotal = califs que ya teniamos + la nuevas a agrgar
                size_t nuevoTotal = (size_t)numCalificaciones + (size_t)nuevasCalificaciones;

                // temp será el puntero temporal de la reserva/redimensión
                float *temp = NULL;

                if (numCalificaciones = 0) {
                    //Prmera vez: pedimos un bloque con malloc para 'nuevoTotal' flotantes
                    temp = (float*)malloc(nuevoTotal + sizeof(float));

                }else {
                    //Ya hay datos capturados: ampliamos el bloque existente con realloc
                    temp = (float*)realloc(calificaciones, nuevoTotal * sizeof(float));
                }

                // Validamos que la reserva/redimensión haya sido exitosa
                if (temp == NULL) {
                    // Si malloc/ralloc falla, No tocamos 'Califiaciones' y mostramos error
                    printf("\n=== Error de memoria === \nNose ha podido reservar memorria.\n");
                    break; //Salimos al menú por seguridad
                }

                // Si todo va bien, ahora 'Calificaciones' apunta al bloque actualizado
                calificaciones = temp;

                // Guardamos desde el indice en el que nos quedamos
                int baseIndex = nuevasCalificaciones;

                // ===Camputara de Calificaicones (con validación 0..10) ===
                for (int i = 0; i < nuevasCalificaciones; ++i) {
                {
                        float val = 0.0f; // aquí se guada cada calificación tecleada
                        int ok = 0;  //bandera de validación

                        do {
                                printf("Ingresa la calificacion %d: ", baseIndex + i +1);
                                // Validamos que sea número
                                if (scanf("%f", &val) != 1) {
                                        limpiarBuffer();  //Limpiamos basura (ej: letras)
                                        printf("== Entrada invalida == \nPor favor ingrese un numero valido entre 0 y 10.\n");
                                        continue; //volvemos a pedir la calificación
                                }

                                //Validamos rango [0..10]
                                if(val < 0.0f || val > 10.00f) {
                                    printf("=== Fuera de rango === \nPor favor ingresa1 un numero entre 0 y 10.\n");
                                    continue; //Volvemos a pedir la calificaión i 
                                }
                                
                                ok = 1; //Si llega aquí, la calificaión es válida
                            
                        } while (ok == 0); //Repetir hasta que la calificación sea válida

                        // Guardamos la calificación en el arreglo dinámico
                  
                    }

                }
                // Actualizamos el total acumulado (ya que agregamos 'nuevasCalificaciones')



            
                


                    
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
