#include "addspace.hpp"
#include <iostream>
// c++17
;

template<typename... Args>
void printDouble (Args const & ... args) {
    print(args + args...);
}

template<typename... Args>
void addOne (Args const & ... args) {
    print(args + 1 ...); // must add one space between 1 and ...
    print("other way to add one to each parameters");
    print((args + 1)...);
}


