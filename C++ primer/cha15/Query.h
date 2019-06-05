/*
 * @Author: five-5
 * @Date: 2019-06-05
 * @Description: 
 * @LastEditTime: 2019-06-05
 */

#ifndef QUERY_H
#define QUERY_H

#include <memory>

#include "Query_base.h"
#include "WordQuery.h"

class Query {
 // 运算符需要访问接受shared_ptr的构造函数
  friend Query operator ~ (const Query&);
  friend Query operator | (const Query&, const Query&);
  friend Query operator & (const Query&, const Query&);
  
 public:
    Query(const std::string& s) : q(new WordQuery(s)) {}
    // 接口函数：调用对应的Query_base操作
    QueryResult eval(const TextQuery &t) const {
        return q->eval(t);
    }

    std::string rep() const { return q->rep(); }
 private:
    Query(std::shared_ptr<Query_base> query) : q(query) {}
    std::shared_ptr<Query_base> q;
};

inline std::ostream& operator <<(std::ostream& os, const Query& query) {
    return os << query.rep();
}

#endif