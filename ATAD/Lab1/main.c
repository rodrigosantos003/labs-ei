#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "strings.h"
#include "arrays.h"

int main()
{
    int v[5] = {2, 3, 6, 4, 7};

    printf("Array: ");
    printArray(v, 5);

    printf("Sum: %d\n", sum(v, 5));
    printf("Mean: %.2f\n", mean(v, 5));
    printf("Variance: %.2f\n", variance(v, 5));
    printf("Standard deviation: %.2f\n", standardDeviation(v, 5));

    printf("\n\n");

    char str1[] = "Sopapos";
    char str2[] = "ATAD";

    printf("Strings: %s, %s\n", str1, str2);
    printf("Strings Iguais: %s\n", equal(str1, str2) ? "Sim" : "Não");
    printf("Palíndromo: %s\n", isPalindrome(str1) ? "Sim" : "Não");
    printf("Duplicados: %s\n", hasDuplicates(str1) ? "Sim" : "Não");

    printf("\n\n");

    printf("Introduza a string: ");
    char str[100];
    scanf("%s", str);

    letterFrequency(str); // Complexidade:

    return EXIT_SUCCESS;
}
