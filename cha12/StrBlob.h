/*
 * @Author: five-5
 * @Description: the practice of strblob in p405 cpp 5e
 * @Date: 2019-04-09
 * @LastEditTime: 2019-04-09
 */


#ifndef STR_BLOB_H
#define STR_BLOB_H

#include <vector>
#include <string>
#include <initializer_list>
#include <memory>
#include <exception>

class StrBlob{
 public:
    typedef std::vector<std::string>::size_type size_type;
    StrBlob(): data(std::make_shared<std::vector<std::string>>()) {}
    StrBlob(std::initializer_list<std::string> il): data(std::make_shared<std::vector<std::string>>(il) ) {}
    size_type size() const { return data->size(); }
    bool empty() const { return data->empty(); }
    // 添加和删除元素
    void push_back(const std::string &t) { data->push_back(t); }
    void pop_back() {
      check(0, "pop_back on empty StrBlob");
      data->pop_back();
   }
    // 元素访问
    std::string& front() {
      // 如果vector为空，check会抛出一个异常
      check(0, "front on empty StrBlob");
      return data->front();
   }
    std::string& back() {
      check(0, "back on empty StrBlob");
      return data->back();
   }
 private:
    std::shared_ptr<std::vector<std::string>> data;
    // 如果data[i]不合法，抛出一个异常
    void check(size_type i, const std::string &msg) const {
      if (i >= data->size()) {
         throw std::out_of_range(msg);
      }
   }  
};
#endif