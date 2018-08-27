#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
    vector<int> v1;
    cout << "v1含有" << v1.size() << " 个元素,分别为：";
    for(auto i : v1)
        cout << i << " ";
    cout << endl;

    vector<int> v2(10);
    cout << "v2含有" << v2.size() << " 个元素,分别为：";
    for(auto i : v2)
        cout << i << " ";
    cout << endl;

    vector<int> v3(10, 42);
    cout << "v3含有" << v3.size() << " 个元素,分别为：";
    for(auto i : v3)
        cout << i << " ";
    cout << endl;

    vector<int> v4{10};
    cout << "v4含有" << v4.size() << " 个元素,分别为：";
    for(auto i : v4)
        cout << i << " ";
    cout << endl;

    vector<int> v5{10, 42};
    cout << "v5含有" << v5.size() << " 个元素,分别为：";
    for(auto i : v5)
        cout << i << " ";
    cout << endl;

    vector<string> v6{10};
    cout << "v6含有" << v6.size() << " 个元素,分别为：";
    for(auto i : v6)
        cout << i << " ";
    cout << endl;

    vector<string> v7{10, "hi"};
    cout << "v7含有" << v7.size() << " 个元素,分别为：";
    for(auto i : v7)
        cout << i << " ";
    cout << endl;

    return 0;
}
