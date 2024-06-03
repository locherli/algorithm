#include <iostream>

// 链表节点的定义
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// 判断链表是否存在环的函数
bool has_cycle(ListNode* head) {
    if (head == nullptr || head->next == nullptr) {
        return false;
    }

    ListNode* slow = head;
    ListNode* fast = head->next;

    while (slow != fast) {
        if (fast == nullptr || fast->next == nullptr) {
            return false;
        }
        slow = slow->next;
        fast = fast->next->next;
    }

    return true;
}

// 示例用法
int main() {
    // 创建一个有环的链表
    ListNode node1(1);
    ListNode node2(2);
    ListNode node3(3);
    ListNode node4(4);

    node1.next = &node2;
    node2.next = &node3;
    node3.next = &node4;
    node4.next = &node2; // 创建环

    // 检查链表是否有环
    std::cout << std::boolalpha; // 输出布尔值为true/false而非1/0
    std::cout << has_cycle(&node1) << std::endl; // 输出: true

    return 0;
}
