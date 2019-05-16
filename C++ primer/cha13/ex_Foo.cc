/*
 * @Author: five-5
 * @Date: 2019-05-16
 * @Description: 
 * @LastEditTime: 2019-05-16
 */

#include <vector>
#include <algorithm>
#include <iostream>

class Foo {
 public:
    Foo(std::vector<int> &data) : data_(data) {};
    Foo sorted() &&;      // 可用于可改变的右值
    Foo sorted() const &; // 可用于任何类型的Foo
 private:
    std::vector<int> data_;
};

// 本对象为右值，因此可以原址排序
Foo Foo::sorted() &&
{
    std::cout << "&& sort" << std::endl;
    std::sort(data_.begin(), data_.end());
    return *this;
}

// 本对象是const或是一个左值，哪种情况我们都不能对其进行原址排序
// Foo Foo::sorted() const &
// {
//     std::cout << "const & sort" << std::endl;
//     Foo ret(*this);                             // 拷贝一个副本
//     sort(ret.data_.begin(), ret.data_.end());   // 排序副本
//     return ret;                                 // 返回副本
// }

// ex13_56
// Foo Foo::sorted() const &
// {
//     std::cout << "const & sort" << std::endl;
//     Foo ret(*this);                             // 拷贝一个副本
//     return ret.sorted();
// }

// ex_57
Foo Foo::sorted() const &
{
    std::cout << "const & sort" << std::endl;
    return Foo(*this).sorted();
}

int main()
{
    std::vector<int> data;
    data.push_back(1);
    data.push_back(0);
    data.push_back(5);
    data.push_back(3);
    data.push_back(2);

    Foo test(data);
    std::cout << "start test" << std::endl;
    test.sorted();
    std::cout << "end test" << std::endl;

    return 0;
}