#include <iostream>
#include <typeinfo>
#include <cxxabi.h>

int main()
{
    const int i = 42;
    auto j = i;
    const auto &k = i;
    auto *p = &i;
    const auto j2 = i, &k2 = i;

    int integer;
    const int const_integer = 0;
    int *intptr = 0;
    const int &const_quot = const_integer;

    // typeid�ǲ�����
    // typeid���ڱ���ʱ��ʶ��ģ�ֻ���������ͲŻ�������ʱʶ��
    // ��gcc��int������ʾΪi, vc ��ʾΪint��ͨ��__cxa_demangle������ԭ��ʾ
    std::cout << "the type of int is " << abi::__cxa_demangle(typeid(integer).name(), nullptr, nullptr, nullptr) << std::endl;
    std::cout << "the type of const int is " << abi::__cxa_demangle(typeid(const_integer).name(), nullptr, nullptr, nullptr) << std::endl;
    std::cout << "the type of int* is " << abi::__cxa_demangle(typeid(intptr).name(), nullptr, nullptr, nullptr) << std::endl;
    std::cout << "the type of const int& is " << abi::__cxa_demangle(typeid(const_quot).name(), nullptr, nullptr, nullptr) << std::endl << std::endl;

    std::cout << "the type of i is " << abi::__cxa_demangle(typeid(i).name(), nullptr, nullptr, nullptr) << std::endl;
    std::cout << "the type of j is " << abi::__cxa_demangle(typeid(j).name(), nullptr, nullptr, nullptr) << std::endl;
    std::cout << "the type of k is " << abi::__cxa_demangle(typeid(k).name(), nullptr, nullptr, nullptr) << std::endl;
    std::cout << "the type of p is " << abi::__cxa_demangle(typeid(p).name(), nullptr, nullptr, nullptr) << std::endl;
    std::cout << "the type of j2 is " << abi::__cxa_demangle(typeid(j2).name(), nullptr, nullptr, nullptr) << std::endl;
    std::cout << "the type of k2 is " << abi::__cxa_demangle(typeid(k2).name(), nullptr, nullptr, nullptr) << std::endl;

    return 0;
}
