#include <iostream>
#include <vector>
#include <cstddef>
using namespace std;

int main()
{
    // ���붯̬���룬��Ҫ���Ȼ�ȡ���������������
    vector<int> vec1{0, 2, 1, 2}, vec2{0, 1, 1, 2, 3, 5, 8};
    int var;
    bool flag = true;

    size_t vec1Size = vec1.size();
    size_t vec2Size = vec2.size();

    if (vec1Size > vec2Size)
    {
        for (size_t i = 0; i < vec2Size; ++i)
            if (vec1[i] != vec2[i])
            {
                flag = false;
                break;
            }
    } else {
        for (size_t i = 0; i < vec1Size; ++i)
            if (vec1[i] != vec2[i])
            {
                flag = false;
                break;
            }
    }

    if (flag)
        cout << "��";
    else
        cout << "��";

    return 0;
}
