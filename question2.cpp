#include <iostream>
using namespace std;

class A{
public:
    A():i(10){}
    virtual void f(){cout<<"A::f()"<< endl;}
    int i;
};

class B: public A{
public:
    B():j(20){}
    virtual void f(){cout<<"B::f()"<< endl;}
    int j;
};

int main(){
    A a;
    B b;
    A* p=&b;
    p->f();
    p=&a;
    p->f();

    A *q=&a;
    int* r =(int*)&a;
    int* t =(int*)&b;
    *r=*t;
    q->f();
    return 0;
}