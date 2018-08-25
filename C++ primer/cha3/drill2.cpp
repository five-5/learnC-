#include <iostream>
#include <string>
using namespace std;

int main()
{
    string str = "Hello";
    string phrase = "Hello World";
    string slang = "Hiya";

    // string对象比较
    if (str <= phrase)
        cout << str << " < " << phrase <<endl;
    if (slang >= phrase)
        cout << slang << " > " << phrase <<endl;

    // string对象赋值
    string st1(10, 'c'), st2; // st1内容为10个c;st2为空字符串
    cout << "赋值前：" << endl;
    cout << "st1 = " << st1 << " " << "长度为：" << st1.size() << endl;
    cout << "st2 = " << st2 << " " << "长度为：" << st2.size() << endl;

    st1 = st2; // 赋值：用st2的副本替换st1的内容；此时均为空字符串
    cout << "赋值后：" << endl;
    cout << "st1 = " << st1 << " " << "长度为：" << st1.size() << endl;
    cout << "st2 = " << st2 << " " << "长度为：" << st2.size() << endl;

    // 两个string对象相加
    string s1 = "hello", s2 = "world";
    string s3 = s1 + ", " + s2 + '\n';
    cout << "s1 = " << s1 << endl;
    cout << "s2 = " << s2 << endl;
    cout << "s3 = s1 + ', '+ s2 = " << s3;

    return 0;
}
