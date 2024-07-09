#include <stdio.h>
#include <math.h>

/**
 * @brief Escreve no ecrã os elementos de um array
 *
 * @param arr Array de inteiros
 * @param arrLength Tamanho do array
 */
void printArray(int arr[], int arrLength)
{
    printf("[ ");
    for (int i = 0; i < arrLength; i++)
    {
        printf("%d%s", arr[i], (i < arrLength - 1 ? ", " : ""));
    }
    printf("]\n");
}

/**
 * @brief Calcula a soma os elementos de um array
 *
 * @param arr Array de inteiros
 * @param arrLength Tamnho do array
 * @return int Valor da soma
 */
int sum(int arr[], int arrLength)
{
    int sum = 0;
    for (int i = 0; i < arrLength; i++)
    {
        sum += arr[i];
    }
    return sum;
}

/**
 * @brief Calcula a média dos elementos de um array
 *
 * @param arr Array de inteiros
 * @param arrLength Tamnho do array
 * @return double Valor da média
 */
double mean(int arr[], int arrLength)
{
    return (double)sum(arr, arrLength) / arrLength;
}

/**
 * @brief Calcula a variação dos elementos de um array
 *
 * @param arr Array de inteiros
 * @param arrLength Tamanho do array
 * @return double Valor da variação
 */
double variance(int arr[], int arrLength)
{
    double meanValue = mean(arr, arrLength);
    double variance = 0;
    for (int i = 0; i < arrLength; i++)
    {
        variance += (arr[i] - meanValue) * (arr[i] - meanValue);
    }
    return variance / (arrLength - 1);
}

/**
 * @brief Calcula o desvio padrão dos elementos de um array
 *
 * @param arr Array de inteiros
 * @param arrLength Tamnho do array
 * @return double Valor do desvio padrão
 */
double standardDeviation(int arr[], int arrLength)
{
    return sqrt(variance(arr, arrLength));
}