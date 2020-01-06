#include <iostream>
#include <string>
#include <cstdlib>

#include "class_template/stack.hpp"

int main() {
    try {
        Stack<int> intStack;
        intStack.push(7);
        std::cout << intStack.top() << std::endl;

        Stack<std::string> strStack;
        strStack.push("hello template!");
        std::cout << strStack.top() << std::endl;
        strStack.pop();
        strStack.pop();
    } catch (std::exception const & ex) {
        std::cerr << "Exception: " << ex.what() << std::endl;
        return EXIT_FAILURE;
    }
    return 0;
}
