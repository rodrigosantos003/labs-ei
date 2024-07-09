#include <stdio.h>
#include <stdlib.h>
#include "input.h"
#include "recursion.h"

int sumOfEvenIndices(int arr[], int arrLength, int index, int sum)
{
    if (index > arrLength)
    {
        return -1; // Retorna -1 se não encontrar a soma desejada
    }

    if (arr[index] % 2 == 0)
    {
        sum += arr[index]; // Adiciona o valor do elemento par atual à soma
    }

    if (sum == 890)
    {
        return index; // Retorna o índice atual se a soma for igual a 890
    }

    // Chama recursivamente a função com o próximo índice
    return sumOfEvenIndices(arr, arrLength, index + 1, sum);
}

int main()
{

    int seq[50] = {
        93, 32, 31, 36, 60, 1, 74, 87, 52, 2,
        76, 54, 74, 17, 90, 81, 96, 72, 22, 31,
        49, 83, 99, 1, 11, 55, 86, 39, 6, 10,
        48, 65, 52, 10, 86, 82, 43, 4, 3, 6,
        78, 35, 31, 82, 18, 1, 48, 80, 23, 38};

    printf("Menor valor: %d\n", arrayMinimum(seq, 50));

    printf("Soma dos pares: %d\n", arraySumEven(seq, 50));

    int index = sumOfEvenIndices(seq, 50, 0, 0);
    printf("A soma dos elementos pares anteriores atinge 890 no índice: %d\n", index);

    printf("Indice do valor 19: %d\n", binarySearch(19, seq, 0, 49));

    quickSort(seq, 0, 49);

    printf("Array ordenado:\n");
    for (int i = 0; i < 50; i++)
    {
        printf("%d ", seq[i]);
    }

    return EXIT_SUCCESS;
}
