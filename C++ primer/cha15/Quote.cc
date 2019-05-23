/*
 * @Author: five-5
 * @Date: 2019-05-22
 * @Description: exercise for derivation and dynamic binding
 * @LastEditTime: 2019-05-23
 */

#include <iostream>

#include "Quote.h"

double print_total(std::ostream& os, const Quote &item, std::size_t n)
{
    double ret = item.net_price(n);
    os << "ISBN: " << item.isbn() 
       << " # sold： " << n << " total due: " << ret << std::endl;
    return ret;
}

int main()
{
    Quote basic("book", 10.6);
    Bulk_quote bulk("book", 10.6, 10, 0.3);
    Limit_quote limit("book", 10.6, 10, 0.3);

    print_total(std::cout, basic, 20);
    print_total(std::cout, bulk, 20);
    print_total(std::cout, limit, 20);
    
    return 0;
}
