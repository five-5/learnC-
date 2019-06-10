/*
 * @Author: five-5
 * @Date: 2019-06-10
 * @Description: test for Blob template class
 * @LastEditTime: 2019-06-11
 */

#include <iostream>

#include "Blob.hpp"

int main()
{
    Blob<int> squares = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    for (size_t i = 0; i != squares.size(); ++i) {
        squares[i] = i * i;
    }
    
    for (size_t i = 0; i != squares.size(); ++i) {
        printf("squares[%d] = %d\n", i, squares[i]);
    }
    return 0;
}