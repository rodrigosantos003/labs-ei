# Algorithms and Abstract Data Types

## Lab 7 \| Exercises + Template

🇬🇧 [English version](README_en.md)

Goals:

- Use of ADT;

- Dynamic memory management (heap).

References:

- “Abstract Data Types – Language C. Bruno Silva”, available on Moodle.

------------------------------------------------------------------------

❗ The requested functions must be defined and implemented in the `operations` module, unless otherwise indicated. You should use valgrind to verify correct memory management at the end of each level.

### Level 1 (Estimated duration: &lt; 20min)

1.  Analyze the code structure, compile and run the program, verifying its execution.

2.  Implement function `bool fortniteItemBuy(const char* name, PtList shop)` that marks the item with name `name` as purchased (field `owned = true` ).

3.  Implement in `main` a piece of code that asks the user for the name of the item to be purchased. Reprint the store; the item, if found, should appear as purchased; otherwise, it should display an error message. Test the program.

### Level 2 (Estimated duration: ~15min)

4.  Implement function `int fortniteItemSearch(const char* name, PtList shop)` that returns the index of the item named `name` ; returns `-1` if it does not exist. Test this function on `main` , showing the complete information of the searched item.

### Level 3 (Estimated duration: ~15min)

5.  Implement function `PtList fortniteShopCopy(PtList shop)` which returns a copy of the store, ie a new list containing a copy of the items in `shop` .

6.  Add to `main` the code to test this function; create the copy, print that list, and don't forget to free the memory before the program ends.

### Level 4 (Estimated duration: ~20min)

7.  Implement function `PtList fortniteFindItemsPriceRange(PtList shop, int min, int max)` which:

    - Returns by return a new list containing a copy of the items whose price is found in `[min, max]` ; returns `NULL` if `shop == NULL` . If there are no items within the range, it returns an elementless (empty) list.

8.  In XYZ018, ask the user for a price range and proceed to purchase the items found in that range. Items must be marked as purchased from the initial list/shop (not the copy).

### Level 5 (Estimated duration: ~20min)

9.  Implement and test the `void forniteSortByName(PtList shop, bool ascending)` function that sorts the items in `shop` ascending/descending (depending on the parameter) by their name. Test this function on the store copy created in step 6.

10. Provide doxygen documentation of all functions requested in this statement.

------------------------------------------------------------------------

``` markdown
@bruno.silva
(EOF)
```

\[Disclaimer: This document was automatically translated, some original formatting may have been lost.\]
