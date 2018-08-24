#include <iostream>
#include "Sales_item.h"

int main()
{
    Sales_item book, sum;

    if (std::cin >> sum){
        while (std::cin >> book)
            sum += book;
    }
    std::cout << sum << std::endl;
    return 0;
}
/*
0-201-78456-X 3 20.00
0-201-78456-X 6 25.00
0-201-78456-X 8 23.00
*/
