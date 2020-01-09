#include "varindices.hpp"
#include <iostream>
#include <string>
// for std::get
#include <tuple>
#include <array>
#include <variant>
#include <utility>
// for get done
#include <vector>

int main() {
    // index type...
    std::vector<std::string> coll = {"good", "times", "say", "bye"};
    print("call printElems, template<typename C, typename... Idx>");
    printElems(coll,2,0,3);

    // index nontype parameters
    print("call printIdx template<std::size_t... Idx, typename C>");
    printIdx<2,0,3>(coll);

    // get array and tuple
    std::array<std::string, 5> arr = {"Hello", "my", "new", "!", "World"};
    print("call printByIdx template<typename T, std::size_t... Idx> void printByIdx(T t, Indices<Idx...>)");
    printByIdx(arr, Indices<0, 4, 3>());

    print("call printIdx template<std::size_t... Idx, typename C>");
    printIdx<0,4,3>(arr);

    auto t = std::make_tuple(12, "monkeys", 2.3);
    print("call printByIdx template<typename T, std::size_t... Idx> void printByIdx(T t, Indices<Idx...>)");
    printByIdx(t, Indices<0, 1, 2>());
    // tuple can not be get by []
    // type 'const std::__1::tuple<int, const char *, double>' does not provide a subscript operator
    // print("call printIdx template<std::size_t... Idx, typename C>");
    // printIdx<0, 1, 2>(t);
    // printByTypes(t, 0, "1", "2.3");

}

