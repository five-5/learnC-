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

    cout << "ԭʼ�������ݣ�";
    for(auto it = intVct.cbegin(); it != intVct.cend(); ++it)
        cout << *it << " ";
    cout << endl;

    // ��Ԫ�ر�Ϊԭ��������
    cout << "�޸ĺ����ݣ�";
    for(auto it = intVct.begin(); it != intVct.end(); ++it){
        *it = (*it) * 2;
        cout << *it << " ";
    }

    return 0;
}
