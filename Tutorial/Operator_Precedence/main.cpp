#include <cassert>
#include <cmath>
#include <iostream>

std::int64_t powint(std::int64_t base, int exp) {
    // Specific function to evaluate int pow as pow can cause overflow.
    assert(exp >= 0 && "powint: exp parameter has negative value");
    std::int64_t result{1};
    while (exp) {
        if (exp & 1) result *= base;
        exp >>= 1;
        base *= base;
    }
    return result;
}

bool isEven(int x) { return (x % 2) == 0; }

// epsilon is an absolute value
bool approximatelyEqualAbs(double a, double b, double absEpsilon) {
    // if the distance between a and b is less than absEpsilon, then a and b are
    // "close enough"
    return std::abs(a - b) <= absEpsilon;
}
// return true if the difference between a and b is within epsilon percent of
// the larger of a and b
bool approximatelyEqualRel(double a, double b, double relEpsilon) {
    return (std::abs(a - b) <=
            (std::max(std::abs(a), std::abs(b)) * relEpsilon));
}

// return true if the difference between a and b is less than absEpsilon, or
// within relEpsilon percent of the larger of a and b
bool approximatelyEqualAbsRel(double a, double b, double absEpsilon,
                              double relEpsilon) {
    // Check if the numbers are really close -- needed when comparing numbers
    // near zero.
    double diff{std::abs(a - b)};
    if (diff <= absEpsilon) return true;

    // Otherwise fall back to Knuth's algorithm
    return (diff <= (std::max(std::abs(a), std::abs(b)) * relEpsilon));
}

int main() {
    std::int64_t x[] = {-1, -2, 3, 4, 5, 6};
    for (auto v : x) {
        // std::cout << powint(10, v) << '\n';
        if (isEven(v))
            std::cout << "True" << '\n';
        else
            std::cout << "False" << '\n';
    }

    // std::cout << 6 + 5 * 4 % 3;

    // Operators
    // ? Conditional ternary operator
    int condition{(x[0] > 0) ? static_cast<int>(x[0]) : 0};

    // comparision is as in other languages <, >, ==, >=, <=, !=
    // instead of
    bool b1{true};
    if (b1 == true) b1 = true;
    // write
    if (b1) b1 = true;
    // try to avoid == or != comparisons on floating point as it is unprecise

    // XOR operator is not implemented in cpp, but != can be used for booleans
    // instead
    b1 = (x[0] > 0) != (x[1] > 0);  // != ... to continue adding XOR
    b1 = !!x[0] != !!x[1];

    return 0;
}
