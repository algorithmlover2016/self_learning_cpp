#ifndef CLASS_TEMPLATE_STACK_HPP
#define CLASS_TEMPLATE_STACK_HPP
#include <vector>
#include <stdexcept>

template <typename T>
class Stack {
    private:
        std::vector<T> _eles;
        //  candidate constructor not viable: requires 1 argument, but 0 were provided
        Stack(Stack<T> const &) = delete;
        Stack<T>& operator=(Stack<T> const &) = delete;
    public:
        Stack() {}
        void push(T const & ele);
        void pop();
        T top() const;
        bool empty() const {
            return _eles.empty();
        }
};

template <typename T>
void Stack<T>::push(T const & ele) {
    _eles.push_back(ele);
}

template <typename T>
void Stack<T>::pop() {
    if (_eles.empty()) {
        throw std::out_of_range("Stack<>::pop(): empty stack");
    }
    _eles.pop_back();
}

template <typename T>
T Stack<T>::top() const {
    if (_eles.empty()) {
        throw std::out_of_range("Stack<>::top(): empty stack");
    }
    return _eles.back();
}

#endif // CLASS_TEMPLATE_STACK_HPP
