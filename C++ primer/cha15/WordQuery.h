/*
 * @Author: five-5
 * @Date: 2019-06-05
 * @Description: 
 * @LastEditTime: 2019-06-05
 */

#ifndef WORDQUERY_H
#define WORDQUERY_H

#include "Query_base.h"

class WordQuery : public Query_base{
    friend class Query;
 WordQuery(const std::string &s) : query_word(s) {}
 QueryResult eval(const TextQuery& t) const override {
     return t.query(query_word);
 }
 std::string rep() const override {return query_word; }
 std::string query_word;     // word to search
};

#endif