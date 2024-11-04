#include<iostream>
using namespace std;

class A {
public:
    A() : i(10) {}
    int i;  // 只有一个 int 类型的成员
};

int main() {
    A a;  // 创建 A 类的对象
    int *p = (int *)&a;  // 将对象 a 的地址转换为 int 指针
    cout << *p << endl;  // 应该输出 10
}