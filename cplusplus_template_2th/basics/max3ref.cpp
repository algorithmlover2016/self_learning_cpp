#include <cstring>
#include <iostream>
#include <string>

// maximum of two values of any type (call-by-reference)
template<typename T>
T const & max (T const& a, T const& b) {
    std::cout << "call template function two values of any type " << __func__ << std::endl;
    return  b < a ? a : b;
}

// if defining this max overload, then the non-template < char const* max(char const* &a, char const* &b) > will not be called
// when calling max(s1, s2, s3). And there will be an error[warning] when call max(s1, s2, s3), which is :
// in instantiation of function template specialization 'max<char>' requested here and
// reference to stack memory associated with parameter 'a' returned [-Wreturn-stack-address]

// template<typename T>
// T const * const& max (T const* a, T const* b) {
//     std::cout << "call template function two values of any type pointer " << __func__ << std::endl;
//   return  b < a ? a : b;
// }

/*
   the upper two overload template functions show that if you define 
   template<typename T>
   T const & max (T const& a, T const& b);
   and 
   template<typename T>
   T const * const& max (T const* a, T const* b);

   these two function can't deal with char const * template parameter when recursively call the function.
 */

// must define the type with reference, otherwise will get reference to stack memory associated with parameter 'b|[a]' returned [-Wreturn-stack-address]
// maximum of two C-strings (call-by-value)
// But when define with reference, it will never be called
char const* & max (char const* & a, char const* & b) {
    std::cout << "call non-template function " << __func__ << std::endl;
    return  std::strcmp(b,a) < 0  ? a : b;
}

// maximum of three values of any type (call-by-reference)
template<typename T>
T const& max (T const& a, T const& b, T const& c) {
    return max (max(a,b), c);       // error if max(a,b) uses call-by-value
}

int main () {
    auto m1 = ::max(7, 42, 68);     // OK
    std::cout << "::max(7, 42, 68) " << m1 << std::endl;

    char const* s1 = "frederic";
    char const* s2 = "anica";
    char const* s3 = "lucas";
    auto m2 = ::max(s1, s2, s3);    // run-time ERROR || -Wreturn-stack-address if define this char const*  max (char const*  a, char const*  b);
    std::cout << "::max(s1, s2, s3) " << m2 << std::endl;
}
