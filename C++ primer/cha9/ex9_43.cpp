// Copyright 2019 @five-5
// License(Apache License)
// Author: five-5
// This is just for cpp primer ex9.43 :
// use insert and erase to replace oldVal in s with newVal

#include <iostream>
#include <string>

void replace_str(const std::string &oldVal, const std::string &newVal, std::string &s) {
    std::size_t erase_lenth = oldVal.size();
    for (auto cur = s.begin(); cur <= s.end() - erase_lenth;) {
        if (oldVal == std::string(cur, cur+erase_lenth)) {
            cur = s.erase(cur, cur + erase_lenth);
            cur = s.insert(cur, newVal.begin(), newVal.end());
            cur += newVal.size();
        } else {
            ++cur;
        }
    }
}

int main()
{
    std::string s = "tho there is many resources in web, many people can not clarify the quality of them.tho tho tho, just test for tho";

    std::cout << s << std::endl << std::endl;
    replace_str("tho", "though", s);
    std::cout <<"After replace: " << s << std::endl;
    return 0;
}