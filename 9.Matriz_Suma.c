#include <stdio.h>

void imprimirMatricesOriginales(int filas, int columnas, int matriz1[filas][columnas], int matriz2[filas][columnas]) {
    printf("Matrices Originales:\n");
    for (int i = 0; i < filas; i++) {
        printf("|");
        for (int j = 0; j < columnas; j++) {
            printf(" %d |", matriz1[i][j]);
        }
        printf("  +  |");
        for (int j = 0; j < columnas; j++) {
            printf(" %d |", matriz2[i][j]);
        }
        printf("\n");
    }
}

void imprimirMatrizResultante(int filas, int columnas, int matriz1[filas][columnas], int matriz2[filas][columnas]) {
    int matrizResul[filas][columnas];
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            matrizResul[i][j] = matriz1[i][j] + matriz2[i][j];
        }
    }
    printf("Matriz Resultante:\n");
    for (int i = 0; i < filas; i++) {
        printf("|");
        for (int j = 0; j < columnas; j++) {
            printf(" %d |", matrizResul[i][j]);
        }
        printf("\n");
    }
}

int main() {
    printf("Bienvenido al programa de suma de matrices (ambas matrices deben tener el mismo tamaño).\n");
    int nfilas, ncolumnas;
    
    printf("Ingrese el número de filas: ");
    scanf("%d", &nfilas);
    if (nfilas <= 0) {
        printf("Error: El número de filas debe ser un entero positivo.\n");
        return 1;
    }

    printf("Ingrese el número de columnas: ");
    scanf("%d", &ncolumnas);
    if (ncolumnas <= 0) {
        printf("Error: El número de columnas debe ser un entero positivo.\n");
        return 1;
    }

    int matriz1[nfilas][ncolumnas];
    int matriz2[nfilas][ncolumnas];

    for (int i = 0; i < nfilas; i++) {
        for (int j = 0; j < ncolumnas; j++) {
            printf("Ingrese el valor para la primera matriz[%d][%d]: ", i, j);
            scanf("%d", &matriz1[i][j]);
        }
    }

    for (int i = 0; i < nfilas; i++) {
        for (int j = 0; j < ncolumnas; j++) {
            printf("Ingrese el valor para la segunda matriz[%d][%d]: ", i, j);
            scanf("%d", &matriz2[i][j]);
        }
    }

    imprimirMatricesOriginales(nfilas, ncolumnas, matriz1, matriz2);
    imprimirMatrizResultante(nfilas, ncolumnas, matriz1, matriz2);

    return 0;
}