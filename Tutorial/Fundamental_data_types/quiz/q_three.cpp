#include <iostream>

double getValue() {
    double x{0.0};
    std::cout << "Enter a double value: ";
    std::cin >> x;
    return x;
}

int main() {
    double x{getValue()};
    double y{getValue()};
    char oper{};
    double result{0.0};

    std::cout << "Enter one of the following: +, -, * or /: ";
    std::cin >> oper;
    switch (oper) {
        case '+':
            result = x + y;
            break;
        case '-':
            result = x - y;
            break;
        case '*':
            result = x * y;
            break;
        case '/':
            result = x / y;
            break;
    }
    std::cout << x << ' ' << oper << ' ' << y << " is " << result;
    return 0;
}