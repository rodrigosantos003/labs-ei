#include "fortnite.h"
#include <stdio.h>
#include <string.h>

FortniteItem fortniteItemCreate(char *name, char *rarity, int vbucks) {
    FortniteItem item;
    strcpy(item.name, name);
    strcpy(item.rarity, rarity);
    item.vbucks = vbucks;
    item.owned = false;
    return item;
}

void fortniteItemPrint(PtFortniteItem item) {
    printf("%-30s | %-20s | %6d | %s", item->name, item->rarity, 
            item->vbucks, (item->owned) ? "Owned" : "Buy");
}
