#include <iostream>
#include <cstring>
#include <string>

#include "basics/macro.h"

template <typename T>
inline T const & max(T const & left, T const & right) {
    GET_MSG;
    return left < right ? right : left;
}

template <typename T>
inline T * const & max( T * const & left, T * const & right) {
    GET_MSG;
    return *left < *right ? right : left;
}

inline char const * const & max(char const * const  & left, char const * const & right) {
    GET_MSG;
    return std::strcmp(left, right) < 0 ? right : left;
}

// error define, not T*
template <typename T>
inline T const * const & max(T const * const & left, T const * const & middle, T const * const & right) {
    GET_MSG;
    return ::max(left, ::max(middle, right));
}

template <typename T>
inline T const & max(T const & left, T const & middle, T const & right) {
    GET_MSG;
    return ::max(left, ::max(middle, right));
}

void println(const std::string & msg) {
    std::cout << msg << std::endl;
}

int main() {
    int a = 7, b = 42;
    std::cout << "::max(7, 42) " << ::max(a, b) << std::endl;

    std::string s1("fadfsaf");
    std::string s2("fadfsftqegdfaf");
    std::cout << "::max(s1, s2) " << ::max(s1, s2) << std::endl;

    int * p1 = &a, *p2 = &b;
    std::cout << "::max(p1, p2) " << ::max(p1, p2) << std::endl;

    std::cout << "::max(\"fasfs\", \"dasfeaf\") " << ::max("fasfs", "dasfeaf") << std::endl;

    println("fesafsfaferdf");

    std::cout << "::max(7, 69, 32) " << ::max(7, 69, 32) << std::endl;
    std::cout << "::max(\"ffadsasfsfss\", \"fdfasffasfsaf\", \"fteqgdfs\")" << ::max<char const *>("ffadsasfsfss", "fdfasffasfsaf", "fteqgdfs") << std::endl;
    // compile error. first, "fasfsfs" defualt conflict type is char const [8], and "fdasfsaf" default conflict type is char const [9], and
    // "fteqgdfsafasf" default conflict type is char const [14];
    // char const [8] is not equal to char const [9], and is also not equal to char const [14]
    // std::cout << "::max(\"fasfsfs\", \"fdasfsaf\", \"fteqgdfsafasf\")" << ::max("fasfsfs", "fdasfsaf", "fteqgdfsafasf") << std::endl;

    // compile error. the inner ::max returning the type is T const * const (char const * const &), and the outer ::max have two parameters,
    // whose type are char const[9] and char const * const &, respectively.
    // std::cout << "::max(\"fadsfsfs\", \"fdasfsaf\", \"fteqgdsa\")" << ::max("fadsfsfs", "fdasfsaf", "fteqgdsa") << std::endl;

    char const * chr1 = "fdsafsdf";
    char const * chr2 = "fdsfgdsfafsdf";
    char const * chr3 = "fdsfdsafasfaafsdf";
    std::cout << "::max(chr1, chr2, chr3)" << ::max(chr1, chr2, chr3) << std::endl;

    return 0;
}
