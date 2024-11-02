#include <iostream>
using namespace std;

class A{
public: // (所有任何函数都能调用更改)
    // 匹配32行
    // A(int ii):i(ii){ 
    //     cout<<"A::A()"<<endl;
    // }
    A():i(0){ // initialization
        cout<<"A::A()"<<endl;
    }
    ~A(){
        cout<<"A::~A()"<<endl;
    }
    void print(){
        cout<<"A::f(), i= "<<i<<endl;
    }
// protected:（给子类）
// 注释后在main函数中b.set(10); 则不适用
// 但class B中仍可以调用
    void set(int ii){
        i=ii;
    }
private: // (所有任何函数都不能调用更改)
    int i;
};

// Inheritance
class B : public A{
public:
    // B():A(15){} // 如果A类中没有default构造函数，B b;会要求B类有default构造函数
    void f(){
        set(20);
        // i=30; // 不能直接访问父类的private变量
        print();
    }
};

int main(){
    // case 1:
    // class B : public A{
    // };
    B b; // 父类先构造，后析构
    b.set(10); 
    b.print();
    // A::A()
    // A::f(), i= 10
    // A::~A()

    // case 2:
    // class B : public A{
    // void f(){
    //     set(20);
    //     print();
    //     }   
    // };
    b.f(); // A::f(), i= 20
    return 0;
}