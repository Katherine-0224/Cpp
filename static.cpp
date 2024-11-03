#include <iostream>
using namespace std;

class A{ // declaration
public:
    // A():i(0){} // 不可以，因为initialization只能对成员非静态变量执行
    A(){i=0;}
    void print(){cout<<i<<endl;}
    void set(int ii){i=ii;}
    // 静态成员函数
    static void say(int ii){cout<<ii<<i<<endl;}
    // static void say(int ii){cout<<this->i<<k<<endl;} // 静态成员函数不能使用非静态变量，也不能使用this
private:
    // static int i; 在这相当于全局变量的声明，有且仅有一个，a改过后该值就会被更新
    static int i; // ld: symbol(s) not found for architecture arm64
    // int i;
    int k;
};

int A::i;
// static int A::i; // 不可以，静态变量只能被自身cpp文件访问，与静态成员变量的定义违背

int main(){
    A a,b;
    a.set(10);
    b.print(); // 10
    // cout << A::i << endl; // 10 (当且仅当i在class A中定义为public)
    a.say(0); // 010
    A::say(0); // 010 (静态变量可以不通过创建默认成员，而是从类定义中直接获取)
    return 0;
}

