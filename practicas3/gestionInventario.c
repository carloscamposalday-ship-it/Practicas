#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Punteros dobles globales para el inventario
char **nombresProductos = NULL;
int *cantidades = NULL;
double *precios = NULL;
int totalP = 0;

//Declaraciones de funciones
int agregarProducto();
void mostrarProductos();
double calcularValorTotoalInventario();
void liberarInventario();
void llenarInventarioInicial();

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
        printf("4. Salir\n");
        printf("Seleccione opcion: ");
        scanf("%d", &opcion);

        switch(opcion) {
            case 1:
            //agregar producto
            if (agregarProducto()) {
                printf("Producto agragado exitosamente.\n");
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
            printf("valor total inventario: $%.2f\n", calcularValorTotoalInventario());
            break;
            case 4:
            printf("Saliendo del sistema...\n");
            break;
            default:
            printf("Opcion invalida.\n");
        }
    } while(opcion != 4);

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

    for (int i = 0; i < 9; i++) {
        // Reasiganar memoria(
        char **tempNombres = (char**)realloc(nombresProductos, (totalP + 1) + sizeof(char*));
        int *tempCantidades = (int*)realloc(cantidades, (totalP + 1) * sizeof(int));
        double *tempPrecios = (double*)realloc(precios, (totalP + 1) + sizeof(double));

        if(tempNombres == NULL || tempCantidades == NULL || tempPrecios == NULL) {
            printf("Error de memoria.\n");
            return;
        }

        nombresProductos = tempNombres;
        cantidades = tempCantidades;
        precios = tempPrecios;

        // Asignar memoria para el nombre
        *(nombresProductos + totalP) = (char*)malloc((strlen(nombresBase + (i * 20)) + 1) * sizeof(char));
        if(*(nombresProductos + totalP) == NULL) {
            printf("Error de memoria para nombre.\n");
            return;
        }
        

    }
}

int agregarProducto() {
    // Re-Asignar memoria exacta para el nombre y copiarlo
	// Re-Asignar cantidad y precio en las matrices correspondientes
	// Pedir los datos del producto
}

void mostrarProductos() {
	printf("=== Productos %d ===\n", numProductos);
	// Recorrer todos los productos he imprimirlos
	// Mostrar: Posición, Nombre, Cantidad, Precio, Valor total
}

double calcularValorTotalInventario() {
	double total = 0;
	// Recorrer todos los productos de la categoría
	// Sumar: cantidad * precio para cada producto
	return total;
}

void liberarInventario() {
	// Liberar memoria en orden inverso
	// Primero liberar cada array interno
	// Luego liberar los arrays principales
}
