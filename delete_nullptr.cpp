#include <iostream>
#include <vector>

void delete_nullptr() {
    int* array = new int(30);
    delete array;
    array = nullptr;
    delete array;
}

int main() {
    std::cout << "hello word" << std::endl;
    delete_nullptr();
    std::string str("fdsafsadfdsafdsfdsafdsafdsafdasfdsafasdffdfafsdafsfas");
    std::cout << sizeof(str) << std::endl;
    std::cout << str.size() << std::endl;
    std::shared_ptr<int> numInt = std::make_shared<int>(10);
    std::cout << *numInt << std::endl;
    std::cout << sizeof(numInt) << std::endl;

    std::shared_ptr<std::string> strPtr(new std::string("fdasfdsf"));
    std::cout << strPtr->size() << std::endl;
    std::cout << sizeof(strPtr) << std::endl;
    return 0;
}
