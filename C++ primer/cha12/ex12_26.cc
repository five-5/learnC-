/*
 * @Author: five-5
 * @Description: exercise12.26
 * @Date: 2019-05-08
 * @LastEditTime: 2019-05-08
 */

#include <string>
#include <memory>
#include <iostream>

#define N 3

int main()
{
    std::allocator<std::string> alloc;
    auto const p = alloc.allocate(N);
    std::string s;
    auto q = p;
    
    while ( q!= p + N && std::cin >> s) { // care about the sequence of two statements
        alloc.construct(q++, s);
    }
    
    const size_t size = q - p;

    std::cout << "enter " << size << " strings" << std::endl;
    
    while (q != p) {
        std::cout << *--q << " ";
        alloc.destroy(q);
    }

    alloc.deallocate(p, N);
    return 0;
}