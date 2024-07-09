#include <stdio.h>
#include <stdlib.h>
#include "input.h"
#include "fortnite.h"

int main()
{

    // array em memória stack
    FortniteItem shop[100];

    int shopSize = fortniteLoadShop(shop, 100);
    printf("Imported %d fortnite items:\n", shopSize);
    fortniteArrayPrint(shop, shopSize);

    char nome[100] = "";

    printf("Introduza o nome do item a comprar: ");
    readString(nome, 100);

    fortniteItemBuy(nome, shop, shopSize);

    fortniteArrayPrint(shop, shopSize);

    FortniteItem *shopCopy = fortniteArrayCopy(shop, shopSize);

    fortniteArrayPrint(shopCopy, shopSize);

    free(shopCopy);

    return EXIT_SUCCESS;
}
