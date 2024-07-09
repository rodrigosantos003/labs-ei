# Algorithms and Abstract Data Types

## Lab 6 \| Exercises + Template

🇬🇧 [English version](README_en.md)

This repository was created from:

- <https://github.com/estsetubal-atad/CProgram_Template>

Consult the README if you have questions about its use.

------------------------------------------------------------------------

Goals:

- Consolidate methodology for ADTs in the C language in the areas:

  - Specification, Implementation and Use.

References:

- Chapter 2 of the book “Abstract Data Types – Language C. Bruno Silva”, available on Moodle.

  - Specification, use and implementation of ADT `Complex` contained in this chapter.

------------------------------------------------------------------------

❗ There is a bash script included, ie `mem_check.sh` which allows you to launch valgrind correctly. When necessary, run on the terminal `$> bash mem_check.sh` .

### Introduction

The objective of this lab is to consolidate the proposed methodology for the specification, implementation and use of abstract data types in the C language. three-dimensional.

- During the levels, you will be asked to perform exercises in the three previous areas simultaneously;

- It should obey the proposed nomenclature, namely the use of the prefix `vector3d...` for the names of the operations and `VECTOR3D_...` for the error codes;

- The ADT specification must be accompanied by doxygen documentation.

### Level 1 (Estimated duration: ~20min)

1.  Define the necessary data structure to store the information of an instance of a vector;

2.  Implement functions `vector3dCreate` and `vector3dPrint` , following the provided documentation.

3.  Test the initially provided program by verifying its correctness.

4.  Check memory management correctness with valgrind.

### Level 2 (Estimated duration: ~20min)

5.  Implement function `vector3dDestroy` and use it to free the memory of the vector instance declared in the initial program. Check memory management correctness with valgrind.

6.  Declare two new instances of `PtVector3d` and print their contents.

    - One initialized through `vector3dCreate` ; the other initialized to `NULL` .

    - Check memory management correctness with valgrind.

### Level 3 (Estimated duration: ~20min)

7.  Implement the "accessor" functions `vector3dX` , `vector3dY` and `vector3dZ` which allow to obtain (by passing by reference) the individual values of the components of a vector.

8.  In file `main.c` declare and implement the following function:

    - `void printComponentsOf(PtVector3d vec)` - "extracts" the individual components from `vec` (via the functions in point 7) and prints them in `"x = <val> | y = <val> | z = <val>"` format.

    - If `vec` is invalid, enter `"Vector NULL. Não é possível apresentar as componentes."` . This check should be done by checking the error code returned by eg `vector3dX` . It could be done through `vec != NULL` , but that's not the point here.

9.  Test the previous function on `main` , passing a valid and initialized instance to `NULL` .

### Level 4 (Estimated duration: ~30min)

10. Implement and test function `vector3dMultiplyByScalar` according to its documentation.

    - The expected result for `<2, 1, -4> * 3` is `<6, 3, -12>` .

11. Implement and test function `vector3dAdd` according to its documentation.

    - The expected result for `<2, 1, -4> + <1, 0, 3>` is `<3, 1, -1>` .

12. Implement and test function `vector3dMagnitude` according to its documentation.

    - The expected result for `||<2, 1, -4>||` is `4.58` .

13. Check memory management correctness with valgrind.

### Level 5 (Estimated duration: &lt; 20min)

14. Implement and test function `vector3dNormalize` according to its documentation.

    - The expected result for `norm(<2, 1, -4>)` is `<0.44, 0.22, -0.87>` .

    - In `main` , verify that the magnitude of the resulting vector is `1` (which is the purpose of normalization).

15. Check memory management correctness with valgrind.

### Additional (autonomous)

16. Add the following function to the ADT specification and implement it:

    ``` cpp
    /**
     * @brief Checks whether two vectors are orthogonal
     * 
     * @param vec1 [in] PtVector3d pointer
     * @param vec2 [in] PtVector3d pointer
     * @return true if they are orthogonal
     * @return false if they are not orthogonal
     * @return false if vec1 is NULL or vec2 is NULL
     */
    bool vector3dOrthogonals(PtVector3d vec1, PtVector3d vec2);
    ```

    Two vectors are orthogonal if they make an angle of 90º between them in Cartesian space. One of the ways to check this is if the inner product between the two vectors is zero.

    `<x1, y1, z1> * <x2, y2, z2> = x1 * x2 + y1 * y2 + z1 * z2`

17. Test the correctness of this operation knowing that:

    - Vectors `<1, 2, 3>` and `<3, 6, -5>` are orthogonal, and;

    - Vectors `<2, 1, -4>` and `<3, 6, -5>` are not orthogonal.

------------------------------------------------------------------------

``` markdown
@bruno.silva
(EOF)
```

\[Disclaimer: This document was automatically translated, some original formatting may have been lost.\]
