#include <iostream>

template<int N, int M> 
bool less (char const(&a)[N], char const(&b)[M])
{
    std::cout << "call specialized char const function " << __func__ << std::endl;
    for (int i = 0; i<N && i<M; ++i) {
        if (a[i]<b[i]) return true;
        if (b[i]<a[i]) return false;
    }
    return N < M;
}
