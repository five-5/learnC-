/*
 * @Author: five-5
 * @Description: cha11 单词文本转换的例子实践
 * @Date: 2019-04-07
 * @LastEditTime: 2019-04-08
 */
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <stdexcept>
#include <map>

std::map<std::string, std::string> BuildMap(std::ifstream &map_file) {
    std::map<std::string, std::string> trans_map;   // 保存转换规则
    std::string key;                                // 要转换的单词
    std::string value;                              // 替换后的内容
    // 读取第一个单词存入key中，行中剩余内容存入value
    while (map_file >> key && getline(map_file, value)) {
        if (value.size() > 1) {                     // 检查是否有转换规则
            trans_map[key] = value.substr(1);       // 跳过前导空格
        } else {
            throw std::runtime_error("no rule for " + key);
        }
    }
    return trans_map;
}

const std::string & Transform(const std::string &s, const std::map<std::string, std::string> &m) {
    // 实际转换工作：
    auto map_it = m.find(s);
    // 如果单词在转换规则map中
    if (map_it != m.cend()) {
        return map_it->second;  // 使用替换短语
    } else {
        return s;
    }
}

void WordTransform(std::ifstream &map_file, std::ifstream &input) {
    auto trans_map = BuildMap(map_file);    // 保存转换规则
    std::string text;                       // 保存输入中的每一行
    while (getline(input, text)) {
        std::istringstream stream(text);    // 读取一行输入
        std::string word;
        bool firstword = true;
        while (stream >> word) {
            if (firstword) {
                firstword = false;
            } else {
                std::cout << " ";           // 在单词间打印一个空格
            }
            // Transform返回它的第一个参数或其转换之后的形式
            std::cout << Transform(word, trans_map); // 打印输出
        }
        std::cout << std::endl;                  // 完成一行的转换
    }
}

int main()
{
    std::ifstream map_file("./map_file.txt");
    std::ifstream input("./input.txt");
    WordTransform(map_file, input);
    return 0;
}