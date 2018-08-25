#ifndef SALES_DATA_H_INCLUDED
#define SALES_DATA_H_INCLUDED

struct Sales_data{
    std::string bookIsbn;  // isbn
    int number;            // 数量
    double unitPrice;      // 单价
    double profit;         // 利润
};

#endif // SALES_DATA_H_INCLUDED
