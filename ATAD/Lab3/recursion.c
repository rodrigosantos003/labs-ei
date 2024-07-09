#include <stdio.h>
#include <stdlib.h>
#include "recursion.h"

int min(int a, int b);

int arrayMinimum(int arr[], int arrLength)
{
    if (arrLength == 1)
        return arr[0];

    return min(arr[arrLength - 1], arrayMinimum(arr, arrLength - 1));
}

int min(int a, int b)
{
    return (a < b) ? a : b;
}

int arraySumEven(int arr[], int arrLength)
{
    if (arrLength == 0)
        return 0;

    if (arr[arrLength - 1] % 2 == 0)
        return arr[arrLength - 1] + arraySumEven(arr, arrLength - 1);

    return arraySumEven(arr, arrLength - 1);
}

int binarySearch(int val, int arr[], int start, int end)
{
    if (start > end)
        return -1;

    int mid = (start + end) / 2;

    if (arr[mid] == val)
        return mid;
    else if (arr[mid] > val)
        return binarySearch(val, arr, start, mid - 1);
    else
        return binarySearch(val, arr, mid + 1, end);
}

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to partition the array and return the pivot index
int partition(int arr[], int low, int high)
{
    int pivot = arr[high]; // Choose the last element as pivot
    int i = low - 1;       // Index of smaller element

    for (int j = low; j < high; j++)
    {
        // If current element is smaller than or equal to pivot
        if (arr[j] <= pivot)
        {
            i++; // Increment index of smaller element
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return i + 1;
}

// Function to implement Quick Sort
void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        // Partitioning index
        int pi = partition(arr, low, high);

        // Separately sort elements before and after partition
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}
