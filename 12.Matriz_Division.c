#include <stdio.h>

void mostrarMatrices(int filas, int columnas, int matriz1[filas][columnas], int matriz2[filas][columnas]) {
    printf("Matrices Originales:\n");
    for(int i = 0; i < filas; i++) {
        printf("|");
        for(int j = 0; j < columnas; j++) {
            printf(" %d |", matriz1[i][j]);
        }
        printf("  /  ");
        printf("|");
        for(int j = 0; j < columnas; j++) {
            printf(" %d |", matriz2[i][j]);
        }
        printf("\n");
    }
}

void multiplicarMatrices(int filas1, int columnas1, int columnas2, int matriz1[filas1][columnas1], float matrizInversa[columnas1][columnas2]) {
    int resultado[filas1][columnas2];
    for(int i = 0; i < filas1; i++) {
        for(int j = 0; j < columnas2; j++) {
            resultado[i][j] = 0;
        }
    }
    for(int i = 0; i < filas1; i++) {
        for(int j = 0; j < columnas2; j++) {
            for(int k = 0; k < columnas1; k++) {
                resultado[i][j] += matriz1[i][k] * matrizInversa[k][j];
            }
        }
    }
    printf("Matriz Resultante:\n");
    for(int i = 0; i < filas1; i++) {
        printf("|");
        for(int j = 0; j < columnas2; j++) {
            printf(" %d |", resultado[i][j]);
        }
        printf("\n");
    }
}

int main() {
    printf("Bienvenido al programa de operaciones con matrices cuadradas del mismo tamaño.\n");
    int filas1, columnas1, filas2, columnas2;
    
    printf("Ingrese el número de filas de la primera matriz: ");
    scanf("%d", &filas1);
    printf("Ingrese el número de columnas de la primera matriz: ");
    scanf("%d", &columnas1);
    
    if (filas1 != columnas1) {
        printf("Error: La primera matriz debe ser cuadrada.\n");
        return 1;
    }
    
    printf("Ingrese el número de filas de la segunda matriz: ");
    scanf("%d", &filas2);
    printf("Ingrese el número de columnas de la segunda matriz: ");
    scanf("%d", &columnas2);
    
    if (filas2 != columnas2) {
        printf("Error: La segunda matriz debe ser cuadrada.\n");
        return 1;
    }
    
    if (filas1 != filas2) {
        printf("Error: Ambas matrices deben tener las mismas dimensiones.\n");
        return 1;
    }
    
    int matriz1[filas1][columnas1];
    for (int i = 0; i < filas1; i++) {
        for (int j = 0; j < columnas1; j++) {
            printf("Ingrese el valor para la primera matriz [%d][%d]: ", i, j);
            scanf("%d", &matriz1[i][j]);
        }
    }
    
    int matriz2[filas2][columnas2];
    for (int i = 0; i < filas2; i++) {
        for (int j = 0; j < columnas2; j++) {
            printf("Ingrese el valor para la segunda matriz [%d][%d]: ", i, j);
            scanf("%d", &matriz2[i][j]);
        }
    }
    
    float matrizInversa[filas2][columnas2];
    float auxiliar[filas2][columnas2];
    
    for (int i = 0; i < filas2; i++) {
        for (int j = 0; j < columnas2; j++) {
            if (i == j) {
                matrizInversa[i][j] = 1.0;
            } else {
                matrizInversa[i][j] = 0.0;
            }
            auxiliar[i][j] = matriz2[i][j];
        }
    }
    
    for (int i = 0; i < filas1; i++) {
        float divisor = auxiliar[i][i];
        for (int j = 0; j < columnas1; j++) {
            auxiliar[i][j] /= divisor;
            matrizInversa[i][j] /= divisor;
        }
        for (int k = 0; k < filas1; k++) {
            if (i != k) {
                float factor = auxiliar[k][i];
                for (int j = 0; j < columnas1; j++) {
                    auxiliar[k][j] -= factor * auxiliar[i][j];
                    matrizInversa[k][j] -= factor * matrizInversa[i][j];
                }
            }
        }
    }
    
    mostrarMatrices(filas1, columnas1, matriz1, matriz2);
    multiplicarMatrices(filas1, columnas1, columnas2, matriz1, matrizInversa);
    
    return 0;
}