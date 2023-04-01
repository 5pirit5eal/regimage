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
    - 
2. Output a newline whenever a line of output is complete
3. Prefer '\n' over std::endl when outputting text to the console
4. Naming:
    - functions and variabales in lower case, separated by _ (snake_case)
    - classes, structs and enumerations with _a_ capital letter, separated by upper case (e.g `YourClass`)
    - When defining function prototypes, keep the parameter names. You can easily create forward declarations 
by copy/pasting your function’s prototype and adding a semicolon.
    - Use explicit namespace prefixes to access identifiers defined in a namespace.
5. Your lines should be no longer than 80 chars in length
6. Your main function should return the value 0 if the program ran normally, or use EXIT_SUCCESS or EXIT_FAILURE from cstdlib
    - Function main will implicitly return 0 if no return statement is provided
7. _DRY_: dont repeat yourself, if you need to do something more than once, rewrite/create function and remove redundancies
8. Do not put a return statement at the end of a non-value returning function.
9. Header files:
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