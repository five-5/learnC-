/*
 * @Author: five-5
 * @Date: 2019-05-22
 * @Description: definetion of quote and bulk_quote
 * @LastEditTime: 2019-05-22
 */

#ifndef QUOTE_H
#define QUOTE_H

#include <string>

class Quote{
 public:
    Quote() = default;
    Quote(const std::string &book, double sales_price) :
            bookNo(book), price(sales_price) {}

    std::string isbn() const { return bookNo; }

    virtual double net_price(std::size_t n) const {
        return n * price;
    }
    virtual ~Quote() = default;  // 对析构函数进行动态绑定

 private:
    std::string bookNo;     // ISBN
    
 protected:
    double price = 0.0;     // 不打折的价格
};

class Bulk_quote : public Quote {
 public:
    Bulk_quote() = default;
    Bulk_quote(const std::string &book, double p, std::size_t qty, double disc) :
        Quote(book, p), min_qty(qty), discount(disc) {}

    double net_price(std::size_t cnt) const override
    {
        if (cnt >= min_qty) {
            return cnt * (1 - discount) * price;
        } else {
            return cnt * price;
        }
    }
    
 private:
    std::size_t min_qty = 0;        // 适用折扣政策的最低购买量
    double discount = 0.0;          // 以小数表示的折扣额
};

#endif