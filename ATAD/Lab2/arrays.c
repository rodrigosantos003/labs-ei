#include <stdio.h>
#include <stdbool.h>
#include "arrays.h"

void printArray(int arr[], int arrLength)
{
    printf("[ ");
    for (int i = 0; i < arrLength; i++)
    {
        printf("%d%s", arr[i], (i < arrLength - 1 ? ", " : ""));
    }
    printf("]\n");
}

int arrayFirstIndexOf(int i, const int arr[], int arrLength)
{
    for (int j = 0; j < arrLength; j++)
    {
        if (arr[j] == i)
        {
            return j;
        }
    }
    return -1;
}

int arrayLastIndexOf(int i, const int arr[], int arrLength)
{
    for (int j = arrLength - 1; j >= 0; j--)
    {
        if (arr[j] == i)
        {
            return j;
        }
    }
    return -1;
}

void arraySort(int arr[], int arrLength, bool ascending)
{
    for (int i = 0; i < arrLength - 1; i++)
    {
        for (int j = 0; j < arrLength - i - 1; j++)
        {
            if (ascending ? arr[j] > arr[j + 1] : arr[j] < arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    printArray(arr, arrLength);
}

// Complexidade Algorítmica: O(n^2)
int matrixMaximumIndex(int m, int n, int mat[][n])
{
    int max = 0;
    int index = -1;

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (mat[i][j] > max)
            {
                max = mat[i][j];
                index = i * n + j;
            }
        }
    }

    return index;
}