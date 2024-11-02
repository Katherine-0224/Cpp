#include <iostream>
using namespace std;

class A{
    int i; // const int i; 则必须初始化
public:
    A():i(0){}
    // 不构成overload
    void f(){cout << "f()" << endl;} // 等同于 void f(A* this){cout << "f()" << endl;}
    void f() const{ cout << "f() const" << endl;} // void f(const A* this) const{ cout << "f() const" << endl;}
};

int main(){
    const A a; // 成员内变量必须初始化且不可变
    a.f(); // f() const
}