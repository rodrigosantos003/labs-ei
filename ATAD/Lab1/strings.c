#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>

/**
 * @brief Verifica se duas strings são iguais
 *
 * @param str1 String 1
 * @param str2 String 2
 * @return true Verdadeiro se as strings são iguais
 * @return false Falso se as strings são diferentes
 */
bool equal(const char str1[], const char str2[])
{
    if (strlen(str1) != strlen(str2))
    {
        return false;
    }

    for (int i = 0; str1[i] != '\0'; i++)
    {
        if (toupper(str1[i]) != toupper(str2[i]))
        {
            return false;
        }
    }

    return true;
}

/**
 * @brief Verifica se uma string é um palíndromo
 *
 * @param str String
 * @return true Verdadeiro se a string é um palíndromo
 * @return false Falso se a string não é um palíndromo
 */
bool isPalindrome(const char str[])
{
    int length = strlen(str);
    for (int i = 0; i < length / 2; i++)
    {
        if (toupper(str[i]) != toupper(str[length - i - 1]))
        {
            return false;
        }
    }
    return true;
}

/**
 * @brief Verifica se uma string tem caracteres duplicados
 *
 * @param str String
 * @return true Verdadeiro se a string tem caracteres duplicados
 * @return false Falso se a string não tem caracteres duplicados
 */
bool hasDuplicates(const char str[])
{
    int length = strlen(str);
    for (int i = 0; i < length; i++)
    {
        for (int j = i + 1; j < length; j++)
        {
            if (toupper(str[i]) == toupper(str[j]))
            {
                return true;
            }
        }
    }
    return false;
}

/**
 * @brief Escreve no ecrã a frequência de cada letra de uma string
 *
 * @param str String
 */
void letterFrequency(const char str[])
{
    int frequency[26] = {0};
    for (int i = 0; str[i] != '\0'; i++)
    {
        if (isalpha(str[i]))
        {
            frequency[toupper(str[i]) - 'A']++;
        }
    }

    printf("%-5s%-10s\n", "Letra ", "Freq.");
    for (int i = 0; i < 26; i++)
    {
        printf("%-5c%-10d\n", i + 'A', frequency[i]);
    }
}