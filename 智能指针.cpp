#include <iostream>
#include <memory> // 需要包含这个头文件来使用 unique_ptr

// 一个简单的类
class MyClass {
public:
    MyClass() {
        std::cout << "MyClass 构造函数调用" << std::endl;
    }
    ~MyClass() {
        std::cout << "MyClass 析构函数调用" << std::endl;
    }
    void print() {
        std::cout << "Hello from MyClass!" << std::endl;
    }
};

int main() {
    // 使用 unique_ptr 创建一个 MyClass 类的实例
    std::unique_ptr<MyClass> myClassPtr(new MyClass);

    // 访问 MyClass 类的方法
    myClassPtr->print();

    // 不需要显式删除，因为 unique_ptr 会在对象生命周期结束时自动删除
     myClassPtr.reset(); //如果你想提前释放，可以使用这个方法

    return 0;
}
