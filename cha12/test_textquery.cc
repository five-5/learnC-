/*
 * @Author: five-5
 * @Description: test text query 
 * @Date: 2019-05-08
 * @LastEditTime: 2019-05-09
 */

#include <fstream>
#include <iostream>

#include "TextQuery.hpp"

void runQueries(std::ifstream &infile);

int main()
{
    std::ifstream infile("book.txt");
    runQueries(infile);
    return 0;
}

void runQueries(std::ifstream &infile)
{
    // infile是一个ifstream, 指向我们要处理的文件
    TextQuery tq(infile);   // 保存文件并建立查询map
    // 与用户交互：提示用户输入要查询的单词，完成查询并打印结果
    while (true) 
    {
        std::cout << "enter word to look for, or q to quit: ";
        std::string s;
        // 若遇到文件尾或者用户输入了'q'时循环终止
        if (!(std::cin >>s) || s == "q") 
        {
            break;
        }
        // 指向查询并打印结果
        print(std::cout, tq.query(s)) << std::endl;
    }
    
}