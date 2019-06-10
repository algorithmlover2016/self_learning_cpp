#include <iostream>
#include <string> 

#include "basics/macro.h"

inline int const & max(int const & left, int const & right) {
    GET_MSG;
    return left < right ? right : left;
}

template <typename T>
inline T const & max(T const & left, T const & right) {
    GET_MSG;
    return left < right ? right : left;
}

template <typename T>
inline T const & max(T const & left, T const & middle, T const & right) {
    GET_MSG;
    return ::max(::max(left, middle), right);
}


int main() {
    std::cout << "::max(7, 42, 68) " << ::max(7, 42, 68) << std::endl;
    std::cout << "::max(7.0, 42.3) " << ::max(7.0, 42.3) << std::endl;
    // std::cout << "::max(\"abcd\", \"def\") " << ::max("abcd", "def") << std::endl;
    std::string s1("abcd");
    std::string s2("defs");
    std::cout << "::max(\"abcd\", \"def\") " << ::max(s1, s2) << std::endl;
    std::cout << "::max<>(7, 43) " << ::max<>(7, 43) << std::endl;
    std::cout << "::max<double>(7.3, 5.0) " << ::max<double>(7.3, 5.0) << std::endl;
    std::cout << "::max('a', 64.7) " << ::max('a', 64.7) << std::endl;
    return 0;
}
