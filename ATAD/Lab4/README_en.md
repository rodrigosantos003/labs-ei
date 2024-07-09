# Algorithms and Abstract Data Types

## Lab 4 \| Exercises + Template

🇬🇧 [English version](README_en.md)

This repository was created from:

- <https://github.com/estsetubal-atad/CProgram_Template>

Consult the README if you have questions about its use.

------------------------------------------------------------------------

Goals:

- Definition and types of data;

- Search, selection and sorting on composite data types;

- Passing arguments by reference (vs. passing by copy);

References:

- ATAD organization, documentation of the software used: <https://github.com/estsetubal-atad/Docs>

- "Linguagem C", e-book available on Moodle.

------------------------------------------------------------------------

❗ The requested functions must be defined and implemented in the `fortnite` module, unless otherwise indicated.

### Level 1 (Estimated duration: &lt; 10min)

1.  Define a composite data type `FortniteItem` that allows storing the information of a Fortnite store item. Consult the `fortniteshop.csv` file to infer the data type and dimension of each structure field.

2.  Define and implement the `fortniteItemCreate` function that returns a structure of type `FortniteItem` and that receives, as a parameter, the necessary values to initialize the created structure.

3.  Follow the following steps:

    - Complete the missing code in function `fortniteLoadShop` ;

    - In `main` declare an array of type `FortniteItem` with dimensions of `100` positions.

    - Call function `fortniteLoadShop` on this array; use the `howMany = 100` argument.

4.  Edit the makefile, compile and run the program, verifying its correct compilation.

### Level 2 (Estimated duration: ~25min)

5.  Define the `PtFortniteItem` data type to be a pointer to the `FortniteItem` type.

6.  Define and implement function `void fortniteItemPrint(PtFortniteItem item)` - which prints the details of an item in tabular form (see output excerpt below).

7.  Define and implement function `void fortniteArrayPrint(FortniteItem arr[], int arrLength)` , the purpose of which should be obvious.

    💡 Use the previous function `fortniteItemPrint` to print each of the array elements.

8.  In `main` invoke this function, compile and run the program. The expected output is the following:

    ``` markdown
    Imported 81 fortnite items: 
    Lovely                         | Rare                 | 1200 
    Hearty                         | Rare                 | 500 
    Hooked On You                  | Rare                 | 200 
    Cuddle King                    | Rare                 | 1200 
    ...
    ```

### Level 3 (Estimated duration: ~25min)

9.  Define and implement the `int findMostExpensiveItemIndex(FortniteItem arr[], int arrLength)` function that applies the selection algorithm to find the index of the most expensive item in the `arr` array.

10. On `main` call this function and print the respective item using function `fortniteItemPrint` .

### Level 4 (Estimated duration: ~20min)

💡 For sorting, use the bubble sort algorithm.

11. Define and implement function `void fortniteArraySortByRarity(FortniteItem arr[], int arrLength)` which should sort `arr` by rarity (alphabetically from AZ)

12. Define and implement function `void fortniteArraySortByCost(FortniteItem arr[], int arrLength)` that must order `arr` descending by cost.

13. Test both of the above functions by outputting the sorted array and checking the correctness of the result.

### Level 5 (Estimated duration: &lt; 15min)

14. On `main` output the size needed to store an instance of `FortniteItem` , ie, use of `sizeof` ;

15. In the previous level sorting algorithms, in the "swap" operations, define, implement, and use the `void swap(PtFortniteItem item1, PtFortniteItem item2)` function that swaps the contents of two addresses.

16. Adapt the code in `fortniteArrayPrint` to scan the array using pointer arithmetic instead of indexing.

------------------------------------------------------------------------

``` markdown
@bruno.silva
(EOF)
```

\[Disclaimer: This document was automatically translated, some original formatting may have been lost.\]
