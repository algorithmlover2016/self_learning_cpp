#include <type_traits>

/* true ? :
In the expression true ? std::declval<_Tp>() : std::declval<_Up>() the first alternative is always selected, but the whole expression must be a valid expression. So std::declval<_Up>() must be valid and that means _Up must be a callable that accepts zero arguments. Beside that, _Tp() and _Up() must return the same type (or one of the types must be implicitly convertible to another), otherwise ternary iterator would not be able to select return value.

This technique is called SFINAE (substitution failure is not an error). The idea is that if template instantiation fails, then it is not an error, and this template is just ignored and compiler searches for another one.
*/
template<typename T1, typename T2>
auto max (T1 a, T2 b) -> typename std::decay<decltype(true?a:b)>::type {
  return  b < a ? a : b;
}
