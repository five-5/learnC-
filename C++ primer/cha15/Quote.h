/*
 * @Author: five-5
 * @Date: 2019-05-22
 * @Description: definetion of quote and bulk_quote
 * @LastEditTime: 2019-05-23
 */

#ifndef QUOTE_H
#define QUOTE_H

#include <string>
#include <iostream>

class Quote{
 public:
    Quote() = default;
    Quote(const std::string &book, double sales_price) :
            bookNo(book), price(sales_price) {}

    std::string isbn() const { return bookNo; }

    virtual double net_price(std::size_t n) const {
        return n * price;
    }

    virtual void debug() const {
        std::cout << "data member of this class:\n"
                  << "bookNo = " << bookNo << " "
                  << "price = " << price << " ";
    }

    virtual ~Quote() = default;  // 对析构函数进行动态绑定

 private:
    std::string bookNo;     // ISBN
    
 protected:
    double price = 0.0;     // 不打折的价格
};

class Disc_quote : public Quote {
 public:
    Disc_quote() = default;
    Disc_quote(const std::string &book, double price, std::size_t qty, double disc) :
            Quote(book, price), quantity(qty), discount(disc) {}
    virtual double net_price(std::size_t ) const override = 0;
    
protected: 
    std::size_t quantity = 0;  // 折扣适用的购买量
    double discount = 0.0;     // 表示折扣的小数值
};

class Bulk_quote : public Disc_quote {
 public:
    Bulk_quote() = default;
    Bulk_quote(const std::string &book, double p, std::size_t qty, double disc) :
        Disc_quote(book, p, qty, disc) {}

    double net_price(std::size_t cnt) const override
    {
        if (cnt >= quantity) {
            return cnt * (1 - discount) * price;
        } else {
            return cnt * price;
        }
    }

    void debug() const override {
        Quote::debug();
        std::cout << "quantity = " << quantity << " "
                  << "discount = " << discount << " ";
    }

};

class Limit_quote : public Disc_quote {
 public:
    Limit_quote() = default;
    Limit_quote(const std::string &book, double p, std::size_t qty, double disc) :
        Disc_quote(book, p, qty, disc) {}

    double net_price(std::size_t cnt) const override
    {
        if (cnt <= quantity) {
            return cnt * (1 - discount) * price;
        } else {
            double tmp = quantity * (1 - discount) * price;
            return tmp + (cnt - quantity) * price;
        }
    }
    
    void debug() const override {
        Quote::debug();
        std::cout << "quantity = " << quantity << " "
                  << "discount = " << discount << " ";
    }
};

#endif