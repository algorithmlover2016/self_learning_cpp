#include <iostream>
#include <string>

// remind that template member won't hide the predefined copy move assin constructor, because they are instances of these template;
class C {
public:
    template<typename T>
    C (T &&) {
        std::cout << "tmpl move constructor\n";
    }

    template<typename T>
    C (T const &) { // the predefined copy constructor is a specialization of this template, if it's used as copy constructor
        std::cout << "tmpl copy constructor\n";
    }

    void getStr() const {
        std::cout << "test C class" << std::endl;
    }
};


template<typename T>
class CC {
public:
      // user-define the predefined copy constructor as deleted // (with conversion to volatile to enable better matches)
      CC(T const &) {
          std::cout << "default constructor" << std::endl;
      }
      CC(CC const volatile&) = delete; // just delete ignored copy constructor, which means std::is_integral<U>::value = true;
                                       // if not declaring this, copy constructor will call predefined copy constructor instead calling tmpl
      // CC(CC const&) = delete; // delete all copy constructor and lead to copy error
      // if T is no integral type, provide copy constructor template with better match:
      template<typename U,
             typename  = std::enable_if_t<!std::is_integral<U>::value>>
      CC(CC<U> const&) {
          std::cout << "tmpl copy constructor" << std::endl;
      }
      void getStr() const {
          std::cout << "test CC class" << std::endl;
      }
};

int main() {
    C x(40.4);
    std::cout << "y begin to copy" << std::endl;
    C y{x}; // call predefined copy constructor if you don't define template<typename T> C (T &&)
    std::cout << "y done to copy" << std::endl;
    C const z(40.5);
    std::cout << "w begin to copy" << std::endl;
    C w(z);
    std::cout << "w done to copy" << std::endl;
    x.getStr();
    y.getStr();
    z.getStr();
    w.getStr();

    CC xx(55.5);
    CC yy{xx};
    xx.getStr();
    yy.getStr();

    // CC zz(55);
    // CC ww{zz}; // can't copy because the predefined copy constructor is deleted
    // zz.getStr();
    // ww.getStr();
    return 0;
}
