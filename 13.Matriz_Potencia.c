#include <stdio.h>
#include <math.h>

void mostrarMatrices(int filas, int columnas, int matrizA[filas][columnas], int matrizB[filas][columnas]){
    printf("Matrices Iniciales:\n");
    for(int i=0; i<filas; i++){
        printf("|");
        for(int j=0; j<columnas; j++){    
            printf(" %d |", matrizA[i][j]); 
        }
        printf("   "); // Espacio entre las dos matrices
        printf("|");
        for(int j=0; j<columnas; j++){
            printf(" %d |", matrizB[i][j]);
        }
        printf("\n");
    }
}

void calcularPotenciaMatrices(int filas, int columnas, int matrizA[filas][columnas], int matrizB[filas][columnas]){
    int resultado[filas][columnas];
    for(int i=0; i<filas; i++){
        for(int j=0; j<columnas; j++){    
            resultado[i][j] = pow(matrizA[i][j], matrizB[i][j]);
        }
    }
    printf("Resultado de la Potenciación de Matrices:\n");
    for(int i=0; i<filas; i++){
        printf("|");
        for(int j=0; j<columnas; j++){    
            printf(" %d |", resultado[i][j]);
        }
        printf("\n");
    }
}

int main(){
    printf("Bienvenido al programa para calcular la potencia de matrices (ambas matrices deben ser del mismo tamaño)\n");
    int filas, columnas;
    printf("Ingrese el número de filas de las matrices: ");
    scanf("%d", &filas);
    printf("Ingrese el número de columnas de las matrices: ");
    scanf("%d", &columnas);

    int matrizA[filas][columnas];
    for(int i=0; i<filas; i++){
        for(int j=0; j<columnas; j++){
            printf("Ingrese un valor para la Matriz A [%d][%d]: ", i, j);
            scanf("%d", &matrizA[i][j]);
        }
    }

    int matrizB[filas][columnas];
    for(int i=0; i<filas; i++){
        for(int j=0; j<columnas; j++){
            printf("Ingrese un valor para la Matriz B [%d][%d]: ", i, j);
            scanf("%d", &matrizB[i][j]);
        }
    }

    mostrarMatrices(filas, columnas, matrizA, matrizB);
    calcularPotenciaMatrices(filas, columnas, matrizA, matrizB);

    return 0;
}