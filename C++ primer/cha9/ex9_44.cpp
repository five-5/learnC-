// Copyright 2019 @five-5
// License(Apache License)
// Author: five-5
// This is just for cpp primer ex9.44 :
// use [] and replace function to replace oldVal in s with newVal

#include <iostream>
#include <string>

void replace_str(const std::string &oldVal, const std::string &newVal, std::string &s) {
    std::size_t erase_lenth = oldVal.size();
    for (size_t pos = 0; pos <= s.size() - erase_lenth;) {
        if (oldVal[0] == s[pos] &&  s.substr(pos, erase_lenth) == oldVal) {
           
            s.replace(pos, erase_lenth, newVal);
            pos += newVal.size();
        } else {
            ++pos;
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