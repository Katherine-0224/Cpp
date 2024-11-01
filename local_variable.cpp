#include<iostream>
using namespace std;

class A{
public:
	int i;
	void f();
};

struct B{
	int i;
};

void A::f(){
	cout << i << endl; // 10
	i=20; // 等同于 this->i=20;
	cout<< i << endl; // 20
	cout << &i << endl; // a.&i == 0x16dcbb24c
						// aa.&i == 0x16dcbb248
	cout << this << endl; // a.&i == 0x16dcbb24c
						  // aa.&i == 0x16dcbb248
}

void f(struct B* p){
	p->i =20;
	cout << p->i << endl; // 20
}

int main(){
	A a;
	A aa;
	B b;
	a.i = 10;
	cout<< a.i << endl; // 10
	a.f();
	cout << a.i << endl; // 20
	cout << &a << endl; // 0x16f6d324c
	aa.f();
	f(&b);

}
