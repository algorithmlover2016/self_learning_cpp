#include "addspace.hpp"
#include <iostream>
#include <string>
// for std::get
#include <tuple>
#include <array>
#include <variant>
#include <utility>
// for get done

template<typename C, typename... Idx>
void printElems (C const & coll, Idx ... idx) {
    print (coll[idx]...);
}

template<std::size_t... Idx, typename C>
void printIdx (C const& coll) {
    print(coll[Idx]...);
}

// type for arbitrary number of indices:
template<std::size_t...> struct Indices {
};

template<typename T, std::size_t... Idx>
void printByIdx(T t, Indices<Idx...>) {
    print(std::get<Idx>(t)...);
}

// template<typename T, typename... Types>
// void printByTypes(T t, Types const &... types) {
//     (std::cout << ... << (decltype(types))) << std::endl;
//     // print(std::get<decltype(types)>(t)...);
// }
