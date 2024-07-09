#pragma once

typedef struct fortniteItem
{
    char name[100];
    char rarity[20];
    int price;
} FortniteItem;

typedef FortniteItem *PtFortniteItem;

FortniteItem fortniteItemCreate(const char *name, const char *rarity, int price);

/**
 * @brief Loads contents of fortnite shop from csv file.
 *
 * The caller states 'howMany' records are to be loaded.
 * If less are available, then only those are loaded into the array.
 *
 * @param arr an array with at least capacity for 'howMany'
 * @param howMany how many items to load.
 * @return int number of items loaded into 'arr'
 */
int fortniteLoadShop(FortniteItem arr[], int howMany);

void fortniteItemPrint(PtFortniteItem item);

void fortniteArrayPrint(FortniteItem arr[], int arrLength);

int findMostExpensiveItemIndex(FortniteItem arr[], int arrLength);

void swap(PtFortniteItem item1, PtFortniteItem item2);

void fortniteArraySortByRarity(FortniteItem arr[], int arrLength);

void fortniteArraySortByCost(FortniteItem arr[], int arrLength);