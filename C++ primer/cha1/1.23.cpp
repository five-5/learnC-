#include <iostream>
#include "Sales_item.h"

int main()
{
    Sales_item currItem, item;
    int times = 1;
    if (std::cin >> currItem){
        while (std::cin >> item){
            if (item.isbn() == currItem.isbn()){
                times++;
            } else{
            std::cout << currItem.isbn() << " occurs " << times << " times" << std::endl;
            currItem = item;
            times = 1;
            }
        }
        std::cout << currItem.isbn() << " occurs " << times << " times" << std::endl;
    }
    return 0;
}
