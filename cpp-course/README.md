# Tutorial Knowledge
This page summarizes all key insights from the lectures

## Setup:
1. Choose an IDE (Visual Studio, Visual Studio Code, Eclipse, Xcode, ...)
2. Install a GCC/G++ compiler (e.g. https://www.mingw-w64.org/)
    - For Windows Users:
        1. Download a MingW-W64-builds compiler from their GitHub
        2. Unpack the built 7z file at C:\ using "extract here"
        3. Add the path to the unpacked folder to the PATH system variable
3. Set the coding style to Google C++ (Extension config in VSCode)

## Compiling code:
g++ file.cpp -o file -pedantic-errors -Wall -Weffc++ -Wextra -Wsign-conversion -Werror -std=c++20

# Rules
1. Every c++ programm needs a main function or it will fail to link to other programms
2. Take care to avoid all situations that result in undefined behavior, such as using uninitialized variables.

# Best Practices
1. Variables
    - Intialize your variables upon creation 
    - using direct initialization with {} if possible (e.g. int x{5};)
    - Each variable by itself even if they share types and values (with descriptive comment)
    - identifier in lower case
    - 
2. Output a newline whenever a line of output is complete
3. Prefer '\n' over std::endl when outputting text to the console
4. Naming:
    - functions and variabales in lower case, separated by _ (snake_case)
    - classes, structs and enumerations with _a_ capital letter, separated by upper case (e.g YourClass)

