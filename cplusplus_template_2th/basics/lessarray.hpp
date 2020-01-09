#include <iostream>

template<typename T, int N, int M> 
bool less (T(&a)[N], T(&b)[M])
{
    std::cout << "call template<typename T, int N, int M> function " << __func__ << std::endl;
    for (int i = 0; i<N && i<M; ++i) {
        if (a[i]<b[i]) return true;
        if (b[i]<a[i]) return false;
    }
    return N < M;
}
