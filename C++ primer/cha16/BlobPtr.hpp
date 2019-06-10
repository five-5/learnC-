/*
 * @Author: five-5
 * @Date: 2019-06-11
 * @Description: 
 * @LastEditTime: 2019-06-11
 */


#ifndef BLOB_PTR_HPP
#define BLOB_PTR_HPP

#include "Blob.hpp"

#include <memory>
#include <vector>
#include <string>
#include <stdexcept>

template <typename> class BlobPtr;

template <typename T>
bool operator ==(const BlobPtr<T>& lhs, const BlobPtr<T>& rhs);

template <typename T>
bool operator < (const BlobPtr<T>& lhs, const BlobPtr<T>& rhs);


template <typename T>
class BlobPtr {
    friend bool operator ==<T> (const BlobPtr<T>& lhs, const BlobPtr<T>& rhs);
    friend bool operator < <T> (const BlobPtr<T>& lhs, const BlobPtr<T>& rhs);
 public:
    BlobPtr() : curr(0) {}
    BlobPtr(Blob<T> &a, size_t sz = 0) : wptr(a.data), curr(sz) {}
    T& operator*() const {
        auto p = check(curr, "dereference past end");
        return (*p)[curr];
    }
    BlobPtr& operator++(); // 前置
    BlobPtr& operator--();
    BlobPtr operator ++(int); // 后缀
    BlobPtr operator --(int);

 private:
    std::shared_ptr<std::vector<T>> check(std::size_t, const std::string &) const;
    std::weak_ptr<std::vector<T>> wptr;
    std::size_t curr;   // 数组中当前的位置
};

template <typename T>
BlobPtr<T>& BlobPtr<T>::operator++() {
    check(curr, "increment past end of BlobPtr");
    ++curr;
    return *this;
}

template <typename T>
BlobPtr<T>& BlobPtr<T>::operator--() {
    --curr;
    check(curr, "decrement past begin of BlobPtr");
    return *this;
}

// 后置
template <typename T>
BlobPtr<T> BlobPtr<T>::operator++(int) {
    BlobPtr ret = *this;
    ++*this;  // 前置++检查递增是否合法
    return ret;
}

template <typename T>
BlobPtr<T> BlobPtr<T>::operator--(int) {
    BlobPtr ret = *this;
    --*this;  // 前置++检查递增是否合法
    return ret;
}

template <typename T>
bool operator== (const BlobPtr<T>& lhs, const BlobPtr<T>& rhs) {
    if (lhs.wptr.lock() != rhs.wptr.lock()) {
        throw std::runtime_error("ptrs to different Blobs!");
    }
    return lhs.i == rhs.i;
}

template <typename T>
bool operator< (const BlobPtr<T>& lhs, const BlobPtr<T>& rhs) {
    if (lhs.wptr.lock() != rhs.wptr.lock()) {
        throw std::runtime_error("ptrs to different Blobs!");
    }
    return lhs.i < rhs.i;
}

#endif 