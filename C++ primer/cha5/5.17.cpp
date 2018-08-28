#include <iostream>
#include <vector>
#include <cstddef>
using namespace std;

int main()
{
    // 若想动态输入，需要首先获取数组个数，再输入
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
        cout << "真";
    else
        cout << "假";

    return 0;
}
