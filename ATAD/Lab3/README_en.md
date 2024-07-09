# Algorithms and Abstract Data Types

## Lab 3 \| Exercises + Template

🇬🇧 [English version](README_en.md)

This repository was created from:

- <https://github.com/estsetubal-atad/CProgram_Template>

Consult the README if you have questions about its use.

------------------------------------------------------------------------

Goals:

- Recursion;

- Doxygen Documentation.

- Debugging;

References:

- ATAD organization, documentation of the software used: <https://github.com/estsetubal-atad/Docs>

- TP slides, available on Moodle.

------------------------------------------------------------------------

💻 Clone this repository before moving forward.

### Level 1 (Estimated duration: &lt; 20min)

❗ The following functions must belong to a new module `recursion` .

1.  Define and implement the `int arrayMinimum(int arr[], int arrLength)` function, which returns the minimum value found in the `arr` array. `arrayMinimum` is intended to be a recursive function that operates as follows (pseudo-code in natural language):

    > If there is only one element, return it.
    >
    > Otherwise, it returns the minimum of:
    >
    > 1)  The last value;
    >
    > <!-- -->
    >
    > 2)  The value returned from the recursive call to the first `(n-1)` elements.

    💡 It is suggested to implement a function `int min(int, int)` that must be defined and declared only in `recursion.c` , as it will only be used there.

2.  Exemplify the use of this function in `main` on array XYZ012; edit the makefile, compile and run the program.

### Level 2 (Estimated duration: &lt; 20min)

3.  Define and implement function `int arraySumEven(int arr[], int arrLength)` , which returns the sum of even elements in array `arr` . `arraySumEven` is intended to be a recursive function.

4.  Exemplify the use of this function in `main` on array `seq` and validate the result.

5.  In `main` implement a small piece of code that checks at which index of array `seq` (inclusive) the sum of its previous even elements reaches `890` .

    - For example, at index `4` the value `128` is reached, ie the subsequence `{93, 32, 31, 36, 60}` .

### Level 3 (Estimated duration: ~25min)

📖 Read Addendum - Binary Search.

6.  Define and implement function `binarySearch` , implementing the given algorithm.

7.  Test the function on `main` , creating and initializing an array with the elements illustrated in the figure and searching for element `19` . You can test later with other values.

### Level 4 and 5 (Estimated duration: ~25min)

📖 Read the Addendum - Quicksort Sorting Algorithm.

8.  Define and implement function `quickSort` , implementing the given algorithm.

9.  Test the function in `main` on the unordered array `seq` ; print array contents after sorting.

❗ Finally, read the Addendum - Invocation.

## Addendum

### Binary Search

In an ordered sequence, it is possible to optimize the search using a strategy of successive partitioning of the sequence into two halves, to reduce the number of elements to be searched.

The algorithmic complexity of this search is `O(log n)` , but it needs the sequence to be sorted (otherwise it has to be done a priori - it doesn't pay off compared to a sequential search)

![](binarySearch.png)

In the previous figure we can see a successful case of a binary search for the `19` value:

1.  In the first iteration, the average element of the sequence is calculated by integer division of the sum of the minimum and maximum positions ( `start` and `end` ), which in this case is the index element `5` .

2.  As the searched value is `19` , it is greater than the value stored in the middle element, it means that it is in the second half of the sequence, passing the minimum position ( `start` ) to the element to the right of the middle position, in this case, `11` .

3.  The analysis is repeated, this time the searched value is smaller than the value of the average element, so this will be found in the first half, passing through this, the maximum value ( `end` ) for the element to the left of the average value .

4.  When the average position matches the searched value, the search ends successfully, returning the index of that element (in this case, index `7` ).

5.  If adjusting `start` and `end` results in an "empty array", then it does not exist and returns `-1`

#### Recursive Algorithm

In pseudo-code:

``` markdown
Algorithm binarySearch
    input: val - integer
           arr - array of integers
           start - start index for search - natural number
           end - end index for search - natural number
    output: arr index of val; -1 if not found - integer
BEGIN
    IF start > end THEN
        RETURN -1

    mid <- (start + end) / 2

    IF arr[mid] = val THEN
        RETURN mid
    ELSE IF arr[mid] > val THEN
        RETURN binarySearch(val, arr, start, mid - 1)
    ELSE
        RETURN binarySearch(val, arr, mid + 1, end)
    END IF 
END
```

### Quicksort Sorting Algorithm

The [*quicksort*](https://en.wikipedia.org/wiki/Quicksort) algorithm is a sorting algorithm based on the "divide-and-conquer" principle and can be implemented recursively. Its average-case algorithmic complexity is `O(n log n)` , ie, more efficient than bubble or selection sort.

It is intended that, given the algorithm, it will be able to translate it into the C language.

#### Recursive Algorithm

In pseudo-code close to implementation:

💡 `swap` means "swap" the elements in the indicated positions.

``` markdown
/* low  --> Starting index,  high  --> Ending index */
quickSort(arr[], low, high)
{
    if (low < high)
    {
        /* pi is partitioning index, arr[pi] is now
           at right place */
        pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);  // Before pi
        quickSort(arr, pi + 1, high); // After pi
    }
}

/* This function takes last element as pivot, places
   the pivot element at its correct position in sorted
    array, and places all smaller (smaller than pivot)
   to left of pivot and all greater elements to right
   of pivot */
partition (arr[], low, high)
{
    // pivot (Element to be placed at right position)
    pivot = arr[high];  
 
    i = (low - 1)  // Index of smaller element and indicates the 
                   // right position of pivot found so far

    for (j = low; j <= high- 1; j++)
    {
        // If current element is smaller than the pivot
        if (arr[j] < pivot)
        {
            i++;    // increment index of smaller element
            swap arr[i] and arr[j]
        }
    }
    swap arr[i + 1] and arr[high]
    return (i + 1)
}
```

### Invocation

Although it is not requested in this work, the invocation of the following algorithms can be done in a "traditional" way, in view of what is taught. Example:

``` cpp
int findIndexOf(int val, int arr[], int arrLength) {
    /* First call of binary search to include the whole array */
    return binarySearch(val, arr, 0, arrLength - 1);
}
```

That is, we keep the traditional "interface" that hides algorithm invocation details. The same can be done, similarly, for the quick sort algorithm.

------------------------------------------------------------------------

``` markdown
@bruno.silva
(EOF)
```

\[Disclaimer: This document was automatically translated, some original formatting may have been lost.\]
