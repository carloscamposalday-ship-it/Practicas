#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Punteros dobles globales para el inventario
char **nombresProductos = NULL;
int *cantidades = NULL;
double *precios = NULL;
int totalP = 0;

//Declaraciones de funciones
int agregarProducto();
void mostrarProductos();
double calcularValorTotalInventario();
void liberarInventario();
void llenarInventarioInicial();
void buscarProducto();
void actualizarStock();

int main() {
    int opcion;

    printf("=== SISTEMA DE INVENTARIO ===\n");

    // Llenar inventario con datos de ejemplo (usar la tabla proporcionada)
    llenarInventarioInicial();

    // Menú interactivo
    do {
        printf("\n--- MENU PRINCIPAL ---\n");
        printf("1. Agregar producto\n");
        printf("2. Mostrar inventario\n");
        printf("3. Calcular valor total del inventario\n");
        printf("4. Buscar producto por nombre\n");
        printf("5. Actualizar stock\n");
        printf("6. Salir\n");
        printf("Seleccione opcion: ");
        scanf("%d", &opcion);

        switch(opcion) {
            case 1:
            //agregar producto
            if (agregarProducto()) {
                printf("Producto agregado exitosamente.\n");
            }else{
                printf("Error al agregar el producto.\n");
            }
            break;
            case 2:
            //muestra todo el inventario
            mostrarProductos();
            break;
            case 3:
            //calcula el valor total del inventario
            printf("valor total inventario: $%.2f\n", calcularValorTotalInventario());
            break;
            case 4:
            // Buscar producto por nombre o número
            buscarProducto();
            break;
            case 5:
            // Actualizar stock
            actualizarStock();
            break;
            case 6:
            printf("Saliendo del sistema...\n");
            break;
            default:
            printf("Opcion invalida.\n");
        }
    } while(opcion != 6);

    // Liberar memoria antes de salir
    liberarInventario();
    return 0;
}

// Función para llenar el inventario incial
void llenarInventarioInicial() {
    // Datos de la tabla usando solo punteros
    char *nombresBase = (char*)malloc(256 * sizeof(char));
    strcpy(nombresBase, "Laptop HP");
    strcpy(nombresBase + 20, "Mouse Inalambrico");
    strcpy(nombresBase + 40, "Teclado Mecanico");
    strcpy(nombresBase + 60, "Camisa Casual");
    strcpy(nombresBase + 80, "Jeans");
    strcpy(nombresBase + 100, "Zapatos Deportivos");
    strcpy(nombresBase + 120, "Arroz");
    strcpy(nombresBase + 140, "Frijol");
    strcpy(nombresBase + 160, "Aceite");

    int *cantsBase = (int*)malloc(9 * sizeof(int));
    *(cantsBase + 0) = 5;
    *(cantsBase + 1) = 15;
    *(cantsBase + 2) = 8;
    *(cantsBase + 3) = 20;
    *(cantsBase + 4) = 12;
    *(cantsBase + 5) = 10;
    *(cantsBase + 6) = 50;
    *(cantsBase + 7) = 40;
    *(cantsBase + 8) = 30;

     double *preciosBase = (double*)malloc(9 * sizeof(double));
    *(preciosBase + 0) = 1200.00;
    *(preciosBase + 1) = 25.50;
    *(preciosBase + 2) = 75.00;
    *(preciosBase + 3) = 35.00;
    *(preciosBase + 4) = 45.00;
    *(preciosBase + 5) = 60.00;
    *(preciosBase + 6) = 2.50;
    *(preciosBase + 7) = 3.00;
    *(preciosBase + 8) = 4.50;

    // Insertar productos usando agregarProducto (simulado)
    int i = 0;
    while (i < 9) {
        // Re - asignar memoria
        char **tempNombres = (char**)realloc(nombresProductos, (totalP + 1) * sizeof(char*));
        int *tempCantidades = (int*)realloc(cantidades, (totalP + 1) * sizeof(int));
        double *tempPrecios = (double*)realloc(precios, (totalP + 1) * sizeof(double));

        if (tempNombres == NULL || tempCantidades == NULL || tempPrecios == NULL) {
            printf("Error de memoria.\n");
            return;
        }

        nombresProductos = tempNombres;
        cantidades = tempCantidades;
        precios = tempPrecios;

        // Asignar memoria para el nombre
        *(nombresProductos + totalP) = (char*)malloc((strlen(nombresBase + (i * 20)) + 1) * sizeof(char));
        if (*(nombresProductos + totalP) == NULL) {
            printf("Error de memoria para nombre.\n");
            return;
        }
        strcpy(*(nombresProductos + totalP), nombresBase + (i * 20));

        // Asignar memoria para cantidad y precio
        *(cantidades + totalP) = *(cantsBase + i);
        *(precios + totalP) = *(preciosBase + i);

        totalP = totalP + 1;
        i = i + 1;
    }
    // Liberar memoria temporal
    free(nombresBase);
    free(cantsBase);
    free(preciosBase);
}

int agregarProducto() {
    // Re-Asignar memoria exacta para el nombre y copiarlo
    char nombreTemp[100];
    int cantidadTemp;
    double precioTemp;

    // Pedir los datos del producto
    printf("\n=== Agregar Producto ===\n");
    printf("Nombre: ");
    // Leer nombre completo con espacios hasta el salto de linea
    // El espacio inicial consume cualquier newline pendiente
    // %99[^\n] lee hasta el final de la línea (máx 99 caracteres)
    scanf(" %99[^\n]", nombreTemp);
    printf("Cantidad: ");
    scanf("%d", &cantidadTemp);
    printf("Precio: ");
    scanf("%lf", &precioTemp);

    // Re-Asignar cantidad y precio en las matrices correspondientes
    char **tempNombres = (char**)realloc(nombresProductos, (totalP + 1) * sizeof(char*));
    int *tempCantidades = (int*)realloc(cantidades, (totalP + 1) * sizeof(int));
    double *tempPrecios = (double*)realloc(precios, (totalP + 1) * sizeof(double));

    // Verificar que cada realloc fue exitoso
    if (tempNombres == NULL || tempCantidades == NULL || tempPrecios == NULL) {
        printf("Error: No se pudo asignar memoria.\n");
        return 0;
    }
    nombresProductos = tempNombres;
    cantidades = tempCantidades;
    precios = tempPrecios;

    // Re-Asignar cantidad y precio en las matrices correspondientes
    *(nombresProductos + totalP) = (char*)malloc((strlen(nombreTemp) + 1) * sizeof(char));
    if (*(nombresProductos + totalP) == NULL) {
        printf("Error: No se pudo asignar memoria para el nombre.\n");
        return 0;
    }

    // Usar strcpy para copiar el nombre del producto
    strcpy(*(nombresProductos + totalP), nombreTemp);

    // Asignar los valores de cantidad y precio en las matrices
    *(cantidades + totalP) = cantidadTemp;
    *(precios + totalP) = precioTemp;

    // Si todo sale bien, retornar 1
    totalP = totalP + 1;
    return 1;
}

void mostrarProductos() {
    printf("=== Productos %d ===\n", totalP);
    // Recorrer todos los productos he imprimirlos
    int i = 0;
    while (i < totalP) {
        // Mostrar: Posición, Nombre, Cantidad, Precio, Valor total
        double valorTotal = (*(cantidades + i)) * (*(precios + i));
        printf("Pos %d: %s - Cant: %d - Precio: $%.2f - Valor: $%.2f\n", 
               i, *(nombresProductos + i), *(cantidades + i), *(precios + i), valorTotal);
        i = i + 1;
    }
}

double calcularValorTotalInventario() {
    double total = 0;
    // Recorrer todos los productos de la categoría
    int i = 0;
    while (i < totalP) {
        // Sumar: cantidad * precio para cada producto
        total = total + (*(cantidades + i)) * (*(precios + i));
        i = i + 1;
    }
    return total;
}

void buscarProducto() {
    char entrada[100];
    int encontrado = 0;
    
    printf("\n--- Buscar Producto ---\n");
    printf("Ingrese nombre, parte del nombre o numero de posicion (0-%d): ", totalP - 1);
    scanf(" %99[^\n]", entrada);

    // Verificar si la entrada es un número
    int esNumero = 1;
    char *ptr = entrada;
    while (*ptr != '\0') {
        if (!isdigit(*ptr)) {
            esNumero = 0;
            break;
        }
        ptr = ptr + 1;
    }

    if (esNumero) {
        // Búsqueda por número de posición
        int posicion = atoi(entrada);
        if (posicion >= 0 && posicion < totalP) {
            double valorTotal = (*(cantidades + posicion)) * (*(precios + posicion));
            printf("ENCONTRADO POR POSICION %d: %s - Cant: %d - Precio: $%.2f - Valor: $%.2f\n", 
                   posicion, *(nombresProductos + posicion), *(cantidades + posicion), *(precios + posicion), valorTotal);
            encontrado = 1;
        } else {
            printf("Error: Posicion %d fuera de rango. El rango valido es 0-%d.\n", posicion, totalP - 1);
        }
    } else {
        // Búsqueda por nombre
        int i = 0;
        while (i < totalP) {
            // Usar strstr para buscar la subcadena (case insensitive)
            if (strstr(*(nombresProductos + i), entrada) != NULL) {
                double valorTotal = (*(cantidades + i)) * (*(precios + i));
                printf("ENCONTRADO POR NOMBRE: Pos %d - %s - Cant: %d - Precio: $%.2f - Valor: $%.2f\n", 
                       i, *(nombresProductos + i), *(cantidades + i), *(precios + i), valorTotal);
                encontrado = 1;
            }
            i = i + 1;
        }
    }

    if (!encontrado && !esNumero) {
        printf("No se encontraron productos con el nombre o parte del nombre '%s'.\n", entrada);
    }
}

void actualizarStock() {
    int posicion;
    int nuevaCantidad;

    printf("\n=== Actualizar Stock ===\n");
    printf("Ingrese la posicion del producto a actualizar (0-%d): ", totalP - 1);
    scanf("%d", &posicion);

    if (posicion < 0 || posicion >= totalP) {
        printf("Error: Posicion invalida.\n");
        return;
    }

    printf("Producto actual: %s - Stock: %d\n", *(nombresProductos + posicion), *(cantidades + posicion));
    printf("Ingrese la nueva cantidad: ");
    scanf("%d", &nuevaCantidad);

    if (nuevaCantidad < 0) {
        printf("Error: La cantidad no puede ser negativa.\n");
        return;
    }

    *(cantidades + posicion) = nuevaCantidad;
    printf("Stock actualizado correctamente.\n");
}

void liberarInventario() {
    // Liberar memoria en orden inverso
    int i = 0;
    while (i < totalP) {
        // Primero liberar cada array interno
        free(*(nombresProductos + i));
        i = i + 1;
    }
    // Luego liberar los arrays principales
    free(nombresProductos);
    free(cantidades);
    free(precios);
    // Reinicia punteros y contador
    nombresProductos = NULL;
    cantidades = NULL;
    precios = NULL;
    totalP = 0;
    
    printf("Memoria liberada correctamente.\n");
}