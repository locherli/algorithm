#include <iostream>

// ����ڵ�Ķ���
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// �ж������Ƿ���ڻ��ĺ���
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

// ʾ���÷�
int main() {
    // ����һ���л�������
    ListNode node1(1);
    ListNode node2(2);
    ListNode node3(3);
    ListNode node4(4);

    node1.next = &node2;
    node2.next = &node3;
    node3.next = &node4;
    node4.next = &node2; // ������

    // ��������Ƿ��л�
    std::cout << std::boolalpha; // �������ֵΪtrue/false����1/0
    std::cout << has_cycle(&node1) << std::endl; // ���: true

    return 0;
}
