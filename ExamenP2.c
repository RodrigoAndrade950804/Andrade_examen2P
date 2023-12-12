#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define InsumosMaximos 2
#define MesesDelAño 12

// Arreglos para almacenar los datos de ingresos y egresos
char nombres[InsumosMaximos][1];
int ingresos[InsumosMaximos][MesesDelAño];
int egresos[InsumosMaximos][MesesDelAño];

// Función para imprimir el detalle de ingresos y egresos por mes
void imprimirDetalle() {
    int total = 0;
    for (int i = 0; i < InsumosMaximos; i++) {
        printf("Insumo: %s\n", nombres[i]);
        for (int j = 0; j < MesesDelAño; j++) {
            if (ingresos[i][j] >= egresos[i][j])
            {
            total =ingresos[i][j] - egresos[i][j]; 
            }else{
            total = 0;
            }
            printf("Mes %d - Ingresos: %d, Egresos: %d, Resultante: %d \n", j + 1, ingresos[i][j], egresos[i][j], total);
            
        }
        printf("\n");
    }
}

// Función para obtener y mostrar el total de ingresos y egresos por insumo en todo el año.
void obtenerTotales() {
    for (int i = 0; i < InsumosMaximos; i++) {
        int totalIngresos = 0, totalEgresos = 0, total;
        for (int j = 0; j < MesesDelAño; j++) {
            totalIngresos += ingresos[i][j];
            totalEgresos += egresos[i][j];
            if (totalIngresos >= totalEgresos)
            {                
            total = totalIngresos - totalEgresos;
            }else{
            total = 0;
            }
            
        }
        printf("Insumo: %s - Total Ingresos: %d, Total Egresos: %d, Total resultante: %d\n", nombres[i], totalIngresos, totalEgresos, total);
    }
}

int main() {
    srand(time(NULL));
    // Inicialización de datos (puedes modificar esta parte según tus necesidades)
    for (int i = 0; i < InsumosMaximos; i++) {
        printf("Ingrese el nombre del insumo %d: ", i + 1);
        scanf("%s", nombres[i]);

        for (int j = 0; j < MesesDelAño; j++) {

            ingresos[i][j] = rand() % 100 + 1;
            printf("Ingresos del insumo %d para el mes %d: %d \n", i + 1, j + 1, ingresos[i][j]);

            egresos[i][j] = rand() % 100 + 1;
            printf("Egresos del insumo %d para el mes %d: %d \n", i + 1, j + 1, egresos[i][j]);
            
        }
    }

    int opcion;
    printf("\nElija una opción:\n");
    printf("1) Imprimir detalle de ingresos y egresos por mes en el año.\n");
    printf("2) Obtener total de ingresos y egresos por insumo en todo el año.\n");
    scanf("%d", &opcion);

    switch (opcion) {
        case 1:
            imprimirDetalle();
            break;
        case 2:
            obtenerTotales();
            break;
        default:
            printf("Opción no válida.\n");
            break;
    }

    return 0;
}
