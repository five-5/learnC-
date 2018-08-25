#include <iostream>
#include <typeinfo>
#include <cxxabi.h>

int main()
{
    int a = 3, b = 4;
    decltype(a) c = a;
    decltype(a = b) d = a;

    std::cout << "a = " << a << "=>" << abi::__cxa_demangle(typeid(a).name(), nullptr, nullptr, nullptr) << std::endl;
    std::cout << "b = " << b << "=>" << abi::__cxa_demangle(typeid(b).name(), nullptr, nullptr, nullptr) << std::endl;
    std::cout << "c = " << c << "=>" << abi::__cxa_demangle(typeid(c).name(), nullptr, nullptr, nullptr) << std::endl;
    std::cout << "d = " << d << "=>" << abi::__cxa_demangle(typeid(d).name(), nullptr, nullptr, nullptr) << std::endl;

    return 0;
}
