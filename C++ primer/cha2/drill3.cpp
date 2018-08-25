#include <iostream>
#include <string>
#include "Sales_data.h"

int main()
{
    Sales_data data1, data2;
    // 读入data1和data2
    std::cin >> data1.bookIsbn >> data1.number >> data1.unitPrice;
    data1.profit = data1.number * data1.unitPrice;
    std::cin >> data2.bookIsbn >> data2.number >> data2.unitPrice;
    data2.profit = data2.number * data2.unitPrice;

    // 检查data1和data2的ISBN是否相同
    if (data1.bookIsbn == data2.bookIsbn)
    {
        // 如果相同，求data1和data2的总和
        Sales_data sum;
        sum.bookIsbn = data1.bookIsbn;
        sum.number = data1.number + data2.number;
        sum.profit = data1.profit + data2.profit;
        // 输出：ISBN、总销售量、平均价格
        std::cout << sum.bookIsbn << " " << sum.number
                  << " " << sum.profit << " ";
        if (sum.number != 0)
            std::cout << sum.profit / sum.number << std::endl;
        else
            std::cout << "(no sales)" << std::endl;
        return 0;
    } else{
    std::cout << "Data must refer to the same ISBN" << std::endl;
    return -1;
    }
}
