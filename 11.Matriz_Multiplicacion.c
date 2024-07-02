#include <stdio.h>

void imprimirMatrices(int filas, int columnas, int matrizA[filas][columnas], int matrizB[filas][columnas]) {
    printf("Matrices Ingresadas:\n");
    for (int i = 0; i < filas; i++) {
        printf("|");
        for (int j = 0; j < columnas; j++) {
            printf(" %d |", matrizA[i][j]);
        }
        printf("  *  ");
        printf("|");
        for (int j = 0; j < columnas; j++) {
            printf(" %d |", matrizB[i][j]);
        }
        printf("\n");
    }
}

void multiplicarMatrices(int filas1, int columnas1, int columnas2, int matrizA[filas1][columnas1], int matrizB[columnas1][columnas2]) {
    int resultado[filas1][columnas2];
    
    for (int i = 0; i < filas1; i++) {
        for (int j = 0; j < columnas2; j++) {
            resultado[i][j] = 0;
        }
    }
    
    for (int i = 0; i < filas1; i++) {
        for (int j = 0; j < columnas2; j++) {
            for (int k = 0; k < columnas1; k++) {
                resultado[i][j] += matrizA[i][k] * matrizB[k][j];
            }
        }
    }
    
    printf("Matriz Resultante:\n");
    for (int i = 0; i < filas1; i++) {
        printf("|");
        for (int j = 0; j < columnas2; j++) {
            printf(" %d |", resultado[i][j]);
        }
        printf("\n");
    }
}

int main() {
    printf("Bienvenido al programa de multiplicación de matrices\n");
    
    int filasA, columnasA, filasB, columnasB;
    
    printf("Ingrese el número de filas de la primera matriz: ");
    scanf("%d", &filasA);
    if (filasA <= 0) {
        printf("Error: Número de filas debe ser positivo\n");
        return 1;
    }
    
    printf("Ingrese el número de columnas de la primera matriz: ");
    scanf("%d", &columnasA);
    if (columnasA <= 0) {
        printf("Error: Número de columnas debe ser positivo\n");
        return 1;
    }
    
    printf("Ingrese el número de filas de la segunda matriz: ");
    scanf("%d", &filasB);
    if (filasB <= 0) {
        printf("Error: Número de filas debe ser positivo\n");
        return 1;
    }
    
    printf("Ingrese el número de columnas de la segunda matriz: ");
    scanf("%d", &columnasB);
    if (columnasB <= 0) {
        printf("Error: Número de columnas debe ser positivo\n");
        return 1;
    }
    
    if (columnasA != filasB) {
        printf("Error: El número de columnas de la primera matriz no es igual al número de filas de la segunda matriz\n");
        return 1;
    }
    
    int matrizA[filasA][columnasA];
    for (int i = 0; i < filasA; i++) {
        for (int j = 0; j < columnasA; j++) {
            printf("Ingrese el valor para la matriz 1 [%d][%d]: ", i, j);
            scanf("%d", &matrizA[i][j]);
        }
    }
    
    int matrizB[filasB][columnasB];
    for (int i = 0; i < filasB; i++) {
        for (int j = 0; j < columnasB; j++) {
            printf("Ingrese el valor para la matriz 2 [%d][%d]: ", i, j);
            scanf("%d", &matrizB[i][j]);
        }
    }
    
    imprimirMatrices(filasA, columnasA, matrizA, matrizB);
    multiplicarMatrices(filasA, columnasA, columnasB, matrizA, matrizB);
    
    return 0;
}