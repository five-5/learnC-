/*
 * @Author: five-5
 * @Date: 2019-06-04
 * @Description: 
 * @LastEditTime: 2019-06-04
 */

#ifndef BASKET_H
#define BASKET_H

#include <memory>
#include <iostream>
#include <set>

#include "Quote.h"

double print_total(std::ostream& os, const Quote &item, size_t n) {
    double ret = item.net_price(n);
    os << "ISBN: " << item.isbn()
       << " # sold: " << n << " total due: " << ret << std::endl;
    return ret;
}

class Basket {
 public:
    // 使用默认合成构造
    void add_item(const std::shared_ptr<Quote> &sale) {items.insert(sale);}
    void add_item(const Quote& sale) {items.insert(std::shared_ptr<Quote>(sale.clone()));}
    void add_item(Quote&& sale) {items.insert(std::shared_ptr<Quote>(std::move(sale).clone()));}

    // 打印每本书的总价和购物篮中所有书的总价
    double total_receipt(std::ostream& os) const {
        double sum = 0.0;
        // iter指向ISBN相同的一批元素中的第一个
        // upper_bound返回一个迭代器，该迭代器指向这批元素的尾后位置
        for (auto iter = items.cbegin();
                  iter != items.cend();
                  iter = items.upper_bound(*iter)) {  // 跳过关键字相同的所有元素
            // 打印该书籍对应的项目
            sum += print_total(os, **iter, items.count(*iter));             
        }
        os << "Total Sale: " << sum << std::endl;
        return sum;
    }
    
 private:
    // 该函数用于比较shared_ptr，multiset成员
    static bool compare(const std::shared_ptr<Quote> &lhs,
                        const std::shared_ptr<Quote> &rhs) {
        return lhs->isbn() < rhs->isbn();
    }
    // multiset保存多个报价，按照compare成员排序
    std::multiset<std::shared_ptr<Quote>, decltype(compare)*> items{compare};
};

#endif