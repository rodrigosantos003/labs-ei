#include <stdio.h>
#include <stdlib.h>
#include "bmi.h"

int main()
{
    bmiPrintTable();

    double height = 0;
    double weight = 0;

    printf("Insira a altura (m): ");
    scanf("%lf", &height);
    printf("Insira o peso (kg): ");
    scanf("%lf", &weight);

    double bmi = bmiCompute(height, weight);

    printf("IMC = %.2f\n", bmi);
    bmiPrintClassification(bmi);

    return 0;
}