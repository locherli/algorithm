#include <iostream>
#include <unordered_map>
#include <string>

int main() {
    // ����һ���յĹ�ϣ��
    std::unordered_map<std::string, int> hash_table;

    // ���ϣ�����������
    hash_table["apple"] = 1;
    hash_table["banana"] = 2;
    hash_table["cherry"] = 3;

    // ͨ��������ֵ
    int value = hash_table["apple"];
    std::cout << "The value for apple is: " << value << std::endl;

    // ���һ�������ڵļ�
    if (hash_table.find("orange") == hash_table.end()) {
        std::cout << "The key orange is not found." << std::endl;
    }

    // ������ϣ��
    for (const auto& pair : hash_table) {
        std::cout << "Key: " << pair.first << ", Value: " << pair.second << std::endl;
    }

    // �޸Ĺ�ϣ���е�ֵ
    hash_table["apple"] = 4;

    // ɾ��һ����ֵ��
    hash_table.erase("banana");

    return 0;
}
