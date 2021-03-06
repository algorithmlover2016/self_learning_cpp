#include <iostream>
#include <vector>
#include <string>
#include "foreachinvoke.hpp"
#include "invokeret.hpp"

// a function to call:
void func(int i) {
  std::cout << "func() called for: " << i << '\n';
}

// a class with a member function that shall be called
class MyClass {
  public:
    void memfunc(int i) const {
      std::cout << "MyClass::memfunc() called for: " << i << '\n';
    }
};

int main()
{
  std::vector<int> primes = { 2, 3, 5, 7, 11, 13, 17, 19 };

  // pass lambda as callable and an additional argument:
  foreach(primes.begin(), primes.end(),          // elements for 2nd arg of lambda
          [](std::string const& prefix, int i) { // lambda to call
            std::cout << prefix << i << '\n';
          },
          "- value: ");                          // 1st arg of lambda

  foreach(primes.begin(), primes.end(),          // elements for 2nd arg of lambda
          [](std::string const& prefix, int i) { // lambda to call
            std::cout << prefix << i << '\n';
          },
          "--value: ");
    
  call(func, 30);
  // foreach(primes.begin(), primes.end(),          // elements for 2nd arg of lambda
  //         call, func);

  // call obj.memfunc() for/with each elements in primes passed as argument
  MyClass obj;
  foreach(primes.begin(), primes.end(),  // elements used as args
          &MyClass::memfunc,              // member function to call; Attention: if not writing &,  call to non-static member function without an object argument
          obj);                          // object to call memfunc() for; or &obj

  foreach(primes.begin(), primes.end(),  // elements used as args
          func);

  foreach(primes.begin(), primes.end(),  // elements used as args
          &func);

  // callable function can be function name or &function_name; member must have &
}
