#pragma once

#include <stdbool.h>

typedef struct fortniteItem {
    char name[40];
    char rarity[12];
    int vbucks;
    bool owned;
} FortniteItem;

typedef struct fortniteItem* PtFortniteItem;

void fortniteItemPrint(PtFortniteItem item);
FortniteItem fortniteItemCreate(char *name, char *rarity, int vbucks);

