#include "stack1.hpp"
#include <deque>
#include <string>
#include <cassert>

// add log information
#include <iostream>

template<>
class Stack<std::string> {
  private:
    std::deque<std::string> elems;  // elements

  public:
    void push(std::string const&);  // push element
    void pop();                     // pop element
    std::string const& top() const; // return top element
    bool empty() const {            // return whether the stack is empty
        return elems.empty();
    }
};

void Stack<std::string>::push (std::string const& elem)
{
    std::cout << "call specialization string template class [" << __func__ << "]" << std::endl;
    elems.push_back(elem);    // append copy of passed elem
}

void Stack<std::string>::pop ()
{
    std::cout << "call specialization string template class [" << __func__ << "]" << std::endl;
    assert(!elems.empty());
    elems.pop_back();         // remove last element
}

std::string const& Stack<std::string>::top () const
{
    std::cout << "call specialization string template class [" << __func__ << "]" << std::endl;
    assert(!elems.empty());
    return elems.back();      // return copy of last element
}
