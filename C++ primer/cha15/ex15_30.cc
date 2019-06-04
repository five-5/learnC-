/*
 * @Author: five-5
 * @Date: 2019-06-04
 * @Description: exer for 15.30
 * @LastEditTime: 2019-06-05
 */

#include <fstream>

#include "Basket.h"

int main()
{
    Basket basket;
    for (int i = 0; i != 15; ++i) {
        basket.add_item(Quote("0-201-82470-1", 50));
        basket.add_item(Bulk_quote("0-201-54848-8", 50, 10, .25));  
    }
    std::ofstream log("log.txt", std::ios_base::app|std::ios_base::out);
    basket.total_receipt(log);
    return 0;
}