// #include "stack1.hpp"
#include "stack_deduction.hpp"

#include <iostream>
#include <string>

int main() {
    Stack intStack = 0;
    std::cout << intStack.empty() << '\n';

    // no matching constructor for initialization of 'std::vector<char [7]>'
    // when copy constructor like Stack(T const & item) without declare Stack(char const*) -> Stack<std::string>;
    // Stack stringStack = "bottom"; 
    Stack stringStack{"bottom"}; // when define copy constructor with reference and declare deduction guides; still can not use assignment sentence like the upper sentence;



    // manipulate int stack
    intStack.push(7);
    std::cout << intStack.top() << '\n';

    // manipulate string stack
    stringStack.push("hello"); // reference to type 'char const[7]' could not bind to an lvalue of type 'const char [6]'
                              // when copy constructor like Stack(T const & item) without declare Stack(char const*) -> Stack<std::string>;
    std::cout << stringStack.top() << '\n';
    stringStack.pop();
}
