#include "vartemplate.hpp"
#include <iostream>

 void print() {
     // zero initialized value
     std::cout << val<long> << '\n'; // OK: prints 42
 }

int main() {
    std::cout << "dval<'c'>: " << dval<'c'> << '\n'; // N has value ’c’ of type 
    arr<10>[0] = 42; // sets first element of global arr
    for (std::size_t i=0; i < arr<10>.size(); ++i) {
        std::cout << "arr<10>[" << i << "]: " << arr<10>[i] << '\n'; // uses values set in
    }
    std::cout << "piDefault<>: " << piDefault<> << '\n'; //outputs a long double
    std::cout << "piDefault<float>: " << piDefault<float> << '\n'; //outputs a float

    std::cout << "pi<float>: " << pi<float> << '\n'; //outputs a float
    std::cout << "pi<double>: " << pi<double> << '\n'; //outputs a double
    // std::cout << "pi<int>: " << pi<int> << '\n'; // type 'double' cannot be narrowed to 'int' in initializer list [-Wc++11-narrowing]

    val<long> = 42;
    print();

}


