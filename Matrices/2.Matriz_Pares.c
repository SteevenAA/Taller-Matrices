#include <stdio.h>

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

void imprimirMatrizPares(int filas, int columnas, int matriz[filas][columnas]) {
    printf("Matriz de Pares:\n");
    for (int i = 0; i < filas; i++) {
        printf("|");
        for (int j = 0; j < columnas; j++) {
            if (matriz[i][j] % 2 == 0) {
                printf(" %d |", matriz[i][j]);
            } else {
                printf("   |");
            }
        }
        printf("\n");
    }
}

int main() {
    printf("Bienvenido al programa de impresión de elementos pares en una matriz\n");
    
    int filas, columnas;
    printf("Ingrese el número de filas de la matriz: ");
    scanf("%d", &filas);
    
    if (filas <= 0) {
        printf("Error: El número de filas debe ser un entero positivo\n");
        return 1;
    }
    
    printf("Ingrese el número de columnas de la matriz: ");
    scanf("%d", &columnas);
    
    if (columnas <= 0) {
        printf("Error: El número de columnas debe ser un entero positivo\n");
        return 1;
    }
    
    int matriz[filas][columnas];
    
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            printf("Ingrese el valor para la posición [%d][%d]: ", i, j);
            scanf("%d", &matriz[i][j]);
        }
    }
    
    imprimirMatrizOriginal(filas, columnas, matriz);
    imprimirMatrizPares(filas, columnas, matriz);
    
    return 0;
}