// Copyright 2019 @five-5
// License(Apache License)
// Author: five-5
// This is just for cpp primer ex9.28 :
// write a function, accepts three parameters, forward_list<string>, string, string
// if find first string, insert second behind first; otherwise insert second in the end

#include <iostream>
#include <string>
#include <forward_list>

void insert_str(std::forward_list<std::string> &str_list, const std::string &to_find, const std::string &to_insert){
    auto cur = str_list.begin(), pre = str_list.before_begin();
    for(; cur != str_list.end();){
        if (*cur == to_find){
            cur = str_list.insert_after(cur, to_insert);
            break;
        } else {
            pre = cur;
            ++cur;
        }
    }
    if (cur == str_list.end()) {
        str_list.insert_after(pre, to_insert);
    }
}

int main()
{
    std::forward_list<std::string> str_forward_list = {"first", "third"};
    std::forward_list<std::string> str_forward_list2 = {"first", "second"};

    std::cout << "str_forward_list = ";
    for(const auto &str : str_forward_list) {
        std::cout << str << " "; 
    }
    std::cout << std::endl << "after insert : "; 
    insert_str(str_forward_list, "first", "second");
    std::cout << "str_forward_list = ";
    for(const auto &str : str_forward_list) {
        std::cout << str << " "; 
    }

    std::cout << std::endl << "str_forward_list2 = ";
    for(const auto &str : str_forward_list2) {
        std::cout << str << " "; 
    }
    std::cout << std::endl << "after insert : "; 
    insert_str(str_forward_list2, "third", "fourth");
    std::cout << "str_forward_list2 = ";
    for(const auto &str : str_forward_list2) {
        std::cout << str << " "; 
    }



    return 0;
}