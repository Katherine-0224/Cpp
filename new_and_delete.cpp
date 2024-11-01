#include<iostream>
using namespace std;

class A{
private:
	int i;
public:
	A(){
		i=0;
		cout << "A::A()" << endl;
	}
	~A(){
		cout << "A::~A(), i= " <<i<< endl;
	}
	void set(int i){
		// i = i; 根据就近原则，这里的两个i都是参数i
		this -> i =i;
	}
	void f(){
		cout << "hello" << endl;;
	}
};

int main(){
	A* p=new A[10];
	for(int i=0;i<10;i++){
		p[i].set(i);
	}
	// A::A()
	// A::A()
	// A::A()
	// A::A()
	// A::A()
	// A::A()
	// A::A()
	// A::A()
	// A::A()
	// A::A()
	// A::~A(), i= 9
	// A::~A(), i= 8
	// A::~A(), i= 7
	// A::~A(), i= 6
	// A::~A(), i= 5
	// A::~A(), i= 4
	// A::~A(), i= 3
	// A::~A(), i= 2
	// A::~A(), i= 1
	// A::~A(), i= 0
	delete[] p;
	return 0;
}
