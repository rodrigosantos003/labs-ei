#include "operations.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "input.h"

PtList fortniteLoadShop()
{
    FILE *stream = fopen("fortniteshop.csv", "r");

    /* If file does not exist, abort */
    if (stream == NULL)
        return NULL;

    PtList list = listCreate();

    int count = 0;
    char line[1024];
    while (fgets(line, 1024, stream))
    {
        char *tmp = strdup(line);

        /* creates tokens[3] array, with tokens read from the file line */
        char **tokens = splitString(tmp, 3, ",");

        int vbucks = atoi(tokens[2]);
        FortniteItem item = fortniteItemCreate(tokens[0], tokens[1], vbucks);

        listAdd(list, count++, item);

        free(tokens);
        free(tmp);
    }

    fclose(stream);

    return list;
}

bool fortniteItemBuy(const char *name, PtList shop)
{
    if (listIsEmpty(shop))
        return false;

    int size;
    listSize(shop, &size);

    for (int i = 0; i < size; i++)
    {
        FortniteItem item, aux;
        listGet(shop, i, &item);

        if (strcmp(item.name, name) == 0)
        {
            item.owned = true;
            listSet(shop, i, item, &aux);
            return true;
        }
    }

    return false;
}

int fortniteItemSearch(const char *name, PtList shop)
{
    if (listIsEmpty(shop))
        return -1;

    int size;
    listSize(shop, &size);

    for (int i = 0; i < size; i++)
    {
        FortniteItem item;
        listGet(shop, i, &item);

        if (strcmp(item.name, name) == 0)
            return i;
    }

    return -1;
}

PtList fortniteShopCopy(PtList shop)
{
    if (listIsEmpty(shop))
        return NULL;

    PtList shopCopy = listCreate();
    if (shopCopy == NULL)
        return NULL;

    int size;
    listSize(shop, &size);

    for (int i = 0; i < size; i++)
    {
        FortniteItem item;
        listGet(shop, i, &item);
        listAdd(shopCopy, i, item);
    }

    return shopCopy;
}

PtList fortniteFindItemsPriceRange(PtList shop, int min, int max)
{
    if (listIsEmpty(shop))
        return NULL;

    PtList itemsPriceRange = listCreate();
    if (itemsPriceRange)
        return NULL;

    int size;
    listSize(shop, &size);

    for (int i = 0; i < size; i++)
    {
        FortniteItem item;
        listGet(shop, i, &item);

        if (item.vbucks >= min && item.vbucks <= max)
            listAdd(itemsPriceRange, i, item);
    }

    return itemsPriceRange;
}