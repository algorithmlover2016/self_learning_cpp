#include <vector>
#include <cassert>
#include <iostream>

template<typename T>
class Stack {
  private:
    std::vector<T> elems;      // elements

  public:
    Stack() = default;
    // copy constructor call by value to decay the right template parameter which is char const * without declare Stack(char const*) -> Stack<std::string>;
    // Stack(T const item) : elems({std::move(item)}) {
    // }

    // You can define specific deduction guides to provide additional or fix existing class template argument deductions. 
    // when declare Stack(char const*) -> Stack<std::string>;
    Stack(T const & item) : elems({item}) {
    }

    void push(T const& elem);  // push element
    void pop();                // pop element
    T const& top() const;      // return top element
    bool empty() const {       // return whether the stack is empty
        return elems.empty();
    }
};

Stack(char const*) -> Stack<std::string>;

template<typename T>
void Stack<T>::push (T const& elem)
{
    std::cout << "call basic tempate class member: [" << __func__ << "]" << std::endl;
    elems.push_back(elem);     // append copy of passed elem
}

template<typename T>
void Stack<T>::pop ()
{
    std::cout << "call basic tempate class member: [" << __func__ << "]" << std::endl;
    assert(!elems.empty());
    elems.pop_back();          // remove last element
}

template<typename T>
T const& Stack<T>::top () const
{
    std::cout << "call basic tempate class member: [" << __func__ << "]" << std::endl;
    assert(!elems.empty());
    return elems.back();       // return copy of last element
}
