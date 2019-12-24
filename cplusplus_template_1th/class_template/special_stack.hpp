#ifndef CLASS_TEMPLATE_SPECIAL_STACK_HPP
#define CLASS_TEMPLATE_SPECIAL_STACK_HPP
#include <deque>
#include <string>
#include <stdexcept>
#include "class_template/stack.hpp"

template<>
class Stack<std::string> {
    private:
        std::deque<std::string> _eles;
    public:
        void push(std::string const &);
        void pop();
        std::string top() const;
        bool empty() const {
            return _eles.empty();
        }
};

void Stack<std::string>::push(std::string const & ele) {
    _eles.push_back(ele);
}

void Stack<std::string>::pop() {
    if (_eles.empty()) {
        throw std::out_of_range("Stack<std::string>::pop(): empty() stack");
    }
    _eles.pop_back();
}

std::string Stack<std::string>::top() const {
    if (_eles.emtpy()) {
        throw std::out_of_range("Stack<std::string>::top(): empty() stack");
    }
    return _eles.back();
}

#endif
