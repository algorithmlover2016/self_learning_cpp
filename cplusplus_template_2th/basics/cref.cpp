#include <functional>  // for std::cref()
#include <string>
#include <iostream>

void printString(std::string const& s)
{
  std::cout << s << '\n';
}

template<typename T>
void printT (T arg)
{
  printString(arg);        // might convert arg back to std::string

}

int main() {
  std::string s = "hello";
  printT(s);               // print s passed by value
  printT(std::cref(s));    // print s passed ``as if by reference'', must hava an operation of conversion from std::reference to original type
  // call by value, but pass reference parameters
  std::cout << "pass reference to call by value template" << std::endl;
  std::string & rs = s;
  printT(rs);               // print reference rs passed by value, T will still be std::string, not std::string&
  std::cout << "pass reference to call by value template" << std::endl;
  printT(s);               // print s passed by value

}
