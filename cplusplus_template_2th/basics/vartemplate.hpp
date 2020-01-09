#include <array>
// variable templates are a C++14 extension [-Werror,-Wc++14-extensions]

template<typename T>
constexpr T pi{3.1415926535897932385};

template<typename T = long double>
constexpr T piDefault = T{3.1415926535897932385};

template<typename T>
T val{};


template<int N>
std::array<int,N> arr{}; // array with N elements, zero-

// 'auto' not allowed in template parameter until C++17
template<auto N>
constexpr decltype(N) dval = N; // type of dval depends on passed value
