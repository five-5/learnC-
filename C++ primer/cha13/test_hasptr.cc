/*
 * @Author: five-5
 * @Date: 2019-05-20
 * @Description: test
 * @LastEditTime: 2019-05-20
 */

#include <iostream>
#include <vector>
#include <algorithm>

#include "HasPtr.h"

int main()
{
    HasPtr a{"a"}, s{"s"}, b{"b"};
    std::vector<HasPtr> vec{a, s,b};
    std::sort(vec.begin(), vec.end());
    for (auto v : vec) {
        v.show();
    }
    return 0;
}