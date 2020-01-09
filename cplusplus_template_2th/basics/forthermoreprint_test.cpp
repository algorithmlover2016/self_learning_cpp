#include "forthermoreprint.hpp"
#include <iostream>
#include <string>
#include <complex>

int main() {
    print("7.5, std::string(\"hello\"), std::complex<float>(4,2) double ");
    printDouble(7.5, std::string("hello"), std::complex<float>(4,2));
    print("7.5, 80, 90, 34.56, -23 add one ");
    addOne(7.5, 80, 90, 34.56, -23);

}
