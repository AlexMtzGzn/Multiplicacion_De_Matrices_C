#include <stdio.h>
#include <stdlib.h>

int **asigancion_Memoria(int *filas, int *columnas, const char letra)
{

    do
    {
        printf("\nIngresa las filas de la matriz %c: ", letra);
        scanf("%i", &filas);
    } while (*filas < 1);

    do
    {
        printf("\nIngresa las columnas de la matriz %c: ", letra);
        scanf("%i", &columnas);
    } while (*columnas < 2);
}

int main(void)
{

    int filasA, columnasA, filasB, columnasB;

    int **matrizA, **matrizB;

    matrizA = asigancion_Memoria(&filasA, columnasA, 'A');
    matrizB = asigancion_Memoria(&filasB, columnasB, 'B');

    return 0;
}