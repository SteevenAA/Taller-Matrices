#include <stdio.h>

void mostrarMatrizOriginal(int filas, int columnas, int matriz[filas][columnas]) {
    printf("Matriz Original:\n");
    for (int i = 0; i < filas; i++) {
        printf("|");
        for (int j = 0; j < columnas; j++) {
            printf(" %d |", matriz[i][j]);
        }
        printf("\n");
    }
}

void mostrarEsquinasMatriz(int filas, int columnas, int matriz[filas][columnas]) {
    printf("Matriz Resultante (Elementos de las esquinas):\n");
    for (int i = 0; i < filas; i++) {
        printf("|");
        for (int j = 0; j < columnas; j++) {
            if ((i == 0 && j == 0) || (i == 0 && j == columnas - 1) || 
                (i == filas - 1 && j == 0) || (i == filas - 1 && j == columnas - 1)) {
                printf(" %d |", matriz[i][j]);
            } else {
                printf("   |");
            }
        }
        printf("\n");
    }
}

int main() {
    printf("Bienvenido al programa para imprimir los 4 elementos de las esquinas de una matriz cuadrada.\n");

    int filas, columnas;

    printf("Ingrese el número de filas de la matriz: ");
    scanf("%d", &filas);
    if (filas <= 0) {
        printf("Error: El número de filas debe ser un número natural positivo.\n");
        return 1;
    }

    printf("Ingrese el número de columnas de la matriz: ");
    scanf("%d", &columnas);
    if (columnas <= 0) {
        printf("Error: El número de columnas debe ser un número natural positivo.\n");
        return 1;
    }

    int matriz[filas][columnas];
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            printf("Ingrese el valor para la posición [%d][%d]: ", i, j);
            scanf("%d", &matriz[i][j]);
        }
    }

    mostrarMatrizOriginal(filas, columnas, matriz);

    if (filas == columnas) {
        mostrarEsquinasMatriz(filas, columnas, matriz);
    } else {
        printf("Error: La matriz ingresada no es cuadrada.\n");
    }

    return 0;
}