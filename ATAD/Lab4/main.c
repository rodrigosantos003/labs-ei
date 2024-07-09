#include <stdio.h>
#include <stdlib.h>
#include "input.h"
#include "fortnite.h"

int main()
{
    PtFortniteItem shop = (PtFortniteItem)malloc(100 * sizeof(FortniteItem));
    int count = fortniteLoadShop(shop, 100);

    printf("Imported %d fortnite items:\n", count);

    fortniteArrayPrint(shop, count);

    int mostExpensiveIndex = findMostExpensiveItemIndex(shop, count);
    printf("\nMost expensive item is: ");
    fortniteItemPrint(&shop[mostExpensiveIndex]);

    fortniteArraySortByRarity(shop, count);
    printf("\nSorted by rarity:\n");
    fortniteArrayPrint(shop, count);

    fortniteArraySortByCost(shop, count);
    printf("\nSorted by cost:\n");
    fortniteArrayPrint(shop, count);

    printf("Size of FortniteItem: %ld\n", sizeof(FortniteItem));

    return EXIT_SUCCESS;
}
