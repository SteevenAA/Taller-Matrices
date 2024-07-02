#include <stdio.h>

// Función para imprimir la matriz original
void imprimirMatrizOriginal(int filas, int columnas, int matriz[filas][columnas]) {
    printf("Matriz Original:\n");
    for (int i = 0; i < filas; i++) {
        printf("|");
        for (int j = 0; j < columnas; j++) {
            printf(" %d |", matriz[i][j]);
        }
        printf("\n");
    }
}

// Función para imprimir la matriz resultante sin los elementos de las esquinas
void imprimirMatrizModificada(int filas, int columnas, int matriz[filas][columnas]) {
    printf("Matriz Modificada:\n");
    for (int i = 0; i < filas; i++) {
        printf("|");
        for (int j = 0; j < columnas; j++) {
            if ((i == 0 && j == 0) || (i == 0 && j == columnas - 1) ||
                (i == filas - 1 && j == 0) || (i == filas - 1 && j == columnas - 1)) {
                printf("   |");
            } else {
                printf(" %d |", matriz[i][j]);
            }
        }
        printf("\n");
    }
}

int main() {
    int filas, columnas;

    printf("Programa para imprimir matrices excluyendo los elementos de las esquinas (solo para matrices cuadradas).\n");

    // Solicitar número de filas
    printf("Ingrese el número de filas de la matriz: ");
    scanf("%d", &filas);
    if (filas <= 0) {
        printf("Error: el número de filas debe ser un número natural.\n");
        return 1;
    }

    // Solicitar número de columnas
    printf("Ingrese el número de columnas de la matriz: ");
    scanf("%d", &columnas);
    if (columnas <= 0) {
        printf("Error: el número de columnas debe ser un número natural.\n");
        return 1;
    }

    // Definir y llenar la matriz
    int matriz[filas][columnas];
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            printf("Ingrese el valor para la posición [%d][%d]: ", i, j);
            scanf("%d", &matriz[i][j]);
        }
    }

    // Imprimir la matriz original
    imprimirMatrizOriginal(filas, columnas, matriz);

    // Verificar si la matriz es cuadrada y, en ese caso, imprimir la matriz modificada
    if (filas == columnas) {
        imprimirMatrizModificada(filas, columnas, matriz);
    } else {
        printf("Error: la matriz ingresada no es cuadrada.\n");
    }

    return 0;
}