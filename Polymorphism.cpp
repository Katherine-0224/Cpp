#include <iostream>
using namespace std;
class A{
public:
    A():i(10){}
    // virtual void f(){cout << "A::f()" << i << endl;} // A::f()10
    virtual void f(){cout << "A::f()" << endl;} 
    int i;
};

class B: public A{
public:
    B():j(20){}
    virtual void f(){cout << "B::f()" << endl;} 
    int j;
};

// double& subscript(const int i){
//     int a;
//     return a;
// }

int main(){
    // A a, b;
    // a.f();
    // cout << sizeof(a) << endl; // 16

    // int *p = (int *)&a;
    // int *q = (int *)&b;
    // cout << *p << endl; // 13779192
    // cout << *q << endl;
    // // p++;
    // // cout << *p << endl; // 1
    // int *x = (int*)p;
    // cout << x << endl;

    A a;
    B b;
    A* p =&b;
    p -> f(); // B::f()
    a=b; // 赋值不会改变两个对象各自的vtable
    a.f(); // A::f()
    p=&a;
    p -> f(); // A::f()

    // 修改vtable
    A *q=&a;
    int* r=(int*)&a;
    int*t =(int*)&b;
    *r=*t;
    q->f(); // B::f()
    return 0;
}

