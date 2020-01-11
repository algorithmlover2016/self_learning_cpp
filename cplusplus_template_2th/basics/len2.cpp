#include "len2.hpp"
#include <iostream>
#include <vector>


int main() {
    int a[10];
    std::cout << "len(a[10]) : " << len(a) << std::endl;
    int * p = a;
    std::cout << "len(p): " << len(p) << std::endl;
    std::cout << "len(\"temp\"): " << len("tmp") << std::endl;
    
    std::vector<int> v;
    std::cout << "len(v): " << len(v) << std::endl;

    std::allocator<int> all;
    std::cout << "len(all): " << len(all) << std::endl;

}
