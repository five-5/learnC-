#include <iostream>
#include "Sales_item.h"

int main()
{
    Sales_item book;
    // ����ISBN�š��۳��Ĳ����Լ����ۼ۸�
    while (std::cin >> book)
    // д��ISBN�š��۳��Ĳ����������۶��ƽ���۸�
        std::cout << book << std::endl;
    return 0;
}
