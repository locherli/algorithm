#include <iostream>
#include <memory> // ��Ҫ�������ͷ�ļ���ʹ�� unique_ptr

// һ���򵥵���
class MyClass {
public:
    MyClass() {
        std::cout << "MyClass ���캯������" << std::endl;
    }
    ~MyClass() {
        std::cout << "MyClass ������������" << std::endl;
    }
    void print() {
        std::cout << "Hello from MyClass!" << std::endl;
    }
};

int main() {
    // ʹ�� unique_ptr ����һ�� MyClass ���ʵ��
    std::unique_ptr<MyClass> myClassPtr(new MyClass);

    // ���� MyClass ��ķ���
    myClassPtr->print();

    // ����Ҫ��ʽɾ������Ϊ unique_ptr ���ڶ����������ڽ���ʱ�Զ�ɾ��
     myClassPtr.reset(); //���������ǰ�ͷţ�����ʹ���������

    return 0;
}
