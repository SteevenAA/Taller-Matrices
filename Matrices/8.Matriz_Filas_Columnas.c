#include <stdio.h>

void imprimirMatriz(int filas, int columnas, int matriz[filas][columnas]) {
    printf("Matriz Ingresada:\n");
    for(int i = 0; i < filas; i++) {
        printf("|");
        for(int j = 0; j < columnas; j++) {
            printf(" %d |", matriz[i][j]);
        }
        printf("\n");
    }
}

void calcularTamanio(int filas, int columnas, int matriz[filas][columnas]) {
    int tamanoTotal = filas * columnas * sizeof(matriz[0][0]);
    int tamanoFila = columnas * sizeof(matriz[0][0]);
    int tamanoElemento = sizeof(matriz[0][0]);
    int filasCalculadas = tamanoTotal / tamanoFila;
    int columnasCalculadas = tamanoFila / tamanoElemento;
    printf("Dimensiones de la Matriz: [%d][%d]\n", filasCalculadas, columnasCalculadas);
}

int main() {
    printf("Bienvenido al programa para calcular el tamaño de una matriz usando sizeof\n");
    int nFilas, nColumnas;

    printf("Ingrese el número de filas de la matriz: ");
    scanf("%d", &nFilas);
    if(nFilas <= 0) {
        printf("Error: El número ingresado no es válido.\n");
        return 1;
    }

    printf("Ingrese el número de columnas de la matriz: ");
    scanf("%d", &nColumnas);
    if(nColumnas <= 0) {
        printf("Error: El número ingresado no es válido.\n");
        return 1;
    }

    int matriz[nFilas][nColumnas];
    for(int i = 0; i < nFilas; i++) {
        for(int j = 0; j < nColumnas; j++) {
            printf("Ingrese el valor para la posición [%d][%d]: ", i, j);
            scanf("%d", &matriz[i][j]);
        }
    }

    imprimirMatriz(nFilas, nColumnas, matriz);
    calcularTamanio(nFilas, nColumnas, matriz);

    return 0;
}