#include <iostream>
#include <string>
#include <cstddef>
using namespace std;

int main(int argc, char*argv[])
{
    string str;
    if (argc == 3) // ���˳������⣬����ʵ��
    {
        for(size_t i = 0; i < argc; ++i){
            if (i == 0)
                continue;
            str += argv[i];
        }
        cout << str;
    } else{
        cout << "error number parameter";
    }

    return 0;
}
