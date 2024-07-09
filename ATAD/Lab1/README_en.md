# Algorithms and Abstract Data Types

## Lab 1 \| Exercises + Template

🇬🇧 [English version](README_en.md)

This repository was created from:

- <https://github.com/estsetubal-atad/CProgram_Template>

Consult the README if you have questions about its use.

------------------------------------------------------------------------

Goals:

- Use of modularity;

- Manipulation of arrays / strings;

- Doxygen Documentation.

References:

- ATAD organization, documentation of the software used: <https://github.com/estsetubal-atad/Docs>

- "Linguagem C", e-book available on Moodle.

------------------------------------------------------------------------

💻 Clone this repository before moving forward.

### Level 1 (Estimated duration: &lt; 10min)

1.  Create an "arrays" module and add the `arrayPrint` function to it, which prints an array in the `[a, b, c, d, <...>]` format to the console:

``` cpp
void printArray(int arr[], int arrLength) {
    printf("[ ");
    for(int i=0; i<arrLength; i++) {
        printf("%d%s", arr[i], (i < arrLength - 1 ? ", " : ""));
    }
    printf("]\n");
}
```

2.  Exemplify the use of this function in `main` , creating and initializing an array of integers `v` with 5 elements (2, 3, 6, 4, 7); edit the makefile, compile and run the program.

### Level 2 (Estimated duration: ~25min)

❗ Whenever possible, implementations should avoid code duplication across other functions that compute necessary steps.

3.  Add the following additional functions to the "arrays" module:

    - `int sum(int arr[], int arrLength)` – returns the sum of the elements of `arr` ;

    - `double mean(int arr[], int arrLength)` – returns the average of the elements of `arr` ;

    - `double variance(int arr[], int arrLength)` – returns the (population) variance of `arr` – using the following formula:

     <img src="https://latex.codecogs.com/png.image?\dpi{150}&space;S^2&space;=&space;\frac{\sum_i^n&space;(x_i&space;-&space;\bar&space;x)^2}{n&space;-&space;1}" title="S^2 = \frac{\sum (x_i - \bar x)^2}{n - 1}" />

    where, `x_i` represents each array element, `\bar(x)` the average of all elements and `n` the number of elements.

    - `double standardDeviation(int arr[], int arrLength)` – returns the standard deviation of arr elements. 💡 The standard deviation consists of the square root of the variance.

4.  Test the result of these functions on the array instantiated in `main` .

    The required output and expected results are:

    ``` markdown
    Array: [2, 3, 6, 4, 7]
    Sum = 22
    Mean = 4.40
    Variance = 4.30
    Standard deviation = 2.07
    ```

    ❗ Display real values with two decimal places.

❓ What is the algorithmic complexity of the `variance` function you implemented?

### Level 3 (Estimated duration: ~25min)

❗ The following functions must belong to a new "strings" module.

🤔 the `const` modifier, eg, `const char[]` , is a "promise" that the string will not be changed within the function.

5.  Create function `bool equal(const char str1[], const char str2[])` that checks if two strings passed as arguments are equal (case-insensitive).

    - 💡 If the two strings have different lengths, they are guaranteed not to be the same, otherwise, use function `tolower(char)/toupper(char)` from library `<ctype.h>` to compare characters in the same capitalization.

6.  Create function `bool isPalindrome(const char str[])` that checks if the string is a palindrome (word or phrase that has the same sequence of letters in any reading order).

    - eg, "ovo", "ana", "sopapos" e "Sator arepo tenet opera rotas".

    - Implement a version that flags eg "Ana" and "aNA" as palindromes.

7.  Create function `bool hasDuplicates(const char str[])` that checks if there are any duplicate characters in `str` .

8.  Test the functions on `main` , prompting the user for all required strings.

### Level 4 (Estimated duration: ~20min)

9.  Implement in the "strings" module the function `void letterFrequency(cons char str[])` that prints on the console the frequency of occurrence of each letter of the alphabet in the string `str` (in tabular form) - it must work in a case-insensitive way and all characters that are not letters must be ignored.

    - Test the function on `main` , prompting the user for the string.

    🔍 Example:

    ``` markdown
    Introduza string: abracadabra
    Letra   | Freq.
    a   | 5
    b   | 2
    c   | 1
    d   | 1
    ...
    r   | 2
    ...     
    z   | 0
    ```

❓ What is the algorithmic complexity of the `letterFrequency` function you implemented?

### Level 5 (Estimated duration: &lt; 15min)

10. Provide doxygen documentation of all functions in the "arrays" module. 💡 documentation must be added in file `arrays.h` .

    - Check that, after doing so, you can see it while editing the `main.c` file, eg, when passing the cursor over the invocation of a documented function.

    - Generate the doxygen documentation - you should get the `html` folder. Open the `index.html` file and check the generated documentation.

------------------------------------------------------------------------

``` markdown
@bruno.silva
(EOF)
```

\[Disclaimer: This document was automatically translated, some original formatting may have been lost.\]
