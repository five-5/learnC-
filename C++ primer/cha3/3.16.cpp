#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
    vector<int> v1;
    cout << "v1����" << v1.size() << " ��Ԫ��,�ֱ�Ϊ��";
    for(auto i : v1)
        cout << i << " ";
    cout << endl;

    vector<int> v2(10);
    cout << "v2����" << v2.size() << " ��Ԫ��,�ֱ�Ϊ��";
    for(auto i : v2)
        cout << i << " ";
    cout << endl;

    vector<int> v3(10, 42);
    cout << "v3����" << v3.size() << " ��Ԫ��,�ֱ�Ϊ��";
    for(auto i : v3)
        cout << i << " ";
    cout << endl;

    vector<int> v4{10};
    cout << "v4����" << v4.size() << " ��Ԫ��,�ֱ�Ϊ��";
    for(auto i : v4)
        cout << i << " ";
    cout << endl;

    vector<int> v5{10, 42};
    cout << "v5����" << v5.size() << " ��Ԫ��,�ֱ�Ϊ��";
    for(auto i : v5)
        cout << i << " ";
    cout << endl;

    vector<string> v6{10};
    cout << "v6����" << v6.size() << " ��Ԫ��,�ֱ�Ϊ��";
    for(auto i : v6)
        cout << i << " ";
    cout << endl;

    vector<string> v7{10, "hi"};
    cout << "v7����" << v7.size() << " ��Ԫ��,�ֱ�Ϊ��";
    for(auto i : v7)
        cout << i << " ";
    cout << endl;

    return 0;
}
