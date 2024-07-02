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

// Función para imprimir solo los elementos impares de la matriz
void imprimirMatrizImpares(int filas, int columnas, int matriz[filas][columnas]) {
    printf("Matriz con elementos impares:\n");
    for (int i = 0; i < filas; i++) {
        printf("|");
        for (int j = 0; j < columnas; j++) {
            if (matriz[i][j] % 2 != 0) {
                printf(" %d |", matriz[i][j]);
            } else {
                printf("   |");
            }
        }
        printf("\n");
    }
}

int main() {
    printf("Bienvenido al programa para mostrar elementos impares de una matriz\n");

    int nfilas, ncolumnas;

    // Solicitar el número de filas de la matriz
    printf("Introduce el número de filas de la matriz: ");
    scanf("%d", &nfilas);
    if (nfilas <= 0) {
        printf("Error: El número de filas debe ser un entero positivo\n");
        return 1;
    }

    // Solicitar el número de columnas de la matriz
    printf("Introduce el número de columnas de la matriz: ");
    scanf("%d", &ncolumnas);
    if (ncolumnas <= 0) {
        printf("Error: El número de columnas debe ser un entero positivo\n");
        return 1;
    }

    int matriz[nfilas][ncolumnas];

    // Rellenar la matriz con valores introducidos por el usuario
    for (int i = 0; i < nfilas; i++) {
        for (int j = 0; j < ncolumnas; j++) {
            printf("Introduce el valor para la posición [%d][%d]: ", i, j);
            scanf("%d", &matriz[i][j]);
        }
    }

    // Imprimir la matriz original
    imprimirMatrizOriginal(nfilas, ncolumnas, matriz);

    // Imprimir la matriz con solo los elementos impares
    imprimirMatrizImpares(nfilas, ncolumnas, matriz);

    return 0;
}
