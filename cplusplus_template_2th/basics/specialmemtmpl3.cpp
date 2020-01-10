#include "specialmemtmpl3.hpp"

int main()
{
  std::string s = "sname";
  Person p1(s);              // init with string object => calls TMPL-CONSTR
  std::cout << "p1.getName(): " << p1.getName() << std::endl;
  Person p2("tmp");          // init with string literal => calls TMPL-CONSTR
  std::cout << "p2.getName(): " << p2.getName() << std::endl;

  Person p3(p1);             // OK => calls COPY-CONSTR
  std::cout << "p3(copy constructor from p1).getName(): " << p3.getName() << std::endl;

  Person p4(std::move(p1));  // OK => calls MOVE-CONST
  std::cout << "p4(move constructor from p1).getName(): " << p4.getName() << std::endl;

  Person const p1c("tmp");              // init with string object => calls TMPL-CONSTR
  Person p3c(p1c);              // init with string object => calls TMPL-CONSTR
  std::cout << "p3(const copy constructor from p1).getName(): " << p3c.getName() << std::endl;
}
