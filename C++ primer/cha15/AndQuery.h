/*
 * @Author: five-5
 * @Date: 2019-06-05
 * @Description: 
 * @LastEditTime: 2019-06-05
 */

#ifndef ANDQUERY_H
#define ANDQUERY_H

#include "BinaryQuery.h"
#include <algorithm>

class AndQuery : public BinaryQuery {
 friend Query operator& (const Query&, const Query&);
 AndQuery(const Query& left, const Query& right): BinaryQuery(left, right, "&") {}
 QueryResult eval(const TextQuery& t) const {
     auto left = lhs.eval(t), right = rhs.eval(t);
     auto ret_lines = std::make_shared<std::set<line_no>>();
     std::set_intersection(left.begin(), left.end(),
                           right.begin(), right.end(),
                           std::inserter(*ret_lines, ret_lines->begin()));
     return QueryResult(rep(), ret_lines, left.get_file());
 }
};

inline Query operator& (const Query& lhs, const Query& rhs) {
    return Query(std::shared_ptr<Query_base>(new AndQuery(lhs, rhs)));
}

#endif