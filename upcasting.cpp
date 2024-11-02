#include <iostream>
using namespace std;

class A{
public:
    int i;
public:
    A():i(10){}
};

class B: public A{
private:
    int j;
public:
    B():j(30){}
    void f(){cout<<"B.j= "<<j<<endl;} // B.j= 50
};

int main(){
    A a;
    B b;
    cout<<a.i<<" "<<b.i<<endl; // 10 10
    cout<<sizeof(a)<< " "<<sizeof(b)<<endl; // 4 8
    int *p=(int *)&a;
    cout <<p<<" "<< *p <<endl; // 0x16cff31d8 10
    *p=20;
    cout << a.i<<endl; // 20
    p=(int *)&b;
    cout<<p << " "<<*p<<endl; // 0x16cff31d4 10
    p++;
    *p=50;
    b.f();
    return 0;
}