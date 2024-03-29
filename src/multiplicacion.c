#include <stdio.h>
#include <stdlib.h>

int **asignacion_Memoria(int *filas, int *columnas, const char letra)
{
    if (letra != 'C')
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

            if (*columnas < 1)
                printf("\nIngresa de nuevo las columnas de la matriz %c", letra);

        } while (*columnas < 2);
    }

    int **matriz = (int **)malloc(*filas * sizeof(int *));

    for (int i = 0; i < *filas; i++)
        matriz[i] = (int *)malloc(*columnas * sizeof(int));

    return matriz;
}

void llenar_Matriz(int **matriz, int *filas, int *columnas, const char letra)
{

    printf("\nLa matriz %c", letra);

    for (int i = 0; i < *filas; i++)
    {

        for (int j = 0; j < *columnas; j++)
        {

            printf("\nIngresa el valor de la matriz[%i][%i]: ", i, j);
            scanf("%i", &matriz[i][j]);
        }
    }
}

int **multiplicacion_Matrices(int **matrizA, int **matrizB, int *filasA, int *columnasA, int *filasB, int *columnasB)
{
    int **matrizC = asignacion_Memoria(filasA, columnasB, 'C');

    for (int i = 0; i < *filasA; i++)
    {
        for (int j = 0; j < *columnasB; j++)
        {
            matrizC[i][j] = 0;
            for (int k = 0; k < *columnasA; k++)
                matrizC[i][j] += matrizA[i][k] * matrizB[k][j];
        }
    }

    return matrizC;
}

void imprimir_matriz(int **matriz, int *filas, int *columnas, const char letra)
{

    printf("\nMatriz %c\n", letra);

    for (int i = 0; i < *filas; i++)
    {
        for (int j = 0; j < *columnas; j++)
        {
            printf(" %i ", matriz[i][j]);
        }

        printf("\n");
    }
}

void liberar_Memoria(int **matriz, int *filas)
{
    for (int i = 0; i < *filas; i++)
        free(matriz[i]);

    free(matriz);
}

int main(void)
{

    int filasA, columnasA, filasB, columnasB;

    int **matrizA, **matrizB, **matrizC;

    matrizA = asignacion_Memoria(&filasA, &columnasA, 'A');
    matrizB = asignacion_Memoria(&filasB, &columnasB, 'B');

    if (columnasA != filasB)
    {
        liberar_Memoria(matrizA, &filasA);
        liberar_Memoria(matrizB, &filasB);

        return 0;
    }

    llenar_Matriz(matrizA, &filasA, &columnasA, 'A');
    llenar_Matriz(matrizB, &filasB, &columnasB, 'B');

    matrizC = multiplicacion_Matrices(matrizA, matrizB, &filasA, &columnasA, &filasB, &columnasB);

    imprimir_matriz(matrizA, &filasA, &columnasB, 'A');
    imprimir_matriz(matrizB, &filasB, &columnasB, 'B');
    imprimir_matriz(matrizC, &filasA, &columnasB, 'C');

    liberar_Memoria(matrizA, &filasA);
    liberar_Memoria(matrizB, &filasB);
    liberar_Memoria(matrizC, &filasA);

    return 0;
}