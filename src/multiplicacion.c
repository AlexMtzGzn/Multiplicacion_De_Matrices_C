#include <stdio.h>
#include <stdlib.h>

int **asigancion_Memoria(int *filas, int *columnas, const char letra)
{
    if (letra != 'c')
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
    }

    int **matriz = (int **)malloc(*filas * sizeof(int *));

    for (int i = 0; i < *filas; i++)
        matriz[i] = (int *)malloc(*columnas * sizeof(int));

    return matriz;
}

int **multiplicacion_Matrices(int **matrizA, int **matrizB, int *filasA, int *columnasA, int *filasB, int *columnasB)
{

    int **matrizC = asigancion_Memoria(filasA, columnasB, 'c');

    for (int i = 0; i < *filasA; i++)
    {
        for (int j = 0; j < *columnasB; j++)
        {
            matrizC[i][j] = 0;
            for (int k = 0; k < *columnasA; k++)
            {
                matrizC[i][j] += matrizA[i][k] * matrizB[k][j];
            }
        }
    }

    return matrizC;
}

void imprimir_matriz(int ** matriz, int *filas, int *columnas, const char letra){

    printf("\nMatriz %c\n", letra);

    for(int i = 0; i < *filas; i++){
        for(int j = 0; j < *columnas; j++){
            printf("%i",matriz[i][j]);
        }

        printf("\n");
    }
}

void liberar_Memoria(int **matriz, int *columnas)
{
    for(int i = 0; i < *columnas; i++)
    free(matriz[i]);

free(matriz);
}

int main(void)
{

    int filasA, columnasA, filasB, columnasB;

    int **matrizA, **matrizB, **matrizC;

    matrizA = asigancion_Memoria(&filasA, &columnasA, 'A');
    matrizB = asigancion_Memoria(&filasB, &columnasB, 'B');

    if (columnasA != filasB)
    {
        liberar_Memoria(matrizA,&columnasA);
        liberar_Memoria(matrizB,&columnasB);

        return 0;
    }

    imprimir_matriz(matrizA,&filasA,&columnasB,'A');
    imprimir_matriz(matrizB,&filasB,&columnasB,'B');
    imprimir_matriz(matrizC,&filasA,&columnasB,'C');

    liberar_Memoria(matrizA,&columnasA);
    liberar_Memoria(matrizB,&columnasB);
    liberar_Memoria(matrizC,&columnasB);


    return 0;
}