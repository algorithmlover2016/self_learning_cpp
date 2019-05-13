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
    return 0;
}
