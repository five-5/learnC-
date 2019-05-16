
#include <string>
#include <memory>
#include <utility>
#include <algorithm>


class StrVec {
 public:
    StrVec() :
        elements(nullptr), first_free(nullptr), cap(nullptr) {}

    StrVec(std::initializer_list<std::string> list) {
        range_initialize(list.begin(), list.end());
    }

    StrVec(const StrVec &s) {
        // 调用alloc_n_copy分配空间以容纳s中一样多的元素
        auto newdata = alloc_n_copy(s.begin(), s.end());
        elements = newdata.first;
        first_free = cap = newdata.second;
    }

    StrVec& operator=(const StrVec &s) {
        auto data = alloc_n_copy(s.begin(), s.end());
        free();
        elements = data.first;
        first_free = cap = data.second;
        return *this;
    }

    StrVec& operator=(StrVec &&rhs) noexcept {
        if (this != &rhs) {
            free();
            elements = rhs.elements;
            first_free = rhs.first_free;
            cap = rhs.cap;
            // 将rhs置于可析构状态
            rhs.elements = rhs.first_free = rhs.cap = nullptr;
        }
        return *this;
    }

    ~StrVec() {
        free();
    }

    void push_back(const std::string &s) {
        chk_n_alloc(); // 确保有空间容纳新元素
        // 在first_free指向的元素中构造s的副本
        alloc.construct(first_free++, s);
    }

    // move version
    void push_back(std::string &&s) {
        chk_n_alloc();  // 如果需要的话为StrVec重新分配内存
        alloc.construct(first_free++, std::move(s));
    }

    size_t size() const {
        return first_free - elements;
    } 

    size_t capacity() const {
        return cap - elements;
    }

    std::string *begin() const {
        return elements;
    }

    std::string *end() const {
        return first_free;
    }

    void alloc_n_move(size_t new_cap)
    {
        auto newdata = alloc.allocate(new_cap);
        auto dest = newdata;
        auto elem = elements;
        for (size_t i = 0; i != size(); ++i)
            alloc.construct(dest++, std::move(*elem++));
        free();
        elements = newdata;
        first_free = dest;
        cap = elements + new_cap;
    }

    void reserve(size_t new_cap)
    {
        if (new_cap <= capacity()) return;
        alloc_n_move(new_cap);
    }

    void resize(size_t count)
    {
        resize(count, std::string());
    }

    void resize(size_t count, const std::string &s)
    {
        if (count > size()) {
            if (count > capacity()) reserve(count * 2);
            for (size_t i = size(); i != count; ++i)
                alloc.construct(first_free++, s);
        }
        else if (count < size()) {
            while (first_free != elements + count)
                alloc.destroy(--first_free);
        }
    }

 private:
    static std::allocator<std::string> alloc; // 分配元素
    
    void chk_n_alloc() {
        if (size() == capacity()) {
            reallocate();
        }
    }
    
    // 工具函数
    std::pair<std::string*, std::string*> alloc_n_copy 
        (const std::string* b, const std::string* e) {
            // 分配空间确保给定范围中的元素
            auto data = alloc.allocate(e - b);
            // 初始化并返回一个pair，该pair由data和uninitialized_copy的返回值构成
            return {data, uninitialized_copy(b, e, data)};
        }

    void alloc_n_move(size_t new_cap)
    {
        auto newdata = alloc.allocate(new_cap);
        auto dest = newdata;
        auto elem = elements;
        for (size_t i = 0; i != size(); ++i)
            alloc.construct(dest++, std::move(*elem++));
        free();
        elements = newdata;
        first_free = dest;
        cap = elements + new_cap;
    }

    // 销毁元素并释放内存
    void free() {
        // 不能传递给deallocate一个空指针，如果elements为0，函数什么也不做
        if (elements) {
            // 逆序销毁旧元素
            for (auto p = first_free; p != elements;) {
                alloc.destroy(--p);
            }
            alloc.deallocate(elements, cap - elements);
        }
        
        // new version
        // std::for_each(elements, first_free, [this](std::string &rhs){ alloc.destroy(&rhs); });
    }   

    // 获得更多内存并拷贝已有元素       
    void reallocate() {
        // 我们将分配当前大小两倍的内存空间
        auto newcapacity = size() ? 2 * size() : 1;
        // 分配新内存
        auto newdata = alloc.allocate(newcapacity);
        // 将数据从旧内存移动到新内存
        auto dest = newdata;  // 指向新数组中下一个空闲位置
        auto elem = elements; // 指向旧数组中下一个元素
        for (size_t i = 0; i != size(); ++i) {
            alloc.construct(dest++, std::move(*elem++));
        } 
        free(); // 一旦我们移动完成元素就释放旧内存空间
        // 更新我们的数据结构，执行新元素
        elements = newdata;
        first_free = dest;
        cap = elements + newcapacity;
    }

     void range_initialize(const std::string* first, const std::string* last) {
        auto newdata = alloc_n_copy(first, last);
        elements = newdata.first;
        first_free = cap = newdata.second;
     }


    std::string *elements;   // 指向数组首元素的指针
    std::string *first_free; // 指向数组第一个空闲元素的指针
    std::string *cap;        // 指向数组尾后位置的指针
};