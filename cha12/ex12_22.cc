/*
 * @Author: five-5
 * @Description: the exercise of 12.22
 * @Date: 2019-05-07
 * @LastEditTime: 2019-05-07
 */

#include "ex12_22.h"

#include <fstream>
#include <iostream>

int main()
{
    std::ifstream ifs("book.txt");
    StrBlob blob;
    for (std::string str; std::getline(ifs, str); )
        blob.push_back(str);
    for (ConstStrBlobPtr pbeg(blob.begin()), pend(blob.end()); pbeg != pend; pbeg.incr())
        std::cout << pbeg.deref() << std::endl;
    return 0;
}