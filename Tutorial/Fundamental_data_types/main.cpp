#include <iostream>

int main() {
    std::cout << "bool:\t\t" << sizeof(bool) << " bytes\n";
    std::cout << "char:\t\t" << sizeof(char) << " bytes\n";
    std::cout << "wchar_t:\t" << sizeof(wchar_t) << " bytes\n";
    std::cout << "char16_t:\t" << sizeof(char16_t) << " bytes\n";
    std::cout << "char32_t:\t" << sizeof(char32_t) << " bytes\n";
    std::cout << "short:\t\t" << sizeof(short) << " bytes\n";
    std::cout << "int:\t\t" << sizeof(int) << " bytes\n";
    std::cout << "long:\t\t" << sizeof(long) << " bytes\n";
    std::cout << "long long:\t" << sizeof(long long) << " bytes\n";
    std::cout << "float:\t\t" << sizeof(float) << " bytes\n";
    std::cout << "double:\t\t" << sizeof(double) << " bytes\n";
    std::cout << "long double:\t" << sizeof(long double) << " bytes\n";

    unsigned short x{65535};  // largest 16-bit unsigned value possible
    std::cout << "x was: " << x << '\n';

    x = 65536;  // 65536 is out of our range, so we get wrap-around
    std::cout << "x is now: " << x << '\n';

    int x{5};       // 5 means integer
    double y{5.0};  // 5.0 is a floating point literal (no suffix means double
                    // type by default)
    float z{
        5.0f};  // 5.0 is a floating point literal, f suffix means float type

    std::cout << true << '\n';
    std::cout << false << '\n';

    std::cout << std::boolalpha;  // print bools as true or false

    std::cout << true << '\n';
    std::cout << false << '\n';

    std::cout << static_cast<int>(5.5) << '\n';

    const int x{5};

    constexpr double gravity{9.8};  // ok: 9.8 is a constant expression
    constexpr int sum{4 + 5};       // ok: 4 + 5 is a constant expression
    constexpr int something{sum};   // ok: sum is a constant expression

    std::cout << "Enter your age: ";
    int age{};
    std::cin >> age;

    return 0;
}