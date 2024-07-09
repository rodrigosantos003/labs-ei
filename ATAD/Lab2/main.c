#include <stdio.h>
#include <stdlib.h>
#include "input.h"
#include "arrays.h"

int main()
{
    int seq[5] = {1, 5, 4, 2, 3};
    int val = 0;

    printArray(seq, 5);

    printf("Escreva um valor a pesquisar: ");
    readInteger(&val);

    int firstIndex = arrayFirstIndexOf(val, seq, 5);
    int lastIndex = arrayLastIndexOf(val, seq, 5);

    firstIndex == -1 ? printf("Valor %d não existe \n", val) : printf("Primeira ocorrência de %d: Índice %d\n", val, firstIndex);
    lastIndex == -1 ? printf("Valor %d não existe \n", val) : printf("Primeira ocorrência de %d: Índice %d\n", val, lastIndex);

    arraySort(seq, 5, true);

    int matrix[2][3] = {{1, 2, 3}, {4, 5, 6}};
    printf("Maior valor no índice: %d", matrixMaximumIndex(2, 3, matrix));

    return EXIT_SUCCESS;
}
