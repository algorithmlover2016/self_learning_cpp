#include <utility>
#include <iostream>
#include <typeinfo> // typeid

class X {
  //...
};

// can not define this template function to call pointers by reference; template<typename T> T * &  max(T * & a, T* & b) {
template<typename T>
T *  max(T *  a, T*  b) {
    std::cout << "call T* template function" << std::endl;
    std::cout << "typeid(a).name(): " << typeid(a).name() << std::endl;
    std::cout << "typeid(b).name(): " << typeid(b).name() << std::endl;
    return *b > *a ? b : a;
}

template<typename T>
T & max(T & a, T & b) {
    std::cout << "call T & template function" << std::endl;
    std::cout << "typeid(a).name(): " << typeid(a).name() << std::endl;
    std::cout << "typeid(b).name(): " << typeid(b).name() << std::endl;
    return b > a ? b : a;
}

void g (X& val) {
  std::cout << "g() for variable\n";
    std::cout << "typeid(val).name(): " << typeid(val).name() << std::endl;
}
void g (X const& val) {
  std::cout << "g() for constant\n";
    std::cout << "typeid(val).name(): " << typeid(val).name() << std::endl;
}
void g (X&& val) {
  std::cout << "g() for movable object\n";
    std::cout << "typeid(val).name(): " << typeid(val).name() << std::endl;
}

template<typename T>
void gTemplate(T&& val) {
    std::cout << "typeid(val).name(): " << typeid(val).name() << std::endl;
    std::cout << "call template g function: " << __func__ << std::endl;
}

// let f() perfect forward argument val to g():
template<typename T>
void f (T&& val) {
    std::cout << "call function: " << __func__ << std::endl;
    // std::forward<T>(val) get by typeid.name() is 1X
    g(std::forward<T>(val));   // call the right g() for any passed argument val
    gTemplate(std::forward<T>(val));
}

int main()
{
    X v;              // create variable
    X const c;        // create constant

    f(v);             // f() for variable calls f(X\&)  =>  calls g(X\&)
    f(c);             // f() for constant calls f(X const\&)  =>  calls g(X const\&)
    f(X());           // f() for temporary calls f(X\&\&)  =>  calls g(X\&\&)
    f(std::move(v));  // f() for move-enabled variable calls f(X\&\&)  =>  calls g(X\&\&)
    int const i = 40;
    int j = 60;
    int & k = j;
    std::cout << "typeid(k).name(): " << typeid(k).name()  << std::endl;
    std::cout << "::max(i, i): " << ::max(i, i) << std::endl;
    // std::cout << "::max(i, j): " << ::max(i, j) << std::endl; // error : candidate template ignored: deduced conflicting types for parameter 'T' ('const int' vs. 'int')
    // std::cout << "::max(i, k): " << ::max(i, k) << std::endl; // error :  candidate template ignored: deduced conflicting types for parameter 'T' ('const int' vs. 'int')
    std::cout << "::max(j, k): " << ::max(j, k) << std::endl;
    std::cout << "::max(k, k): " << ::max(k, k) << std::endl;
    // int * p = &j;
    // std::cout << "::max(p, j): " << ::max(p, j) << std::endl; // error : candidate template ignored: deduced conflicting types for parameter 'T' ('int *' vs. 'int')
    double x = 50.506, y = 23344.0442;;
    std::cout << "::max(x, y): " << ::max(x, y) << std::endl;
    // std::cout << "::max(&x, &y): " << ::max(&x, &y) << std::endl; // candidate function [with T = double *] not viable: no known conversion from 'double *' to 'double *&' for 1st argument when no define T *; only call T*
    std::cout << "::max(\"hello\", \"world\"): " << ::max("hello", "world!") << std::endl; // call T* template function first, PKc typeid.nam(); if not defining T*, and length is same, call T &, type is  A6_c; otherwise  candidate template ignored: deduced conflicting types for parameter 'T' ('char const[6]' vs. 'char const[7]')
    typedef double * DP;
    // double *  dpx = &x, *dpy = &y;
    DP dpx = &x, dpy = &y;
    std::cout << "::max(dpx, dpy): " << ::max(dpx, dpy) << std::endl; // call T* template function first, if not defined, call T; function behavior changed
    DP & dprx = dpx, & dpry = dpy;
    std::cout << "typeid(dprx).name(): " << typeid(dprx).name() << std::endl;
    std::cout << "::max(dprx, dpry): " << ::max(dprx, dpry) << std::endl; // call T* template function first, if not defined, call T
}
