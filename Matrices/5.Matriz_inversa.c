#include <stdio.h>
#include <math.h>

void imprimirMatriz(int filas, int columnas, int matriz[filas][columnas]) {
    printf("Matriz Original:\n");
    for (int i = 0; i < filas; i++) {
        printf("|");
        for (int j = 0; j < columnas; j++) {
            printf(" %d |", matriz[i][j]);
        }
        printf("\n");
    }
}

void calcularInversa(int filas, int columnas, int matriz[filas][columnas]) {
    float identidad[filas][columnas];
    float aux[filas][columnas];

    // Inicialización de las matrices identidad y auxiliar
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            identidad[i][j] = (i == j) ? 1 : 0;
            aux[i][j] = matriz[i][j];
        }
    }

    // Proceso de obtención de la matriz inversa
    for (int i = 0; i < filas; i++) {
        float divisor = aux[i][i];
        for (int j = 0; j < columnas; j++) {
            aux[i][j] /= divisor;
            identidad[i][j] /= divisor;
        }
        for (int k = 0; k < filas; k++) {
            if (i != k) {
                float factor = aux[k][i];
                for (int j = 0; j < columnas; j++) {
                    aux[k][j] -= factor * aux[i][j];
                    identidad[k][j] -= factor * identidad[i][j];
                }
            }
        }
    }

    // Impresión de la matriz inversa
    printf("Matriz Inversa:\n");
    for (int i = 0; i < filas; i++) {
        int error = 0;
        printf("|");
        for (int j = 0; j < columnas; j++) {
            if (!isinf(identidad[i][j])) {
                printf(" %.2f |", identidad[i][j]);
            } else {
                error = 1;
                break;
            }
        }
        if (error) {
            printf("Error: La matriz no tiene inversa\n");
            break;
        } else {
            printf("\n");
        }
    }
}

int main() {
    printf("Bienvenido al programa para calcular la inversa de una matriz cuadrada\n");

    int filas, columnas;
    printf("Ingrese el número de filas de la matriz: ");
    scanf("%d", &filas);
    if (filas <= 0) {
        printf("Error: El número de filas debe ser un número natural\n");
        return 1;
    }

    printf("Ingrese el número de columnas de la matriz: ");
    scanf("%d", &columnas);
    if (columnas <= 0) {
        printf("Error: El número de columnas debe ser un número natural\n");
        return 1;
    }

    if (filas != columnas) {
        printf("Error: La matriz debe ser cuadrada\n");
        return 1;
    }

    int matriz[filas][columnas];
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            printf("Ingrese el valor en la posición [%d][%d]: ", i, j);
            scanf("%d", &matriz[i][j]);
        }
    }

    imprimirMatriz(filas, columnas, matriz);
    calcularInversa(filas, columnas, matriz);

    return 0;
}