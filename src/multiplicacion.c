#include <stdio.h>
#include <stdlib.h>

int **asigancion_Memoria(int *filas, int *columnas, const char letra)
{

    do
    {
        printf("\nIngresa las filas de la matriz %c: ", letra);
        scanf("%i", filas);

        if (*filas < 1)
            printf("\nIngresa de nuevo las columnas de la matriz %c", letra);

    } while (*filas < 1);

    do
    {
        printf("\nIngresa las columnas de la matriz %c: ", letra);
        scanf("%i", columnas);

        if (*filas < 1)
            printf("\nIngresa de nuevo las columnas de la matriz %c", letra);

    } while (*columnas < 2);

    int **matriz = (int **)malloc(*filas * sizeof(int *));

    for (int i = 0; i < *filas; i++)
        matriz[i] = (int *)malloc(*columnas * sizeof(int));

    return matriz;
}

int ** multiplicacion_Matrices(int ** matrizA, int** matrizB, int *filasA, int *columnasA , int *filasB, int *columnasB){

    //int **matrizC = asigancion_Memoria();

    //return matrizC;
}

void liberar_Memoria(int **matrizA, int **matrizB)
{

    free(matrizA);
    free(matrizB);
}

int main(void)
{

    int filasA, columnasA, filasB, columnasB;

    int **matrizA, **matrizB, **matrizC;

    matrizA = asigancion_Memoria(&filasA, &columnasA, 'A');
    matrizB = asigancion_Memoria(&filasB, &columnasB, 'B');

    if (columnasA != filasB)
    {
        liberar_Memoria(matrizA,matrizB);

        return 0;
    }



    return 0;
}