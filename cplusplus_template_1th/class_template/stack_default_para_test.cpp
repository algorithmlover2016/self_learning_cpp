#include <iostream>
#include <deque>
#include <cstdlib>

#include "class_template/default_template_para_stack.hpp"

int main() {

    try {
        StackDefaultParam<int> intStack;
        intStack.push(7);
        std::cout << intStack.top() << std::endl;
        intStack.pop();

        StackDefaultParam<double, std::deque<double> > dblStack;
        dblStack.push(42.42);
        std::cout << dblStack.top() << std::endl;
        dblStack.pop();
        dblStack.pop();
    }catch (std::exception const & ex) {
        std::cerr << "Exception: " << ex.what() << std::endl;
        return EXIT_FAILURE;
    }
    return 0;
}
