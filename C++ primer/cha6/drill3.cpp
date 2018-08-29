#include <iostream>
#include <string>
using namespace std;

string::size_type find_char(const string &s, char c,
                             string::size_type &occurs)
{
    auto ret = s.size();     // 妙妙秒，省去flag
    occurs = 0;
    for (decltype(ret) i = 0; i != s.size(); ++i){
        if (s[i] == c){
            if (ret == s.size())
                ret = i;    // 记录c第一次出现的位置
            ++occurs;
        }
    }
    return ret;
}

int main()
{

    return 0;
}
