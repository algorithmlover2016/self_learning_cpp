/*
   template function simple example max()
   */

#ifndef BASICS_MAX_HPP
#define BASICS_MAX_HPP
template <typename T>
inline T const & max(T const & left, T const & right) {
    return left < right ? right : left;
}

#endif
