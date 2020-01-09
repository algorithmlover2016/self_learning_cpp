#include "arrays.hpp"

template<typename T1, typename T2, typename T3>
void foo(int a0[42], int a1[7], int a2[],    // pointers by language rules
         int (&a3)[42],          // reference to array of known bound
         int (&x0)[],            // reference to array of unknown bound
         T1 x1,                  // passing by value decays
         T2& x2, T3&& x3)        // passing by reference
{
    std::cout << "call function " << __func__ << std::endl;
    MyClass<decltype(a0)>::print();     // uses MyClass<T*> because the parameter is translated by pointer
    MyClass<decltype(a1)>::print();     // uses MyClass<T*>
    MyClass<decltype(a2)>::print();     // uses MyClass<T*>
    MyClass<decltype(a3)>::print();     // uses MyClass<T(\&)[SZ]>
    MyClass<decltype(x0)>::print();     // uses MyClass<T(\&)[]>
    MyClass<decltype(x1)>::print();     // uses MyClass<T*>
    MyClass<decltype(x2)>::print();     // uses MyClass<T(\&)[]>
    MyClass<decltype(x3)>::print();     // uses MyClass<T(\&)[]>
}

int main() {
    int a[42];
    MyClass<decltype(a)>::print();      // uses MyClass<T[SZ]>

    extern int x[];                     // forward declare array
    MyClass<decltype(x)>::print();      // uses MyClass<T[]>

    foo(a, a, a, a, x, x, x, x);
}

int x[] = {0, 8, 15};                 // define forward-declared array
