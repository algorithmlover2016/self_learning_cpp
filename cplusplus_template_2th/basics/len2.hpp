#include <iostream>
// number of elements in a raw array:
template<typename T, unsigned N>
std::size_t len (T(&)[N]) 
{ 
    std::cout << "call template<typename T, unsigned N> function " << __func__ << std::endl; 
  return N;
}

// // number of elements for a type having size_type:
// template<typename T>
// typename T::size_type len (T const& t) {  // can accept std::vector<int>
//   return t.size();
// }

// template<typename T>
// auto len(T const & t) -> decltype( (void)(t.size()), T::size_type() ) {
template<typename T>
auto len (T const& t) -> decltype((void)(t.size()), typename T::size_type()) { // must have typename keyword, otherwise
                                                                               // candidate template ignored: substitution failure [with T = std::__1::vector<int, std::__1::allocator<int> >]:
                                                                               // missing 'typename' prior to dependent type name 'vector<int, allocator<int> >::size_type'
    std::cout << "call template<typename T> function auto-> " << __func__ << std::endl;
    return t.size();
}

// fallback for all other types:
std::size_t len (...) { 
    std::cout << "call ... function " << __func__ << std::endl;
    return 0;
}
