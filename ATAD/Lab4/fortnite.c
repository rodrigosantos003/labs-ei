#include "fortnite.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "input.h"
#include "fortnite.h"

FortniteItem fortniteItemCreate(const char *name, const char *rarity, int price)
{
    FortniteItem item;
    strcpy(item.name, name);
    strcpy(item.rarity, rarity);
    item.price = price;
    return item;
}

int fortniteLoadShop(FortniteItem arr[], int howMany)
{
    FILE *stream = fopen("fortniteshop.csv", "r");

    /* If file does not exist, abort */
    if (stream == NULL)
        return -1;

    int count = 0;
    char line[1024];
    while (fgets(line, 1024, stream))
    {
        if (count == howMany)
            break;

        char *tmp = strdup(line);

        /* creates tokens[3] array, with tokens read from the file line */
        char **tokens = splitString(tmp, 3, ",");

        int vbucks = atoi(tokens[2]);
        arr[count++] = fortniteItemCreate(tokens[0], tokens[1], vbucks);

        free(tokens);
        free(tmp);
    }

    fclose(stream);

    return count;
}

void fortniteItemPrint(PtFortniteItem item)
{
    printf("%-30s | %-20s | %d\n", item->name, item->rarity, item->price);
}

void fortniteArrayPrint(PtFortniteItem arr, int arrLength)
{
    for (int i = 0; i < arrLength; i++)
    {
        fortniteItemPrint(&arr[i]);
    }
}

int findMostExpensiveItemIndex(FortniteItem arr[], int arrLength)
{
    int max = 0;

    for (int i = 0; i < arrLength; i++)
    {
        if (arr[i].price > arr[max].price)
            max = i;
    }

    return max;
}

void swap(PtFortniteItem item1, PtFortniteItem item2)
{
    FortniteItem temp = *item1;
    *item1 = *item2;
    *item2 = temp;
}

void fortniteArraySortByRarity(FortniteItem arr[], int arrLength)
{
    for (int i = 0; i < arrLength; i++)
    {
        for (int j = 0; j < arrLength - i - 1; j++)
        {
            if (strcmp(arr[j + 1].rarity, arr[j].rarity) < 0)
            {
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
}

void fortniteArraySortByCost(FortniteItem arr[], int arrLength)
{
    for (int i = 0; i < arrLength; i++)
    {
        int max = i;

        for (int j = i; j < arrLength; j++)
        {
            if (arr[j].price > arr[max].price)
            {
                max = j;
            }
        }

        swap(&arr[i], &arr[max]);
    }

    // for (int i = 0; i < arrLength; i++)
    // {
    //     for (int j = 0; j < arrLength - i - 1; j++)
    //     {
    //         if (arr[j + 1].price > arr[j].price)
    //         {
    //             swap(&arr[j], &arr[j + 1]);
    //         }
    //     }
    // }
}