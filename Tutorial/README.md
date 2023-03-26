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
`g++ full_path_to_file.cpp -o file.exe -pedantic-errors -Wall -Weffc++ -Wextra -Wsign-conversion -Werror -std=c++20`

# Rules
1. Every c++ programm needs a main function or it will fail to link to other programms
2. Take care to avoid all situations that result in undefined behavior, such as using uninitialized variables.
3. Values calculated in an expression are discarded at the end of the expression (2+3=5, 5 is discarded)
4. Nested functions are not possible in c++
5. Use double quotes to include header files that you’ve written or are expected to be found in the current directory. Use angled brackets to include headers that come with your compiler, OS, or third-party libraries you’ve installed elsewhere on your system.

# Best Practices
1. Variables
    - Intialize your variables upon creation 
    - using direct initialization with {} if possible (e.g. int x{5};)
    - Each variable by itself even if they share types and values (with descriptive comment)
    - identifier in lower case
    - Define your local variables as close to their first use as reasonable
    - 
2. Output a newline whenever a line of output is complete
3. Prefer '\n' over std::endl when outputting text to the console
4. Naming:
    - functions and variabales in lower case, separated by _ (snake_case)
    - classes, structs and enumerations with _a_ capital letter, separated by upper case (e.g YourClass)
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
    

