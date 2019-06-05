/*
 * @Author: five-5
 * @Date: 2019-06-05
 * @Description: 
 * @LastEditTime: 2019-06-05
 */

#ifndef BINARYQUERY_H
#define BINARYQUERY_H

#include "Query_base.h"
#include "Query.h"

class BinaryQuery : public Query_base{
 protected:
    BinaryQuery(const Query& l, const Query& r, std::string s) : lhs(l), rhs(r), opSym(s) {}
    // 抽象类：BinaryQuery不定义eval
    std::string rep() const { return "(" + lhs.rep() + " " 
                                         + opSym + " "
                                         + rhs.rep() + ")";}
    Query lhs, rhs;     // 左右侧对象
    std::string opSym;  // 运算符
};

#endif