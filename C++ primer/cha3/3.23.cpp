#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> intVct;
    int var;
    while (cin >> var){
        intVct.push_back(var);
    }

    cout << "原始输入数据：";
    for(auto it = intVct.cbegin(); it != intVct.cend(); ++it)
        cout << *it << " ";
    cout << endl;

    // 将元素变为原来的两倍
    cout << "修改后数据：";
    for(auto it = intVct.begin(); it != intVct.end(); ++it){
        *it = (*it) * 2;
        cout << *it << " ";
    }

    return 0;
}
