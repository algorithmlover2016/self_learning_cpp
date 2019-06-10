#ifndef BASICS_MACRO_H
#define BASICS_MACRO_H

#define GET_MSG { \
    std::cout << "call the function " << __DATE__ << " " << __TIME__ << " " << __func__  << std::endl; \
    std::cout <<  __FILE__ << ":" << __LINE__ << ":" << __PRETTY_FUNCTION__ << std::endl; \
}

#endif
