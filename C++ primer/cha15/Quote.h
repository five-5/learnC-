/*
 * @Author: five-5
 * @Date: 2019-05-22
 * @Description: definetion of quote and bulk_quote
 * @LastEditTime: 2019-05-27
 */

#ifndef QUOTE_H
#define QUOTE_H

#include <string>
#include <iostream>

class Quote{
    friend bool operator !=(const Quote& lhs, const Quote& rhs)
    {
        return lhs.bookNo != rhs.bookNo && lhs.price != rhs.price;
    }
 public:
    Quote() { std::cout << "default constructing Quote" << std::endl; }
    Quote(const std::string &book, double sales_price) :
            bookNo(book), price(sales_price) { std::cout << "Quote: constructor takes 2 para.\n"; }

    // copy constructor
    Quote(const Quote& q) : bookNo(q.bookNo), price(q.price)
    { std::cout << "Quote: copy constructor\n"; }

    // move constructor
    Quote(Quote&& q) noexcept : bookNo(std::move(q.bookNo)), price(std::move(q.price))
    { std::cout << "Quote: move constructor\n";}

    // copy =
    Quote& operator =(const Quote& rhs)
    {
        if (*this != rhs)
        {
            bookNo = rhs.bookNo;
            price = rhs.price;
        }
        std::cout << "Quote: copy =()\n";

        return *this;
    }

    // move =
    Quote& operator =(Quote&& rhs) noexcept
    {
        if (*this != rhs)
        {
            bookNo = rhs.bookNo;
            price = rhs.price;
        }
        std::cout << "Quote: move = !!!!\n";
        return *this;
    }

    std::string isbn() const { return bookNo; }

    virtual double net_price(std::size_t n) const {
        return n * price;
    }

    virtual void debug() const {
        std::cout << "data member of this class:\n"
                  << "bookNo = " << bookNo << " "
                  << "price = " << price << " ";
    }

    virtual ~Quote()  // 对析构函数进行动态绑定
    {
        std::cout << "destructing Quote\n";
    }

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
    Bulk_quote() { std::cout << "default constructing Bulk_quote\n"; }
    Bulk_quote(const std::string &book, double p, std::size_t qty, double disc) :
        Disc_quote(book, p, qty, disc) { std::cout << "Bulk_quote: constructor takes 4 para.\n"; }

    // copy constructor
    Bulk_quote(const Bulk_quote& nq) : Disc_quote(bq)
    { std::cout << "Bulk_quote: copy constructor\n"; }

    // move constructor
    Bulk_quote(Bulk_quote&& bq) noexcept : Disc_quote(std::move(bq))
    { std::cout << "Bulk_quote: move constructor\n"; }

    // copy =()
    Bulk_quote& operator =(const Bulk_quote& rhs)
    {
        Disc_quote::operator=(rhs);
        std::cout << "Bulk_quote: copy=() \n";

        return *this;
    }

    // move=()
    Bulk_quote& operator =(Bulk_quote&& rhs) noexcept
    {
        Disc_quote::operator=(std::move(rhs));
        std::cout << "Bulk_quote: move=() \n";

        return *this;
    }

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

    ~Bulk_quote() override
    {
        std::cout << "destructing Bulk_quote\n";
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