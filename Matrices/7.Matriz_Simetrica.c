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

void verificarSimetria(int filas, int columnas, int matriz[filas][columnas]) {
    printf("Matriz Resultante:\n");
    int esSimetrica = 1; // Suponemos que la matriz es simétrica inicialmente
    for (int i = 0; i < columnas; i++) {
        printf("|");
        for (int j = 0; j < filas; j++) {
            if (matriz[i][j] != matriz[j][i]) {
                esSimetrica = 0; // Marcamos como no simétrica
                break; // Salimos del bucle interno
            }
            printf(" %d |", matriz[j][i]);
        }
        printf("\n");
        if (!esSimetrica) break; // Salimos del bucle externo si no es simétrica
    }
    if (esSimetrica) {
        printf("La matriz es simétrica.\n");
    } else {
        printf("Error: La matriz no es simétrica.\n");
    }
}

int main() {
    printf("Bienvenido al programa para verificar la simetría de una matriz cuadrada.\n");

    int filas, columnas;
    printf("Ingrese el número de filas de la matriz: ");
    scanf("%d", &filas);
    if (filas <= 0) {
        printf("Error: Número de filas no válido.\n");
        return 1;
    }

    printf("Ingrese el número de columnas de la matriz: ");
    scanf("%d", &columnas);
    if (columnas <= 0) {
        printf("Error: Número de columnas no válido.\n");
        return 1;
    }

    if (filas != columnas) {
        printf("Error: La matriz debe ser cuadrada.\n");
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
    verificarSimetria(filas, columnas, matriz);

    return 0;
}