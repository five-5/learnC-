#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
    vector<int> v1;
    cout << "v1含有" << v1.size() << " 个元素,分别为：";
    for(auto it = v1.cbegin(); it != v1.cend(); ++it)
        cout << *it << " ";
    cout << endl;

    vector<int> v2(10);
    cout << "v2含有" << v2.size() << " 个元素,分别为：";
    for(auto it = v2.cbegin(); it != v2.cend(); ++it)
        cout << *it << " ";
    cout << endl;

    vector<int> v3(10, 42);
    cout << "v3含有" << v3.size() << " 个元素,分别为：";
    for(auto it = v3.cbegin(); it != v3.cend(); ++it)
        cout << *it << " ";
    cout << endl;

    vector<int> v4{10};
    cout << "v4含有" << v4.size() << " 个元素,分别为：";
    for(auto it = v4.cbegin(); it != v4.cend(); ++it)
        cout << *it << " ";
    cout << endl;

    vector<int> v5{10, 42};
    cout << "v5含有" << v5.size() << " 个元素,分别为：";
    for(auto it = v5.cbegin(); it != v5.cend(); ++it)
        cout << *it << " ";
    cout << endl;

    vector<string> v6{10};
    cout << "v6含有" << v6.size() << " 个元素,分别为：";
    for(auto it = v6.cbegin(); it != v6.cend(); ++it)
        cout << *it << " ";
    cout << endl;

    vector<string> v7{10, "hi"};
    cout << "v7含有" << v7.size() << " 个元素,分别为：";
    for(auto it = v7.cbegin(); it != v7.cend(); ++it)
        cout << *it << " ";
    cout << endl;

    return 0;
}
