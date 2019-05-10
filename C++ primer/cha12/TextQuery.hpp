/*
 * @Author: five-5
 * @Description: query word in certain file, return the times and print the line list
 * @Date: 2019-05-08
 * @LastEditTime: 2019-05-09
 */

#ifndef TEXTQUERY_HPP
#define TEXTQUERY_HPP

#include <fstream>
#include <sstream>
#include <string>
#include <map>

#include "QueryResult.hpp"

class TextQuery{
 public:
    using line_no = std::vector<std::string>::size_type;
    TextQuery(std::ifstream& in) : file_(new std::vector<std::string>)
    {
        std::string text;
        while (getline(in, text))     // 对文件中每一行
        {
            file_->push_back(text);    // 保存此行文本
            int n = file_->size() - 1; // 当前行号
            std::istringstream line(text);
            std::string word;
            while (line >> word)       // 对行中每个单词
            {
                // 如果单词不在word_map_中，以之为下标在word_map_中添加一项
                auto &lines = word_map_[word];   // lines是一个shared_ptr
                if (!lines)   // 在第一次遇到这个单词时，此指针为空
                {
                    lines.reset(new std::set<line_no>);  // 分配一个新的set
                }
                lines->insert(n);       // 将此行号插入set中
            }
        }
    }

    QueryResult query(const std::string sought) const
    {
        // 如果未找到sought,我们将返回一个指向此set的指针
        static std::shared_ptr<std::set<line_no>> no_data(new std::set<line_no>);
        // 使用find而不是下标运算符来查找单词，避免将单词添加到word_map_中
        auto loc = word_map_.find(sought);
        if (loc == word_map_.end()) 
        {
            return QueryResult(sought, no_data, file_);  // 未找到
        }
        else
        {
            return QueryResult(sought, loc->second, file_);
        }
    }
    
 private:
    std::shared_ptr<std::vector<std::string>> file_; // 输入文件
    // 每个单词到它所在的行号的集合的映射
    std::map<std::string, std::shared_ptr<std::set<line_no>>> word_map_;
};

#endif