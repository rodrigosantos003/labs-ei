#include <stdio.h>
#include <stdlib.h>
#include "input.h"
#include "operations.h" //already includes fornite and list modules

int main()
{
    PtList shop = fortniteLoadShop();
    listPrint(shop);

    char *itemName = (char *)calloc(50, sizeof(char));
    printf("Enter an item to buy: ");
    readString(itemName, 50);

    bool itemBuy = fortniteItemBuy(itemName, shop);

    if (!itemBuy)
        printf("Não foi possível comprar o item\n");

    listPrint(shop);

    printf("Item at index %d\n", fortniteItemSearch(itemName, shop));

    PtList shopCopy = fortniteShopCopy(shop);
    listPrint(shopCopy);

    listDestroy(&shop);
    listDestroy(&shopCopy);

    return EXIT_SUCCESS;
}
