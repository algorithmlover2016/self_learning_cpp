#include <iostream>
#include <string>

#include "basics/max.hpp"

int main() {
    int i = 42;
    std::cout << "max(7, " << i << "): " << ::max(7, i) << std::endl;

    double d1 = 3.14;
    double d2 = -6.23;
    std::cout << "max(" << d1 << ", " << d2 << "): " << ::max(d1, d2) << std::endl;

    std::string s1 = "hello world!";
    std::string s2 = "hello template!";
    std::cout << "max(\"" << s1 << "\", \"" << s2 << "\"): " << ::max(s1, s2) << std::endl;

    return 0;
}
