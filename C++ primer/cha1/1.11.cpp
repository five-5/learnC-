#include <iostream>

int main()
{
    int val1, val2;

    std::cout << "Input two integer:"<<std::endl;
    std::cin >> val1 >> val2;
    int minn = val1, maxn = val2;
    if (val1 > val2){
        minn = val2;
        maxn = val1;
    }
    int i = minn;
    std::cout << "Numbers in (" << minn << "," << maxn << ")£º" << std::endl;
    while ( i <= maxn){
        std::cout << i << std::endl;
        i++;
    }
    return 0;
}
