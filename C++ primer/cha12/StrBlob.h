/*
 * @Author: five-5
 * @Description: the practice of strblob in p405 cpp 5e 
 * @Date: 2019-04-09
 * @LastEditTime: 2019-05-07
 */


#ifndef STR_BLOB_H
#define STR_BLOB_H

#include <vector>
#include <string>
#include <initializer_list>
#include <memory>
#include <exception>


class StrBlobPtr;
// a class to manage string type
class StrBlob{
   
 public:
    typedef std::vector<std::string>::size_type size_type;
    friend class StrBlobPtr;
    
    StrBlobPtr begin();
    StrBlobPtr end();
    
    StrBlob(): data_(std::make_shared<std::vector<std::string>>()) {}
    StrBlob(std::initializer_list<std::string> il): data_(std::make_shared<std::vector<std::string>>(il) ) {}
    size_type size() const { return data_->size(); }
    bool empty() const { return data_->empty(); }
    // 添加和删除元素
    void push_back(const std::string &t) { data_->push_back(t); }
    void pop_back() {
      check(0, "pop_back on empty StrBlob");
      data_->pop_back();
   }
    // 元素访问
    std::string& front() {
      // 如果vector为空，check会抛出一个异常
      check(0, "front on empty StrBlob");
      return data_->front();
   }
    std::string& back() {
      check(0, "back on empty StrBlob");
      return data_->back();
   }

 private:
    std::shared_ptr<std::vector<std::string>> data_;
    // 如果data__[i]不合法，抛出一个异常
    void check(size_type i, const std::string &msg) const {
      if (i >= data_->size()) {
         throw std::out_of_range(msg);
      }
   }  
};

class StrBlobPtr{
 public:
    StrBlobPtr():curr(0){}
    StrBlobPtr(StrBlob &a, size_t sz = 0): wptr(a.data_), curr(sz) {}
    bool operator!=(const StrBlobPtr& p) {
       return p.curr != curr;
    }
    std::string& deref() const
    {
       auto p = check(curr, "dereference past end");
       return (*p)[curr];     // *p是对象所指向的vector
    }
    StrBlobPtr& incr() // 前缀增加
    {
       // 如果curr已经指向容器尾，就不再增加
       check(curr,"increment past end of StrBloPtr");
       ++curr;  // ++
       return *this;
    }
 private:
    // 若检查成功，check返回一个指向vector的shared_ptr
    std::shared_ptr<std::vector<std::string>> 
    check(std::size_t i, const std::string& msg) const
    {
       auto ret = wptr.lock();
       if (!ret) {
          throw std::runtime_error("unbound StrBlobPtr");
       }
       if (i >= ret->size()) {
          throw std::out_of_range(msg);
       }
       return ret;    // 否则，返回指向vector的shared_ptr
    }
    // 保存一个weak_ptr，意味着底层vector可能被销毁
    std::weak_ptr<std::vector<std::string>> wptr;
    std::size_t curr; // 在数组中的当前位置
};

StrBlobPtr StrBlob::begin() 
{
   return StrBlobPtr(*this);
}
   
StrBlobPtr  StrBlob::end() 
{
   auto ret = StrBlobPtr(*this, data_->size());
   return ret;
}

#endif