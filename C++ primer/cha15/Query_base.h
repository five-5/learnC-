/*
 * @Author: five-5
 * @Date: 2019-06-05
 * @Description: 
 * @LastEditTime: 2019-06-05
 */

#ifndef QUERY_BASE_H
#define QUERY_BASE_H

#include "../cha12/TextQuery.hpp"
#include "../cha12/QueryResult.hpp"

class Query_base {
  friend class Query;
 protected: 
    using line_no = TextQuery::line_no;    // 用于eval函数
    virtual ~Query_base() = default;
 private:
    // eval返回与当前Query匹配的QueryResult
    virtual QueryResult eval(const TextQuery&) const = 0;
    // rep是表示查询的一个string
    virtual std::string rep() const = 0;
};

#endif