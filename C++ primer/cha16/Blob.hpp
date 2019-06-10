/*
 * @Author: five-5
 * @Date: 2019-06-10
 * @Description: 
 * @LastEditTime: 2019-06-10
 */

#ifndef BLOB_HPP
#define BLOB_HPP

#include <vector>
#include <memory>
#include <string>
#include <stdexcept>

template <typename T>
class Blob {
 public:
    typedef T value_type;
    typedef typename std::vector<T>::size_type size_type;
    // constructor
    Blob(): data(std::make_shared<std::vector<T>>()) {}
    Blob(std::initializer_list<T> il): data(std::make_shared<std::vector<T>>(il)) {}
    // Blob中的元素数目
    size_type size() const { return data->size(); }
    bool empty() const { return data->empty(); }
    // add and remove elemet
    void push_back(const T& t) { data->push_back(t); }
    // move version
    void push_back(T&& t) { data->push_back(std::move(t)); }
    void pop_back();
    // access element
    T& back();
    T& front();
    T& operator[](size_type i);
    
 private:
    std::shared_ptr<std::vector<T>> data;  
    // 若data[i]无效，则抛出msg
    void check(size_type i, const std::string &msg) const; 
};

template <typename T>
void Blob<T>::check(size_type i, const std::string &msg) const {
    if ( i >= data->size()) {
        throw std::out_of_range(msg);
    }
}

template <typename T>
T& Blob<T>::back() {
    check(0, "back on empty Blob");
    return data->back();
}

template <typename T>
T& Blob<T>::front() {
    check(0, "front on empty Blob");
    return data->front();
}

template <typename T>
T& Blob<T>::operator[] (size_type i) {
    check(i, "subscript out of range");
    return (*data)[i];
}

template <typename T>
void Blob<T>::pop_back() {
    check(0, "pop_bakc on empty Blob");
    data->pop_back();
}

#endif