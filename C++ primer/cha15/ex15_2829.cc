/*
 * @Author: five-5
 * @Date: 2019-06-04
 * @Description: exer for 15.28 15.29
 * @LastEditTime: 2019-06-04
 */

#include <iostream>
#include <memory>
#include <vector>

#include "Quote.h"

int main()
{
    std::vector<Quote> v;
    v.push_back(Quote("0-201-82470-1", 50));
    v.push_back(Bulk_quote("0-201-54848-8", 50, 10, .25));
    double total = 0;
    for (auto item : v) {
        total += item.net_price(15);
    }
    std::cout << "<Quote> " << total << std::endl;
    
    std::vector<std::shared_ptr<Quote>> basket;
    basket.push_back(std::make_shared<Quote>("0-201-82470-1", 50));
    basket.push_back(std::make_shared<Bulk_quote>("0-201-54848-8", 50, 10, .25));
    double total_p = 0;
    for (auto item : basket) {
        total_p += item->net_price(15);
    }
    std::cout << "shared_ptr<Quote> " << total_p << std::endl;
    
    return 0;
}