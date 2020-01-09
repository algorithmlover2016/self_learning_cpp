#include "lessarray.hpp"
#include "lessstring.hpp" // just like an specialization of less array

#include <iostream>

int main() {
    int x[] = {1, 2, 3};
    int y[] = {1, 2, 3, 4, 5};
    std::cout << less(x,y) << '\n';
    std::cout << less("ab","abc") << '\n';
}
