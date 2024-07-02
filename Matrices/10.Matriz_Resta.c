#include <stdio.h>

// Función para imprimir las matrices originales
void imprimirMatrices(int filas, int columnas, int matrizA[filas][columnas], int matrizB[filas][columnas]) {
    printf("Matrices Originales:\n");
    for (int i = 0; i < filas; i++) {
        printf("|");
        for (int j = 0; j < columnas; j++) {
            printf(" %d |", matrizA[i][j]);
        }
        printf("  -  |");
        for (int j = 0; j < columnas; j++) {
            printf(" %d |", matrizB[i][j]);
        }
        printf("\n");
    }
}

// Función para imprimir la matriz resultante de la resta
void restarYImprimirMatrices(int filas, int columnas, int matrizA[filas][columnas], int matrizB[filas][columnas]) {
    int matrizResultado[filas][columnas];

    // Realizar la resta de las matrices
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            matrizResultado[i][j] = matrizA[i][j] - matrizB[i][j];
        }
    }

    printf("Matriz Resultante:\n");
    for (int i = 0; i < filas; i++) {
        printf("|");
        for (int j = 0; j < columnas; j++) {
            printf(" %d |", matrizResultado[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int filas, columnas;

    printf("Bienvenido al programa de resta de matrices (Las matrices deben tener el mismo tamaño).\n");
    printf("Ingrese el número de filas de las matrices: ");
    scanf("%d", &filas);
    if (filas <= 0) {
        printf("Error: El número de filas debe ser un número natural positivo.\n");
        return 1;
    }

    printf("Ingrese el número de columnas de las matrices: ");
    scanf("%d", &columnas);
    if (columnas <= 0) {
        printf("Error: El número de columnas debe ser un número natural positivo.\n");
        return 1;
    }

    int matrizA[filas][columnas];
    int matrizB[filas][columnas];

    // Lectura de los valores para la primera matriz
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            printf("Ingrese el valor para la primera matriz [%d][%d]: ", i, j);
            scanf("%d", &matrizA[i][j]);
        }
    }

    // Lectura de los valores para la segunda matriz
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            printf("Ingrese el valor para la segunda matriz [%d][%d]: ", i, j);
            scanf("%d", &matrizB[i][j]);
        }
    }

    // Llamada a las funciones para imprimir matrices y calcular la resta
    imprimirMatrices(filas, columnas, matrizA, matrizB);
    restarYImprimirMatrices(filas, columnas, matrizA, matrizB);

    return 0;
}