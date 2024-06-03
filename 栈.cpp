#define MAX_SIZE 100 // ջ���������//
#include <iostream>
#include <vector>
#include <stdexcept> // �����׳��쳣

template <typename T>
class Stack {
private:
    std::vector<T> elems; // ʹ��vector���洢ջԪ��

public:
    void push(const T& elem); // ��ջ
    void pop();               // ��ջ
    T top() const;            // ����ջ��Ԫ��
    bool empty() const { return elems.empty(); } // ���ջ�Ƿ�Ϊ��
};

template <typename T>
void Stack<T>::push(const T& elem) {
    elems.push_back(elem); // ��Ԫ����ӵ�������ĩβ
}

template <typename T>
void Stack<T>::pop() {
    if (elems.empty()) {
        throw std::out_of_range("Stack<>::pop(): empty stack"); // ջΪ��ʱ�׳��쳣
    }
    elems.pop_back(); // ɾ�����������һ��Ԫ��
}

template <typename T>
T Stack<T>::top() const {
    if (elems.empty()) {
        throw std::out_of_range("Stack<>::top(): empty stack"); // ջΪ��ʱ�׳��쳣
    }
    return elems.back(); // �������������һ��Ԫ��
}

int main() {
    try {
        Stack<int> intStack;  // int���͵�ջ
        Stack<std::string> stringStack;  // string���͵�ջ

        // ����intջ
        intStack.push(7);
        std::cout << intStack.top() << std::endl;

        // ����stringջ
        stringStack.push("Hello");
        std::cout << stringStack.top() << std::endl;
        stringStack.pop();
        stringStack.pop(); // ������׳��쳣����Ϊջ�Ѿ�Ϊ��
    }
    catch (std::exception const& ex) {
        std::cerr << "Exception: " << ex.what() << std::endl;
        return -1;
    }

    return 0;
}
