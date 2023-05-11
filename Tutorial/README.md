# Tutorial Knowledge
This page summarizes all key insights from the lectures

## Setup:
1. Choose an IDE (Visual Studio, Visual Studio Code, Eclipse, Xcode, ...)
2. Install a GCC/G++ compiler (e.g. https://www.mingw-w64.org/)
    - For Windows Users:
        1. Download a MingW-W64-builds compiler from their GitHub
        2. Unpack the built 7z file at C:\ using "extract here"
        3. Add the path to the unpacked folder to the PATH system variable
3. Set the coding style to Google C++ (Extension config in VSCode) using .clang-format
https://zed0.co.uk/clang-format-configurator/

## Compiling code:
Typical compilation command for a single file:

`g++ full_path_to_file.cpp -o file -pedantic-errors -Wall -Weffc++ -Wextra -Wsign-conversion -Werror -std=c++20`

Typical compilation command for multiple files:

`g++ full_path_to_files/*.cpp -o name_of_programm -pedantic-errors -Wall -Weffc++ -Wextra -Wsign-conversion -Werror -std=c++20`


When including header files from other directories:

`g++ -I/source/includes main.cpp -o file -pedantic-errors -Wall -Weffc++ -Wextra -Wsign-conversion -Werror -std=c++20`

or in your tasks.json configuration file, add a new line in the “Args” section:
`"-I/source/includes",`

# Rules
1. Every c++ programm needs a main function or it will fail to link to other programms
2. Take care to avoid all situations that result in undefined behavior, such as using uninitialized variables.
3. Values calculated in an expression are discarded at the end of the expression (2+3=5, 5 is discarded)
4. Nested functions are not possible in c++
5. Use double quotes (`#include "add.h"`) to include header files that you’ve written or are expected to be found in the current directory. Use angled brackets to include headers that come with your compiler, OS, or third-party libraries you’ve installed elsewhere on your system (`#include <iostream>`).
6. 

# Best Practices
1. Variables
    - Intialize your variables upon creation 
    - using direct initialization with {} if possible (e.g. `int x{5};`)
    - Each variable by itself even if they share types and values (with descriptive comment)
    - identifier in lower case
    - Define your local variables as close to their first use as reasonable
    - For maximum compatibility, you shouldn’t assume that variables are larger than the specified minimum size (see data types table).
    - You can make integer unsigned by using `unsigned [your type]`, but should be avoided mixing with signed and used for holding quantaties or mathematical operations
    - Prefer `int` when the size of the integer doesn’t matter (e.g. the number will always fit within the range of a 2-byte signed integer). For example, if you’re asking the user to enter their age, or counting from 1 to 10, it doesn’t matter whether int is 16 or 32 bits (the numbers will fit either way). This will cover the vast majority of the cases you’re likely to run across.
    - Prefer `std::int#_t` when storing a quantity that needs a guaranteed range.
    - Prefer `std::uint#_t` when doing bit manipulation or where well-defined wrap-around behavior is required.
    - The type of your literals should match the type of the variables they’re being assigned to or used to initialize.
    - Put stand-alone chars in single quotes (e.g. `'t'` or `'\n'`, not `"t"` or `"\n"`). Do not use mulit-character literals e.g. `'42'`
    - Any variable that should not be modifiable after initialization and whose initializer is known at compile-time should be declared as constexpr.
    - Any variable that should not be modifiable after initialization and whose initializer is not known at compile-time should be declared as const.
    - Prefer std::string_view over std::string when you need a read-only string, especially for function parameters.
2. Logging
    - Output a newline whenever a line of output is complete
    - Prefer '\n' over std::endl when outputting text to the console
3. Functions:
    - Use an empty parameter list instead of void to indicate that a function has no parameters.
    - Do not put a return statement at the end of a non-value returning function.
    - _DRY_: dont repeat yourself, if you need to do something more than once, rewrite/create function and remove redundancies
    - Your main function should return the value 0 if the program ran normally, or use EXIT_SUCCESS or EXIT_FAILURE from cstdlib
    - Function main will implicitly return 0 if no return statement is provided
    - Don’t use `const` when returning by value.
4. Naming:
    - functions and variabales in lower case, separated by _ (snake_case)
    - classes, structs and enumerations with _a_ capital letter, separated by upper case (e.g `YourClass`)
    - When defining function prototypes, keep the parameter names. You can easily create forward declarations
    - Place `const` before its type when defining a constant.
by copy/pasting your function’s prototype and adding a semicolon.
    - Use explicit namespace prefixes to access identifiers defined in a namespace.
5. Your lines should be no longer than 80 chars in length
6. Header files:
    - Header files should generally not contain function and variable definitions, so as not to violate the one definition rule.
An exception is made for symbolic constants
    - If a header file is paired with a code file (e.g. add.h with add.cpp), they should both have the same base name (add).
    - Source files should #include their paired header file (if one exists).
    - Each file should explicitly #include all of the header files it needs to compile. Do not rely on headers included transitively from other headers.
    - To minimize errors, structure includes by the following order:
        1. standard library headers
        2. 3rd party library headers
        3. Other heaers from your project
        4. The paired header file
    - When including a header file from the standard library, use the version without the .h extension if it exists. User-defined headers should still use a .h extension.
    - Each file should explicitly `#include` all of the header files it needs to compile.
    - A header guard is the name of the header file in all caps (add.h --> `#define ADD_H`)
7. Operators:
    - Always parenthesize the conditional part of the conditional operator ?, and consider parenthesizing the whole thing as well (e.g. `std::cout << ((x > y) ? x : y) << '\n'`).
    - Avoid == or != comparisons on floating point as it is unprecise. Instead use an epsilon (e.g. `std::abs(a-b) > epsilon`)
    
# Data Types

|  Data Type  |            Description            |                   Typical Bit Width                  |                                                         Typical Range                                                        |
|:-----------:|:---------------------------------:|:----------------------------------------------------:|:----------------------------------------------------------------------------------------------------------------------------:|
| bool        | Boolean value                     | 1 bit                                                | true or false                                                                                                                |
| char        | Character or small integer        | 8 bits                                               | -128 to 127 or 0 to 255                                                                                                      |
| short       | Short integer                     | 16 bits                                              | -32,768 to 32,767                                                                                                            |
| int         | Integer                           | 32 bits                                              | -2,147,483,648 to 2,147,483,647                                                                                              |
| long        | Long integer                      | 32 bits on 32-bit systems, 64 bits on 64-bit systems | -2,147,483,648 to 2,147,483,647 on 32-bit systems, -9,223,372,036,854,775,808 to 9,223,372,036,854,775,807 on 64-bit systems |
| long long   | Long long integer                 | 64 bits                                              | -9,223,372,036,854,775,808 to 9,223,372,036,854,775,807                                                                      |
| float       | Single-precision floating point   | 32 bits                                              | Approximately 1.2E-38 to 3.4E+38                                                                                             |
| double      | Double-precision floating point   | 64 bits                                              | Approximately 2.3E-308 to 1.8E+308                                                                                           |
| long double | Extended-precision floating point | 80 bits on most systems, 128 bits on some systems    | Approximately 3.4E-4932 to 1.1E+4932                                                                                         |
| wchar_t     | Wide character                    | 16 bits or 32 bits                                   | 0 to 65,535 or 0 to 4,294,967,295                                                                                            |
| char16_t    | 16-bit Unicode character          | 16 bits                                              | 0 to 65,535                                                                                                                  |
| char32_t    | 32-bit Unicode character          | 32 bits                                              | 0 to 4,294,967,295                                                                                                           |
| void        | Represents the absence of type    | N/A                                                  | N/A                                                                                                                          |
| nullptr     | Null pointer                      | N/A                                                  | N/A                                                                                                                          |

## Char Values

|       Name      |    Symbol    |                                        Meaning                                       |
|:---------------:|:------------:|:------------------------------------------------------------------------------------:|
| Alert           | \a           | Makes an alert, such as a beep                                                       |
| Backspace       | \b           | Moves the cursor back one space                                                      |
| Formfeed        | \f           | Moves the cursor to next logical page                                                |
| Newline         | \n           | Moves cursor to next line                                                            |
| Carriage return | \r           | Moves cursor to beginning of line                                                    |
| Horizontal tab  | \t           | Prints a horizontal tab                                                              |
| Vertical tab    | \v           | Prints a vertical tab                                                                |
| Single quote    | \’           | Prints a single quote                                                                |
| Double quote    | \”           | Prints a double quote                                                                |
| Backslash       | \\           | Prints a backslash.                                                                  |
| Question mark   | \?           | Prints a question mark.<br>No longer relevant. You can use question marks unescaped. |
| Octal number    | \(number)    | Translates into char represented by octal                                            |
| Hex number      | \x(number)   | Translates into char represented by hex number                                       |
| nullptr         | Null pointer | N/A                                                                                  |