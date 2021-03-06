// initializer_list example
#include <iostream>          // std::cout
#include <initializer_list>  // std::initializer_list

template<typename T>
int print(T const & arg) {
    std::cout << arg << '\t';
    return 0;
}

template<typename T, typename... Args>
int print(T const & ele, Args... args) {
    // args of this type can't be iter(loop); 
    // for (auto x : args) { 
    //     std::cout << x << '\t';
    // }

    std::cout << "variable template parameters" << std::endl;
    print(ele); // call the upper print with one template parameters;
    print(args...); // the others recursive call this print
    return 0;
}

int main () {

  std::initializer_list<int> mylist{20,50,80,90};
  // mylist = { 10, 20, 30, 40 };
  std::cout << "mylist contains:";
  for (int x: mylist) std::cout << ' ' << x;
  std::cout << '\n';
  std::cout << "begin to execute print" << std::endl;
  print(10, 20, 30, 40);
  std::cout << '\n';
  return 0;
}

// compile command
// g++ -std=c++11 -o main_variable_template_parameters variable_template_parameters.cpp

// reference:
// https://songlee24.github.io/2014/07/22/cpp-changeable-parameter/
// http://www.cplusplus.com/reference/initializer_list/initializer_list/begin/
/*
   // initializer_list::begin/end
#include <iostream>          // std::cout
#include <string>            // std::string
#include <sstream>           // std::stringstream
#include <initializer_list>  // std::initializer_list

struct myclass {
  std::string str;
  myclass(std::initializer_list<int> args) {
    std::stringstream ss;
    std::initializer_list<int>::iterator it;  // same as: const int* it
    for ( it=args.begin(); it!=args.end(); ++it) ss << ' ' << *it;
    str = ss.str();
  }
};

int main ()
{
  myclass myobject {10, 20, 30};
  std::cout << "myobject contains:" << myobject.str << '\n';
  return 0;
}
*/
