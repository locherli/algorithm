#define MAX_SIZE 100 // 栈的最大容量//
#include <iostream>
#include <vector>
#include <stdexcept> // 用于抛出异常

template <typename T>
class Stack {
private:
    std::vector<T> elems; // 使用vector来存储栈元素

public:
    void push(const T& elem); // 入栈
    void pop();               // 出栈
    T top() const;            // 返回栈顶元素
    bool empty() const { return elems.empty(); } // 检查栈是否为空
};

template <typename T>
void Stack<T>::push(const T& elem) {
    elems.push_back(elem); // 将元素添加到向量的末尾
}

template <typename T>
void Stack<T>::pop() {
    if (elems.empty()) {
        throw std::out_of_range("Stack<>::pop(): empty stack"); // 栈为空时抛出异常
    }
    elems.pop_back(); // 删除向量的最后一个元素
}

template <typename T>
T Stack<T>::top() const {
    if (elems.empty()) {
        throw std::out_of_range("Stack<>::top(): empty stack"); // 栈为空时抛出异常
    }
    return elems.back(); // 返回向量的最后一个元素
}

int main() {
    try {
        Stack<int> intStack;  // int类型的栈
        Stack<std::string> stringStack;  // string类型的栈

        // 操作int栈
        intStack.push(7);
        std::cout << intStack.top() << std::endl;

        // 操作string栈
        stringStack.push("Hello");
        std::cout << stringStack.top() << std::endl;
        stringStack.pop();
        stringStack.pop(); // 这里会抛出异常，因为栈已经为空
    }
    catch (std::exception const& ex) {
        std::cerr << "Exception: " << ex.what() << std::endl;
        return -1;
    }

    return 0;
}
