#include <stdio.h>
#include <math.h>
#include "bmi.h"

/**
 * @brief Calcula o IMC
 *
 * @param height Altura
 * @param weight Peso
 * @return double Valor do IMC
 */
double bmiCompute(double height, double weight)
{
    return weight / pow(height, 2);
}

/**
 * @brief Calcula a classificação do IMC
 *
 * @param bmi Valor do IMC
 */
void bmiPrintClassification(double bmi)
{
    if (bmi < 19)
    {
        printf("Abaixo do Peso\n");
    }
    else if (bmi < 25)
    {
        printf("Peso Normal\n");
    }
    else if (bmi < 30)
    {
        printf("Sobrepeso\n");
    }
    else if (bmi < 40)
    {
        printf("Obesidade do Tipo I\n");
    }
    else
    {
        printf("Obesidade Mórbida\n");
    }
}

/**
 * Escreve a tabela de classificação do IMC
 *
 */
void bmiPrintTable()
{
    printf("++++++++++++++++++++++++++++++++++++++++\n");
    printf("+++ Valor do IMC ++++++ Classificação \t\t+++\n");
    printf("++++++++++++++++++++++++++++++++++++++++\n");
    printf("+++ IMC < 19 ++++++ Abaixo do Peso \t\t+++\n");
    printf("+++ 19 <= IMC < 25 ++++++ Peso Normal \t\t+++\n");
    printf("+++ 25 <= IMC < 30 ++++++ Sobrepeso \t\t+++\n");
    printf("+++ 30 <= IMC < 40 ++++++ Obesidade do Tipo I \t+++\n");
    printf("+++ IMC >= 40 ++ Obesidade Mórbida \t\t+++\n");
    printf("++++++++++++++++++++++++++++++++++++++++\n");
}