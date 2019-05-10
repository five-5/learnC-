/*
 * @Author: five-5
 * @Description: helper class to print the query result
 * @Date: 2019-05-08
 * @LastEditTime: 2019-05-09
 */

#ifndef QUERY_RESULT_HPP
#define QUERY_RESULT_HPP

#include <iostream>
#include <memory>
#include <set>
#include <vector>

class QueryResult{
    using line_no = std::vector<std::string>::size_type;
 friend std::ostream& print(std::ostream& out, const QueryResult& qr);
 public:
    QueryResult(std::string s,
                std::shared_ptr<std::set<line_no>> p,
                std::shared_ptr<std::vector<std::string>> f):
                sought_(s), lines_(p), file_(f) {}
 private:
    std::string sought_;  // 查询单词
    std::shared_ptr<std::set<line_no>> lines_; // 出现的行号
    std::shared_ptr<std::vector<std::string>> file_; // 输入文件
};

std::string make_plural(std::size_t ctr, const std::string &word,
                                         const std::string &ending)
{
    return (ctr > 1) ? word + ending : word;
}

std::ostream& print(std::ostream& out, const QueryResult& qr)
{
    // 如果找到了单词，打印出现次数和所有出现的位置
    out << qr.sought_ << " occurs " << qr.lines_->size() << " "
        << make_plural(qr.lines_->size(), "time", "s") << std::endl;
    // 打印单词出现的每一行
    for (auto num : *qr.lines_)  // 对set中每个单词
    {
        // 避免行号从0开始给用户带来困惑
        out << "\t(line "<< num + 1 << ") "
            << *(qr.file_->begin() + num) << std::endl;
    }
    return out;
}

#endif