/*
 * @Author: five-5
 * @Date: 2019-06-05
 * @Description: 
 * @LastEditTime: 2019-06-05
 */

#ifndef OrQUERY_H
#define OrQUERY_H

#include "BinaryQuery.h"

class OrQuery : public BinaryQuery {
 friend Query operator| (const Query&, const Query&);
 OrQuery(const Query& left, const Query& right): BinaryQuery(left, right, "|") {}
 QueryResult eval(const TextQuery& text) const override {
     // 通过Query成员lhs和rhs进行的虚调度
     // 通过eval返回每个运算对象的QueryResult
     auto right = rhs.eval(text), left = lhs.eval(text);
     // 将左侧对象的行号拷贝到结果set中
     auto ret_lines = std::make_shared<std::set<line_no>>(left.begin(), left.end());
     // 插入右侧运算对象所得的行号
     ret_lines->insert(right.begin(), right.end());
     // 返回一个新的QueryResult，它表示lhs和rhs的并集
     return QueryResult(rep(), ret_lines, left.get_file());
 }
};

inline Query operator| (const Query& lhs, const Query& rhs) {
    return Query(std::shared_ptr<Query_base>(new OrQuery(lhs, rhs)));
}

#endif