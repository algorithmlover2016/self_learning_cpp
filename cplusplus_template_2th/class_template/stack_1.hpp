#ifndef CLASS_TEMPLATE_STACK_1_HPP_
#define CLASS_TEMPLATE_STACK_1_HPP_
#include <vector>

template <typename T>
class Stack {
    private:
        std::vector<T> _elems;
    public:
        void push(T const & ele);
        void pop();
        T top() const;
        bool empty() const {
            return _elems.empty();
        }
}
template <typename T>
void Stack<T>::push(T const & ele) {
    _elems.push_back(ele);
}

template <typename T>
void Stack<T>::pop() {
    if (empty()) {
        throw std::out_of_range("Stack<>::pop(): empty stack");
    }
    _elems.pop_back();
}

template <typename T>
T 

#endif
