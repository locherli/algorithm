#include <iostream>
#include <unordered_map>
#include <string>

int main() {
    // 创建一个空的哈希表
    std::unordered_map<std::string, int> hash_table;

    // 向哈希表中添加数据
    hash_table["apple"] = 1;
    hash_table["banana"] = 2;
    hash_table["cherry"] = 3;

    // 通过键查找值
    int value = hash_table["apple"];
    std::cout << "The value for apple is: " << value << std::endl;

    // 检查一个不存在的键
    if (hash_table.find("orange") == hash_table.end()) {
        std::cout << "The key orange is not found." << std::endl;
    }

    // 遍历哈希表
    for (const auto& pair : hash_table) {
        std::cout << "Key: " << pair.first << ", Value: " << pair.second << std::endl;
    }

    // 修改哈希表中的值
    hash_table["apple"] = 4;

    // 删除一个键值对
    hash_table.erase("banana");

    return 0;
}
