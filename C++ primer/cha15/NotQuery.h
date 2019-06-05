/*
 * @Author: five-5
 * @Date: 2019-06-05
 * @Description: 
 * @LastEditTime: 2019-06-05
 */

#ifndef NOTQUERY_H
#define NOTQUERY_H

#include "Query_base.h"
#include "Query.h"

class NotQuery: public Query_base {
    friend Query operator~(const Query& operand);
    
 NotQuery(const Query &q) : query(q) {}
 QueryResult eval(const TextQuery& t) const override {
     auto result = query.eval(t);
     auto ret_lines = std::make_shared<std::set<line_no>>();
     auto beg = result.begin(), end = result.end();
     auto sz = result.get_file()->size();
     for (size_t n = 0; n != sz; ++n) {
         if (beg == end || *beg != n) {
             ret_lines->insert(n);
         } else if (beg != end) {
             ++beg;
         }
     }
     return QueryResult(rep(), ret_lines, result.get_file());
 }
 std::string rep() const override {return "~(" + query.rep() + ")"; }
 Query query;
};

inline Query operator~(const Query& operand) {
    return Query(std::shared_ptr<Query_base>(new NotQuery(operand)));
}

#endif