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

// Función para imprimir la matriz transpuesta
void imprimirMatrizTranspuesta(int filas, int columnas, int matriz[filas][columnas]) {
    printf("Matriz Transpuesta:\n");
    for (int i = 0; i < columnas; i++) {
        printf("|");
        for (int j = 0; j < filas; j++) {
            printf(" %d |", matriz[j][i]);
        }
        printf("\n");
    }
}

int main() {
    printf("Bienvenido al programa de transposición de matrices\n");
    
    int numFilas, numColumnas;
    printf("Ingrese el número de filas de la matriz: ");
    scanf("%d", &numFilas);
    
    if (numFilas <= 0) {
        printf("Error: El número de filas debe ser un entero positivo.\n");
        return 1;
    }
    
    printf("Ingrese el número de columnas de la matriz: ");
    scanf("%d", &numColumnas);
    
    if (numColumnas <= 0) {
        printf("Error: El número de columnas debe ser un entero positivo.\n");
        return 1;
    }
    
    int matriz[numFilas][numColumnas];
    
    // Llenar la matriz con valores proporcionados por el usuario
    for (int i = 0; i < numFilas; i++) {
        for (int j = 0; j < numColumnas; j++) {
            printf("Ingrese el valor para la posición [%d][%d]: ", i, j);
            scanf("%d", &matriz[i][j]);
        }
    }
    
    // Imprimir la matriz original y la transpuesta
    imprimirMatrizOriginal(numFilas, numColumnas, matriz);
    imprimirMatrizTranspuesta(numFilas, numColumnas, matriz);
    
    return 0;
}