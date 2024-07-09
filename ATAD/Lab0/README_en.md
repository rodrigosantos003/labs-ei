# Algorithms and Abstract Data Types

## Lab 0 \| Exercises

🇬🇧 [English version](README_en.md)

Goals:

- Installation of the development environment (IDE), compiler and necessary tools.

- Creation of a project based on the available template.

- Development and debugging.

Prerequisites:

- Computer with Linux environment (bare or dual-boot), Windows 10/11 or MacOS.

- GitHub account (personal or institutional email)

### 1 \| Installation (Estimated duration &lt; 30min)

1.  Navigate to - and bookmark - the ATAD GitHub organization: <https://github.com/estsetubal-atad>

2.  In the organization's repositories, open the “Docs” repository and follow the “Software.pdf” tutorial - pay attention to the instructions for your operating system.

Documentation of all the tools to be used in the curricular unit is available in the same repository. Consult them whenever necessary.

### 2 \| Creating a new project (Estimated duration ~ 2min)

3.  Clone the `CProgram_Template` project via git from the command line:

``` console
$> git clone https://github.com/estsetubal-atad/CProgram_Template.git Lab0_Template
```

4.  Open the project in VS Code:

``` console
$> code Lab0_Template/
```

⚠️ If you are using Windows/WSL, you must ensure (note the bottom left corner) that you are in a Remote WSL session.

### 3 \| BMI (Body Mass Index) Program (Estimated duration ~ 30min)

5.  Create module `bmi` consisting of files `bmi.h` and `bmi.c` .

6.  Following good modularity practices, add three functions to this module:

    - `double bmiCompute(double height, double weight)` – which calculates BMI according to the following formula:

    ``` markdown
    BMI = (weight in kg) / (height in meters)^2
    ```

    - `void bmiPrintClassification(double bmi)` – which prints (in text) the BMI classification according to the following table:

    | Value of `BMI`   | Classification |
    |------------------|----------------|
    | `BMI < 19`       | Under weight   |
    | `19 <= BMI < 25` | Normal weight  |
    | `25 <= BMI < 30` | Overweight     |
    | `30 <= BMI < 40` | Type I Obesity |
    | `BMI >= 40`      | Morbid obesity |

    - `void bmiPrintTable()` – which prints the previous table in formatted form.

7.  Provide doxygen documentation of the developed functions and manage it (you should get a folder `html` with a file `index.html` ). Check the documentation result.

8.  Create a program in function `main` that, in the order presented:

    i.  Present the BMI table to the user;

    ii.  Ask the user for their weight and height, and;

    iii.  Calculate and display your BMI score.

### 4 \| Debugging (Estimated duration ~ 10min)

Test the debug functionality: place a breakpoint on the implementation of function `bmiPrintClassification` and run the program in debug mode.

### 5 \| Autonomous Worksheet Assigment | C Language (Estimated Duration ~ 90min)

The objectives of this worksheet are:

- Consolidate the process of developing and compiling programs in the C Language, using the proposed methodology and tools;
- Familiarize yourself with the basic syntax of the C Language, its data types, and how to proceed with input and output of data.

It is highly recommended to make this initial "effort" from which you will quickly reap dividends.

------------------------------------------------------------------------

``` markdown
@bruno.silva
(EOF)
```

\[Disclaimer: This document was automatically translated, some original formatting may have been lost.\]
