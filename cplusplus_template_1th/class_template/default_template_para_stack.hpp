#ifndef CLASS_TEMPLATE_DEFAULT_TEMPLATE_PARA_STACK_HPP
#define CLASS_TEMPLATE_DEFAULT_TEMPLATE_PARA_STACK_HPP

#include <vector>
#include <stdexcept>
template <typename T, typename CONT = std::vector<T> >
class StackDefaultParam {
    private:
        CONT _eles;
    public:
        void push(T const &);
        void pop();
        T top() const;
        bool empty() const {
            return _eles.empty();
        }
};

template <typename T, typename CONT>
void StackDefaultParam<T, CONT>::push(T const & ele) {
    _eles.push_back(ele);
}

template <typename T, typename CONT>
T StackDefaultParam<T, CONT>::top() const {
    if (_eles.empty()) {
        throw std::out_of_range("Stack<>::top(): empty stack");
    }
    return _eles.back();
}

template <typename T, typename CONT>
void StackDefaultParam<T, CONT>::pop() {
    if (_eles.empty()) {
        throw std::out_of_range("Stack<>::pop(): empty stack");
    }
    _eles.pop_back();
}

#endif  // CLASS_TEMPLATE_DEFAULT_TEMPLATE_PARA_STACK_HPP
