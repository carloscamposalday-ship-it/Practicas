#include <stdio.h>

void main(){
    printf("=== Calculadora de Promedio Dinámica ===\n\n");
    int opcion = 0;

    //Variablespara géstión de memoria dinámica
    double *calificaciones = NULL;  //puntero al arreglo cdinámico de calificaciones
    int total_calificaciones = 0; // Contador del total de calificaciones almacenadas


    while(opcion != 2){
        printf("1) Ingresar calificaciones\n");
        printf("2) Salir\n");
        printf("Seleccione una opcion: ");
        scanf("%i",&opcion);

        switch(opcion){
        case 1:
        {
            char respuesta;
            int continuar = 1;

            do {
                // Preguuntar cuantas calificaciones ingresar
                int nuevas_calificaciones;
                if(total_calificaciones == 0) {
                    printf("\n¿Cuámtas calificaciones desea ingresar? ");
                }else{
                    printf("\n¿Cuántas calificaciones más desa ingresar? ");
                }
                scanf("%d", &nuevas_calificaciones);

                // Validar que el número sea válido
                if(nuevas_calificaciones <= 0) {
                printf("Error: Debe ingresar un número mayor a 0.\n");
                continue; // Volver al inicio del bucle
                }

                //Gestion de memoria dinámica
                int nuevo_total = total_calificaciones + nuevas_calificaciones;
                double *temp;

                if(total_calificaciones == 0) {
                    //Primera vez: reservar memoria con malloc
                    temp = (double*)malloc(nuevo_total * sizeof(double));
                }else{
                    //Expandir memoria existente con realloc
                    temp = (double*)realloc(calificaciones, nuevo_total * sizeof(double));
                }

                //Verificar si la resrva de memoria fue exitosa
                if(temp == NULL) {
                    printf("Error: Nose pudo reservar memoria.\n");
                    break;
                }
                calificaciones = temp;

                //Captura de califiacaciones con validación de rango
                printf("\n");
                for(int i = 0; i < nuevas_calificaciones; i++) {
                    double calificacion;
                    int valida = 0;

                    while(!valida) {
                        printf("Ingrese la calificación %d: ", total_calificaciones + i + 1);
                        scanf("%lf", &calificacion);

                        //Validar que la calificación esté entre 0 y 10
                        if(calificacion >= 0.0 && calificacion <= 10.0) {
                            valida = 1;
                        }else{
                            printf("Error: La calificaición debe estar entre 0 y 10.\n");
                        }
                    }

                    // Almacenar calificación en el arreglo dinámico
                    calificaciones[total_calificaciones + i] = calificacion;
                }

                // Actualizar contador total de calificaciones
                total_calificaciones = nuevo_total;

                //Calculo del promedio
                double suma = 0.0;
                for(int i = 0; i < total_calificaciones; i++) {
                    suma += calificaciones[i];
                }
                double promedio = suma / total_calificaciones;

                //Mostrar resutados: Promedio y Estado
                printf("\nPromedio: %.2f\n", promedio);
                if(promedio >= 7.0) {
                    printf("Estado: Aprobado\n");
                }else{
                }printf("Estado: Reprobado\n");
                

                //Preguntar si desea agregar más calificacines
                printf("\n¿Desea agregar más calificaciones? (s/n): ");
                scanf(" %c", &respuesta);

                // Validar respuesta (solo 's' o 'n' Permitidos)
                while(respuesta != 's' && respuesta != 'n') {
                    printf("Error: Ingrese 's' para si o 'n' para no: ");
                    scanf(" %c", &respuesta);
                }

                continuar = (respuesta == 's');
 
            }while(continuar);
            break;
        }

        case 2:
            //se libera la memoria reservada
            if(calificaciones != NULL) {
                free(calificaciones);
                calificaciones = NULL;
            }

            //mensaje de despedida
            printf("\nMemoria liberada!!! Hasta luego.\n");
            break;
        default:
            //opcion del usuario invalida
            printf("\n=== Opcion invalida === \nPor favor seleccione una opcion del menu:\n");
        }
    }

}
